/** ******************************************************************************
 *  (c) 2019-2020 Zondax GmbH
 *  (c) 2016-2017 Ledger
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ******************************************************************************* */
import { P2_VALUES, PREHASH_LEN, SIGRSLEN } from "./consts";
import { ResponseAddress, ResponseSign, TemplateIns } from "./types";

import GenericApp, {
  ConstructorParams,
  errorCodeToString,
  LedgerError,
  PAYLOAD_TYPE,
  processErrorResponse,
  Transport,
} from "@zondax/ledger-js";
import { processGetAddrResponse } from "./helper";

export * from "./types";

export default class TemplateApp extends GenericApp {
  readonly INS!: TemplateIns;
  constructor(transport: Transport) {
    if (transport == null) throw new Error("Transport has not been defined");

    const params: ConstructorParams = {
      cla: 0x80,
      ins: {
        GET_VERSION: 0x00,
        GET_ADDR: 0x01,
        SIGN: 0x02,
      },
      p1Values: {
        ONLY_RETRIEVE: 0x00,
        SHOW_ADDRESS_IN_DEVICE: 0x01,
      },
      acceptedPathLengths: [4, 5, 6],
      chunkSize: 250,
    };
    super(transport, params);
  }

  async getAddressAndPubKey(path: string): Promise<ResponseAddress> {
    const serializedPath = this.serializePath(path);
    return await this.transport
      .send(this.CLA, this.INS.GET_ADDR, this.P1_VALUES.ONLY_RETRIEVE, P2_VALUES.DEFAULT, serializedPath, [
        LedgerError.NoErrors,
      ])
      .then(processGetAddrResponse, processErrorResponse);
  }

  async showAddressAndPubKey(path: string): Promise<ResponseAddress> {
    const serializedPath = this.serializePath(path);

    return await this.transport
      .send(this.CLA, this.INS.GET_ADDR, this.P1_VALUES.SHOW_ADDRESS_IN_DEVICE, P2_VALUES.DEFAULT, serializedPath, [
        LedgerError.NoErrors,
      ])
      .then(processGetAddrResponse, processErrorResponse);
  }

  // #{TODO} --> Create sign methods, this are example ones!
  async signSendChunk(chunkIdx: number, chunkNum: number, chunk: Buffer, txtype: number): Promise<ResponseSign> {
    let payloadType = PAYLOAD_TYPE.ADD;
    if (chunkIdx === 1) {
      payloadType = PAYLOAD_TYPE.INIT;
    }
    if (chunkIdx === chunkNum) {
      payloadType = PAYLOAD_TYPE.LAST;
    }

    return await this.transport
      .send(this.CLA, this.INS.SIGN, payloadType, txtype, chunk, [
        LedgerError.NoErrors,
        LedgerError.DataIsInvalid,
        LedgerError.BadKeyHandle,
        LedgerError.SignVerifyError,
      ])
      .then((response: Buffer) => {
        const errorCodeData = response.subarray(-2);
        const returnCode = errorCodeData[0] * 256 + errorCodeData[1];
        let errorMessage = errorCodeToString(returnCode);

        let preSignHash = Buffer.alloc(0);
        let signatureRS = Buffer.alloc(0);
        let signatureDER = Buffer.alloc(0);

        if (
          returnCode === LedgerError.BadKeyHandle ||
          returnCode === LedgerError.DataIsInvalid ||
          returnCode === LedgerError.SignVerifyError
        ) {
          errorMessage = `${errorMessage} : ${response.subarray(0, response.length - 2).toString("ascii")}`;
        }

        if (returnCode === LedgerError.NoErrors && response.length > 2) {
          preSignHash = response.subarray(0, PREHASH_LEN);
          signatureRS = response.subarray(PREHASH_LEN, PREHASH_LEN + SIGRSLEN);
          signatureDER = response.subarray(PREHASH_LEN + SIGRSLEN + 1, response.length - 2);
          return {
            preSignHash,
            signatureRS,
            signatureDER,
            returnCode,
            errorMessage,
          };
        }

        return {
          returnCode,
          errorMessage,
        };
      }, processErrorResponse);
  }

  async sign(path: string, message: Buffer, txtype: number): Promise<ResponseSign> {
    const chunks = this.prepareChunks(path, message);
    return await this.signSendChunk(1, chunks.length, chunks[0], txtype % 256).then(async (response) => {
      let result: ResponseSign = {
        returnCode: response.returnCode,
        errorMessage: response.errorMessage,
      };

      for (let i = 1; i < chunks.length; i += 1) {
        // eslint-disable-next-line no-await-in-loop
        result = await this.signSendChunk(1 + i, chunks.length, chunks[i], txtype % 256);
        if (result.returnCode !== LedgerError.NoErrors) {
          break;
        }
      }
      return result;
    }, processErrorResponse);
  }
}
