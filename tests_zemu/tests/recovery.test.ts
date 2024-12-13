/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
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

import Zemu, { ButtonKind, DEFAULT_START_OPTIONS, isTouchDevice } from '@zondax/zemu'
import { newSubstrateApp, PolkadotGenericApp } from '@zondax/ledger-substrate'
import { APP_SEED, models } from './common'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

export const PATH = "m/44'/354'/0'/0'/0'"
export const DOT_SS58_PREFIX = 0

const expected_address_recovery = '5HAeMNeM1XzB9ab742XyV8rM4u1wsAUiQQod61n9cjMTrKbn'
const expected_pk_recovery = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'

jest.setTimeout(180000)

describe('Standard', function () {
  test.concurrent.each(models)('can start and stop container', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('get address recovery', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

      const resp = await app.getAddress(PATH, DOT_SS58_PREFIX)
      console.log(resp)

      expect(resp.address).toEqual(expected_address_recovery)
      expect(resp.pubKey).toEqual(expected_pk_recovery)
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('show address recovery', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({
        ...defaultOptions,
        model: m.name,
        approveKeyword: isTouchDevice(m.name) ? 'Confirm' : '',
        approveAction: ButtonKind.ApproveTapButton,
      })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

      const respRequest = app.getAddress(PATH, DOT_SS58_PREFIX, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-recovery_show_address`)

      const resp = await respRequest

      console.log(resp)

      expect(resp.address).toEqual(expected_address_recovery)
      expect(resp.pubKey).toEqual(expected_pk_recovery)
    } finally {
      await sim.close()
    }
  })

  test.only.each(models)('show address recovery - reject', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({
        ...defaultOptions,
        model: m.name,
        approveKeyword: isTouchDevice(m.name) ? 'Confirm' : '',
      })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

      const respRequest = app.getAddress(PATH, DOT_SS58_PREFIX, true)
      expect(respRequest).rejects.toMatchObject({
        returnCode: 0x6986,
        errorMessage: 'Transaction rejected'
      })
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndReject('.', `${m.prefix.toLowerCase()}-recovery_show_address_reject`)

    } finally {
      await sim.close()
    }
  })
})
