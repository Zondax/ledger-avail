/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
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
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

// Common read functions

parser_error_t _readbool(parser_context_t *c, pd_bool_t *v);
parser_error_t _readu8(parser_context_t *c, pd_u8_t *v);
parser_error_t _readu16(parser_context_t *c, pd_u16_t *v);
parser_error_t _readu32(parser_context_t *c, pd_u32_t *v);
parser_error_t _readu64(parser_context_t *c, pd_u64_t *v);
parser_error_t _readBlockNumber(parser_context_t *c, pd_BlockNumber_t *v);
parser_error_t _readCompactu32(parser_context_t *c, pd_Compactu32_t *v);
parser_error_t _readCompactu64(parser_context_t *c, pd_Compactu64_t *v);
parser_error_t _readCallImpl(parser_context_t *c, pd_Call_t *v, pd_MethodNested_t *m);

parser_error_t _readCompactu128(parser_context_t *c, pd_Compactu128_t *v);
parser_error_t _readData(parser_context_t *c, pd_Data_t *v);
parser_error_t _readH256(parser_context_t *c, pd_H256_t *v);
parser_error_t _readAccountId(parser_context_t *c, pd_AccountId_t *v);
parser_error_t _readBytes(parser_context_t *c, pd_Bytes_t *v);
parser_error_t _readCompactAccountIndex(parser_context_t *c, pd_CompactAccountIndex_t *v);
parser_error_t _readFungibleToken(parser_context_t *c, pd_FungibleToken_t *v);
parser_error_t _readPerbill(parser_context_t *c, pd_Perbill_t *v);
parser_error_t _readTupleDataData(parser_context_t *c, pd_TupleDataData_t *v);
parser_error_t _readu128(parser_context_t *c, pd_u128_t *v);
parser_error_t _readu8_array_20(parser_context_t *c, pd_u8_array_20_t *v);
parser_error_t _readAccountIdLookupOfT(parser_context_t *c, pd_AccountIdLookupOfT_t *v);
parser_error_t _readBalance(parser_context_t *c, pd_Balance_t *v);
parser_error_t _readCall(parser_context_t *c, pd_Call_t *v);
parser_error_t _readCommissionClaimPermissionAccountId(parser_context_t *c, pd_CommissionClaimPermissionAccountId_t *v);
parser_error_t _readCompactPerBill(parser_context_t *c, pd_CompactPerBill_t *v);
parser_error_t _readMessage(parser_context_t *c, pd_Message_t *v);
parser_error_t _readOptionu8_array_20(parser_context_t *c, pd_Optionu8_array_20_t *v);
parser_error_t _readPercent(parser_context_t *c, pd_Percent_t *v);
parser_error_t _readProxyType(parser_context_t *c, pd_ProxyType_t *v);
parser_error_t _readTimepoint(parser_context_t *c, pd_Timepoint_t *v);
parser_error_t _readTuplePerbillAccountId(parser_context_t *c, pd_TuplePerbillAccountId_t *v);
parser_error_t _readVecBytes(parser_context_t *c, pd_VecBytes_t *v);
parser_error_t _readVecTupleDataData(parser_context_t *c, pd_VecTupleDataData_t *v);
parser_error_t _readWeightFee(parser_context_t *c, pd_WeightFee_t *v);
parser_error_t _readWeightMaximumFee(parser_context_t *c, pd_WeightMaximumFee_t *v);
parser_error_t _readschedulePeriodBlockNumber(parser_context_t *c, pd_schedulePeriodBlockNumber_t *v);
parser_error_t _readAddressedMessage(parser_context_t *c, pd_AddressedMessage_t *v);
parser_error_t _readBondExtraBalanceOfT(parser_context_t *c, pd_BondExtraBalanceOfT_t *v);
parser_error_t _readCommissionChangeRateBlockNumber(parser_context_t *c, pd_CommissionChangeRateBlockNumber_t *v);
parser_error_t _readConfigOpAccountId(parser_context_t *c, pd_ConfigOpAccountId_t *v);
parser_error_t _readConfigOpBalanceOfT(parser_context_t *c, pd_ConfigOpBalanceOfT_t *v);
parser_error_t _readConfigOpPerbill(parser_context_t *c, pd_ConfigOpPerbill_t *v);
parser_error_t _readConfigOpPercent(parser_context_t *c, pd_ConfigOpPercent_t *v);
parser_error_t _readDispatchFeeModifier(parser_context_t *c, pd_DispatchFeeModifier_t *v);
parser_error_t _readIdentityInfo(parser_context_t *c, pd_IdentityInfo_t *v);
parser_error_t _readOptionCommissionClaimPermissionAccountId(parser_context_t *c,
                                                             pd_OptionCommissionClaimPermissionAccountId_t *v);
parser_error_t _readOptionTimepoint(parser_context_t *c, pd_OptionTimepoint_t *v);
parser_error_t _readOptionTuplePerbillAccountId(parser_context_t *c, pd_OptionTuplePerbillAccountId_t *v);
parser_error_t _readProposal(parser_context_t *c, pd_Proposal_t *v);
parser_error_t _readRewardDestination(parser_context_t *c, pd_RewardDestination_t *v);
parser_error_t _readValidProof(parser_context_t *c, pd_ValidProof_t *v);
parser_error_t _readValidatorPrefs(parser_context_t *c, pd_ValidatorPrefs_t *v);
parser_error_t _readVecAccountIdLookupOfT(parser_context_t *c, pd_VecAccountIdLookupOfT_t *v);
parser_error_t _readVecCall(parser_context_t *c, pd_VecCall_t *v);
parser_error_t _readWeight(parser_context_t *c, pd_Weight_t *v);
parser_error_t _readAdjustmentDirection(parser_context_t *c, pd_AdjustmentDirection_t *v);
parser_error_t _readAppData(parser_context_t *c, pd_AppData_t *v);
parser_error_t _readAppKey(parser_context_t *c, pd_AppKey_t *v);
parser_error_t _readClaimPermission(parser_context_t *c, pd_ClaimPermission_t *v);
parser_error_t _readConfigOpu32(parser_context_t *c, pd_ConfigOpu32_t *v);
parser_error_t _readEraIndex(parser_context_t *c, pd_EraIndex_t *v);
parser_error_t _readHash(parser_context_t *c, pd_Hash_t *v);
parser_error_t _readKeys(parser_context_t *c, pd_Keys_t *v);
parser_error_t _readMemberCount(parser_context_t *c, pd_MemberCount_t *v);
parser_error_t _readOptionAccountId(parser_context_t *c, pd_OptionAccountId_t *v);
parser_error_t _readOptionProxyType(parser_context_t *c, pd_OptionProxyType_t *v);
parser_error_t _readOptionschedulePeriodBlockNumber(parser_context_t *c, pd_OptionschedulePeriodBlockNumber_t *v);
parser_error_t _readPage(parser_context_t *c, pd_Page_t *v);
parser_error_t _readPoolId(parser_context_t *c, pd_PoolId_t *v);
parser_error_t _readPoolState(parser_context_t *c, pd_PoolState_t *v);
parser_error_t _readVecAccountId(parser_context_t *c, pd_VecAccountId_t *v);
parser_error_t _readVecu32(parser_context_t *c, pd_Vecu32_t *v);
parser_error_t _readVecu8(parser_context_t *c, pd_Vecu8_t *v);
parser_error_t _readschedulePriority(parser_context_t *c, pd_schedulePriority_t *v);

// Common toString functions

parser_error_t _toStringu8(const pd_u8_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu16(const pd_u16_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu32(const pd_u32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu64(const pd_u64_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringbool(const pd_bool_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBlockNumber(const pd_BlockNumber_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringCompactu32(const pd_Compactu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringCompactu64(const pd_Compactu64_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringCompactu128(const pd_Compactu128_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringData(const pd_Data_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringH256(const pd_H256_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringAccountId(const pd_AccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringBytes(const pd_Bytes_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                              uint8_t *pageCount);

parser_error_t _toStringCompactAccountIndex(const pd_CompactAccountIndex_t *v, char *outValue, uint16_t outValueLen,
                                            uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringFungibleToken(const pd_FungibleToken_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                      uint8_t *pageCount);

parser_error_t _toStringPerbill(const pd_Perbill_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringTupleDataData(const pd_TupleDataData_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                      uint8_t *pageCount);

parser_error_t _toStringu128(const pd_u128_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu8_array_20(const pd_u8_array_20_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringAccountIdLookupOfT(const pd_AccountIdLookupOfT_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBalance(const pd_Balance_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringCall(const pd_Call_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCommissionClaimPermissionAccountId(const pd_CommissionClaimPermissionAccountId_t *v, char *outValue,
                                                           uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactPerBill(const pd_CompactPerBill_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                       uint8_t *pageCount);

parser_error_t _toStringMessage(const pd_Message_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringOptionu8_array_20(const pd_Optionu8_array_20_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPercent(const pd_Percent_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringProxyType(const pd_ProxyType_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringTimepoint(const pd_Timepoint_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringTuplePerbillAccountId(const pd_TuplePerbillAccountId_t *v, char *outValue, uint16_t outValueLen,
                                              uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecBytes(const pd_VecBytes_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringVecTupleDataData(const pd_VecTupleDataData_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringWeightFee(const pd_WeightFee_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringWeightMaximumFee(const pd_WeightMaximumFee_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringschedulePeriodBlockNumber(const pd_schedulePeriodBlockNumber_t *v, char *outValue,
                                                  uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringAddressedMessage(const pd_AddressedMessage_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBondExtraBalanceOfT(const pd_BondExtraBalanceOfT_t *v, char *outValue, uint16_t outValueLen,
                                            uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCommissionChangeRateBlockNumber(const pd_CommissionChangeRateBlockNumber_t *v, char *outValue,
                                                        uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringConfigOpAccountId(const pd_ConfigOpAccountId_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringConfigOpBalanceOfT(const pd_ConfigOpBalanceOfT_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringConfigOpPerbill(const pd_ConfigOpPerbill_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                        uint8_t *pageCount);

parser_error_t _toStringConfigOpPercent(const pd_ConfigOpPercent_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                        uint8_t *pageCount);

parser_error_t _toStringDispatchFeeModifier(const pd_DispatchFeeModifier_t *v, char *outValue, uint16_t outValueLen,
                                            uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringIdentityInfo(const pd_IdentityInfo_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringOptionCommissionClaimPermissionAccountId(const pd_OptionCommissionClaimPermissionAccountId_t *v,
                                                                 char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                                                 uint8_t *pageCount);

parser_error_t _toStringOptionTimepoint(const pd_OptionTimepoint_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                        uint8_t *pageCount);

parser_error_t _toStringOptionTuplePerbillAccountId(const pd_OptionTuplePerbillAccountId_t *v, char *outValue,
                                                    uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringProposal(const pd_Proposal_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringRewardDestination(const pd_RewardDestination_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringValidProof(const pd_ValidProof_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringValidatorPrefs(const pd_ValidatorPrefs_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                       uint8_t *pageCount);

parser_error_t _toStringVecAccountIdLookupOfT(const pd_VecAccountIdLookupOfT_t *v, char *outValue, uint16_t outValueLen,
                                              uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecCall(const pd_VecCall_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringWeight(const pd_Weight_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringAdjustmentDirection(const pd_AdjustmentDirection_t *v, char *outValue, uint16_t outValueLen,
                                            uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringAppData(const pd_AppData_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringAppKey(const pd_AppKey_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringClaimPermission(const pd_ClaimPermission_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                        uint8_t *pageCount);

parser_error_t _toStringConfigOpu32(const pd_ConfigOpu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringEraIndex(const pd_EraIndex_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringHash(const pd_Hash_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringKeys(const pd_Keys_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringMemberCount(const pd_MemberCount_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringOptionAccountId(const pd_OptionAccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                        uint8_t *pageCount);

parser_error_t _toStringOptionProxyType(const pd_OptionProxyType_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                        uint8_t *pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber(const pd_OptionschedulePeriodBlockNumber_t *v, char *outValue,
                                                        uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPage(const pd_Page_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPoolId(const pd_PoolId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringPoolState(const pd_PoolState_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringVecAccountId(const pd_VecAccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringVecu32(const pd_Vecu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringVecu8(const pd_Vecu8_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                              uint8_t *pageCount);

parser_error_t _toStringschedulePriority(const pd_schedulePriority_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

#ifdef __cplusplus
}
#endif
