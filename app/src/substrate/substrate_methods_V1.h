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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_UTILITY_V1 1
#define PD_CALL_BALANCES_V1 6
#define PD_CALL_STAKING_V1 10
#define PD_CALL_SESSION_V1 11
#define PD_CALL_DATAAVAILABILITY_V1 29
#define PD_CALL_MULTISIG_V1 34
#define PD_CALL_NOMINATIONPOOLS_V1 36
#define PD_CALL_VECTOR_V1 39

#define PD_CALL_UTILITY_BATCH_V1 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V1_t;

#define PD_CALL_UTILITY_BATCH_ALL_V1 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V1_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V1 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_SYSTEM_AUTHORIZE_UPGRADE_V1 9
typedef struct {
    pd_Hash_t code_hash;
} pd_system_authorize_upgrade_V1_t;

#define PD_CALL_SYSTEM_AUTHORIZE_UPGRADE_WITHOUT_CHECKS_V1 10
typedef struct {
    pd_Hash_t code_hash;
} pd_system_authorize_upgrade_without_checks_V1_t;

#define PD_CALL_SYSTEM_APPLY_AUTHORIZED_UPGRADE_V1 11
typedef struct {
    pd_Vecu8_t code;
} pd_system_apply_authorized_upgrade_V1_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V1 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V1_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V1 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V1_t;

#define PD_CALL_BALANCES_UPGRADE_ACCOUNTS_V1 6
typedef struct {
    pd_VecAccountId_t who;
} pd_balances_upgrade_accounts_V1_t;

#define PD_CALL_BALANCES_FORCE_SET_BALANCE_V1 8
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
} pd_balances_force_set_balance_V1_t;

#define PD_CALL_BALANCES_FORCE_ADJUST_TOTAL_ISSUANCE_V1 9
typedef struct {
    pd_AdjustmentDirection_t direction;
    pd_CompactBalance_t delta;
} pd_balances_force_adjust_total_issuance_V1_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V1 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V1_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V1 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V1_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V1 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_V1_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V1 12
typedef struct {
} pd_staking_force_no_eras_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V1 13
typedef struct {
} pd_staking_force_new_era_V1_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V1 14
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_V1_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V1 15
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V1 16
typedef struct {
} pd_staking_force_new_era_always_V1_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V1 17
typedef struct {
    pd_EraIndex_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V1_t;

#define PD_CALL_STAKING_REAP_STASH_V1 20
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V1_t;

#define PD_CALL_STAKING_KICK_V1 21
typedef struct {
    pd_VecAccountIdLookupOfT_t who;
} pd_staking_kick_V1_t;

#define PD_CALL_STAKING_SET_STAKING_CONFIGS_V1 22
typedef struct {
    pd_ConfigOpBalanceOfT_t min_nominator_bond;
    pd_ConfigOpBalanceOfT_t min_validator_bond;
    pd_ConfigOpu32_t max_nominator_count;
    pd_ConfigOpu32_t max_validator_count;
    pd_ConfigOpPercent_t chill_threshold;
    pd_ConfigOpPerbill_t min_commission;
} pd_staking_set_staking_configs_V1_t;

#define PD_CALL_STAKING_CHILL_OTHER_V1 23
typedef struct {
    pd_AccountId_t stash;
} pd_staking_chill_other_V1_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V1 24
typedef struct {
    pd_AccountId_t validator_stash;
} pd_staking_force_apply_min_commission_V1_t;

#define PD_CALL_STAKING_SET_MIN_COMMISSION_V1 25
typedef struct {
    pd_Perbill_t new_;
} pd_staking_set_min_commission_V1_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_BY_PAGE_V1 26
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
    pd_Page_t page;
} pd_staking_payout_stakers_by_page_V1_t;

#define PD_CALL_STAKING_UPDATE_PAYEE_V1 27
typedef struct {
    pd_AccountId_t controller;
} pd_staking_update_payee_V1_t;

#define PD_CALL_DATAAVAILABILITY_CREATE_APPLICATION_KEY_V1 0
typedef struct {
    pd_AppKey_t key;
} pd_dataavailability_create_application_key_V1_t;

#define PD_CALL_DATAAVAILABILITY_SUBMIT_DATA_V1 1
typedef struct {
    pd_AppData_t data;
} pd_dataavailability_submit_data_V1_t;

#define PD_CALL_DATAAVAILABILITY_SUBMIT_BLOCK_LENGTH_PROPOSAL_V1 2
typedef struct {
    pd_u32_t rows;
    pd_u32_t cols;
} pd_dataavailability_submit_block_length_proposal_V1_t;

#define PD_CALL_DATAAVAILABILITY_SET_APPLICATION_KEY_V1 3
typedef struct {
    pd_AppKey_t old_key;
    pd_AppKey_t new_key;
} pd_dataavailability_set_application_key_V1_t;

#define PD_CALL_DATAAVAILABILITY_SET_SUBMIT_DATA_FEE_MODIFIER_V1 4
typedef struct {
    pd_DispatchFeeModifier_t modifier;
} pd_dataavailability_set_submit_data_fee_modifier_V1_t;

#define PD_CALL_NOMINATIONPOOLS_POOL_WITHDRAW_UNBONDED_V1 4
typedef struct {
    pd_PoolId_t pool_id;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_pool_withdraw_unbonded_V1_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_WITH_POOL_ID_V1 7
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t root;
    pd_AccountIdLookupOfT_t nominator;
    pd_AccountIdLookupOfT_t bouncer;
    pd_PoolId_t pool_id;
} pd_nominationpools_create_with_pool_id_V1_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CONFIGS_V1 11
typedef struct {
    pd_ConfigOpBalanceOfT_t min_join_bond;
    pd_ConfigOpBalanceOfT_t min_create_bond;
    pd_ConfigOpu32_t max_pools;
    pd_ConfigOpu32_t max_members;
    pd_ConfigOpu32_t max_members_per_pool;
    pd_ConfigOpPerbill_t global_max_commission;
} pd_nominationpools_set_configs_V1_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_OTHER_V1 14
typedef struct {
    pd_AccountIdLookupOfT_t member;
    pd_BondExtraBalanceOfT_t extra;
} pd_nominationpools_bond_extra_other_V1_t;

#define PD_CALL_NOMINATIONPOOLS_ADJUST_POOL_DEPOSIT_V1 21
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_adjust_pool_deposit_V1_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_CLAIM_PERMISSION_V1 22
typedef struct {
    pd_PoolId_t pool_id;
    pd_OptionCommissionClaimPermissionAccountId_t permission;
} pd_nominationpools_set_commission_claim_permission_V1_t;

#define PD_CALL_VECTOR_EXECUTE_V1 1
typedef struct {
    pd_Compactu64_t slot;
    pd_AddressedMessage_t addr_message;
    pd_ValidProof_t account_proof;
    pd_ValidProof_t storage_proof;
} pd_vector_execute_V1_t;

#define PD_CALL_VECTOR_SEND_MESSAGE_V1 3
typedef struct {
    pd_Message_t message;
    pd_H256_t to;
    pd_Compactu32_t domain;
} pd_vector_send_message_V1_t;

#endif

typedef union {
    pd_utility_batch_V1_t utility_batch_V1;
    pd_utility_batch_all_V1_t utility_batch_all_V1;
    pd_utility_force_batch_V1_t utility_force_batch_V1;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_authorize_upgrade_V1_t system_authorize_upgrade_V1;
    pd_system_authorize_upgrade_without_checks_V1_t system_authorize_upgrade_without_checks_V1;
    pd_system_apply_authorized_upgrade_V1_t system_apply_authorized_upgrade_V1;
    pd_utility_with_weight_V1_t utility_with_weight_V1;
    pd_balances_force_unreserve_V1_t balances_force_unreserve_V1;
    pd_balances_upgrade_accounts_V1_t balances_upgrade_accounts_V1;
    pd_balances_force_set_balance_V1_t balances_force_set_balance_V1;
    pd_balances_force_adjust_total_issuance_V1_t balances_force_adjust_total_issuance_V1;
    pd_staking_set_validator_count_V1_t staking_set_validator_count_V1;
    pd_staking_increase_validator_count_V1_t staking_increase_validator_count_V1;
    pd_staking_scale_validator_count_V1_t staking_scale_validator_count_V1;
    pd_staking_force_no_eras_V1_t staking_force_no_eras_V1;
    pd_staking_force_new_era_V1_t staking_force_new_era_V1;
    pd_staking_set_invulnerables_V1_t staking_set_invulnerables_V1;
    pd_staking_force_unstake_V1_t staking_force_unstake_V1;
    pd_staking_force_new_era_always_V1_t staking_force_new_era_always_V1;
    pd_staking_cancel_deferred_slash_V1_t staking_cancel_deferred_slash_V1;
    pd_staking_reap_stash_V1_t staking_reap_stash_V1;
    pd_staking_kick_V1_t staking_kick_V1;
    pd_staking_set_staking_configs_V1_t staking_set_staking_configs_V1;
    pd_staking_chill_other_V1_t staking_chill_other_V1;
    pd_staking_force_apply_min_commission_V1_t staking_force_apply_min_commission_V1;
    pd_staking_set_min_commission_V1_t staking_set_min_commission_V1;
    pd_staking_payout_stakers_by_page_V1_t staking_payout_stakers_by_page_V1;
    pd_staking_update_payee_V1_t staking_update_payee_V1;
    pd_dataavailability_create_application_key_V1_t dataavailability_create_application_key_V1;
    pd_dataavailability_submit_data_V1_t dataavailability_submit_data_V1;
    pd_dataavailability_submit_block_length_proposal_V1_t dataavailability_submit_block_length_proposal_V1;
    pd_dataavailability_set_application_key_V1_t dataavailability_set_application_key_V1;
    pd_dataavailability_set_submit_data_fee_modifier_V1_t dataavailability_set_submit_data_fee_modifier_V1;
    pd_nominationpools_pool_withdraw_unbonded_V1_t nominationpools_pool_withdraw_unbonded_V1;
    pd_nominationpools_create_with_pool_id_V1_t nominationpools_create_with_pool_id_V1;
    pd_nominationpools_set_configs_V1_t nominationpools_set_configs_V1;
    pd_nominationpools_bond_extra_other_V1_t nominationpools_bond_extra_other_V1;
    pd_nominationpools_adjust_pool_deposit_V1_t nominationpools_adjust_pool_deposit_V1;
    pd_nominationpools_set_commission_claim_permission_V1_t nominationpools_set_commission_claim_permission_V1;
    pd_vector_execute_V1_t vector_execute_V1;
    pd_vector_send_message_V1_t vector_send_message_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_ALLOW_DEATH_V1 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V1_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V1 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V1_t;

#define PD_CALL_STAKING_BOND_V1 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_RewardDestination_t payee;
} pd_staking_bond_V1_t;

#define PD_CALL_STAKING_BOND_EXTRA_V1 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V1_t;

#define PD_CALL_STAKING_UNBOND_V1 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V1_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V1 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V1_t;

#define PD_CALL_STAKING_VALIDATE_V1 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_V1_t;

#define PD_CALL_STAKING_NOMINATE_V1 5
typedef struct {
    pd_VecAccountIdLookupOfT_t targets;
} pd_staking_nominate_V1_t;

#define PD_CALL_STAKING_CHILL_V1 6
typedef struct {
} pd_staking_chill_V1_t;

#define PD_CALL_STAKING_SET_PAYEE_V1 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_V1_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V1 8
typedef struct {
} pd_staking_set_controller_V1_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V1 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_V1_t;

#define PD_CALL_STAKING_REBOND_V1 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V1 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V1_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V1 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_V1 2
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V1 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V1_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V1 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V1 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_V1 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V1 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V1_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V1 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V1_t;

#define PD_CALL_NOMINATIONPOOLS_JOIN_V1 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_PoolId_t pool_id;
} pd_nominationpools_join_V1_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_V1 1
typedef struct {
    pd_BondExtraBalanceOfT_t extra;
} pd_nominationpools_bond_extra_V1_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_V1 2
typedef struct {
} pd_nominationpools_claim_payout_V1_t;

#define PD_CALL_NOMINATIONPOOLS_UNBOND_V1 3
typedef struct {
    pd_AccountIdLookupOfT_t member_account;
    pd_CompactBalance_t unbonding_points;
} pd_nominationpools_unbond_V1_t;

#define PD_CALL_NOMINATIONPOOLS_WITHDRAW_UNBONDED_V1 5
typedef struct {
    pd_AccountIdLookupOfT_t member_account;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_withdraw_unbonded_V1_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_V1 6
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t root;
    pd_AccountIdLookupOfT_t nominator;
    pd_AccountIdLookupOfT_t bouncer;
} pd_nominationpools_create_V1_t;

#define PD_CALL_NOMINATIONPOOLS_NOMINATE_V1 8
typedef struct {
    pd_PoolId_t pool_id;
    pd_VecAccountId_t validators;
} pd_nominationpools_nominate_V1_t;

#define PD_CALL_NOMINATIONPOOLS_SET_STATE_V1 9
typedef struct {
    pd_PoolId_t pool_id;
    pd_PoolState_t state;
} pd_nominationpools_set_state_V1_t;

#define PD_CALL_NOMINATIONPOOLS_SET_METADATA_V1 10
typedef struct {
    pd_PoolId_t pool_id;
    pd_Vecu8_t metadata;
} pd_nominationpools_set_metadata_V1_t;

#define PD_CALL_NOMINATIONPOOLS_UPDATE_ROLES_V1 12
typedef struct {
    pd_PoolId_t pool_id;
    pd_ConfigOpAccountId_t new_root;
    pd_ConfigOpAccountId_t new_nominator;
    pd_ConfigOpAccountId_t new_bouncer;
} pd_nominationpools_update_roles_V1_t;

#define PD_CALL_NOMINATIONPOOLS_CHILL_V1 13
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_chill_V1_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CLAIM_PERMISSION_V1 15
typedef struct {
    pd_ClaimPermission_t permission;
} pd_nominationpools_set_claim_permission_V1_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_OTHER_V1 16
typedef struct {
    pd_AccountId_t other;
} pd_nominationpools_claim_payout_other_V1_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_V1 17
typedef struct {
    pd_PoolId_t pool_id;
    pd_OptionTuplePerbillAccountId_t new_commission;
} pd_nominationpools_set_commission_V1_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_MAX_V1 18
typedef struct {
    pd_PoolId_t pool_id;
    pd_Perbill_t max_commission;
} pd_nominationpools_set_commission_max_V1_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_CHANGE_RATE_V1 19
typedef struct {
    pd_PoolId_t pool_id;
    pd_CommissionChangeRateBlockNumber_t change_rate;
} pd_nominationpools_set_commission_change_rate_V1_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_COMMISSION_V1 20
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_claim_commission_V1_t;

#endif

typedef union {
    pd_balances_transfer_allow_death_V1_t balances_transfer_allow_death_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
    pd_balances_transfer_all_V1_t balances_transfer_all_V1;
    pd_staking_bond_V1_t staking_bond_V1;
    pd_staking_bond_extra_V1_t staking_bond_extra_V1;
    pd_staking_unbond_V1_t staking_unbond_V1;
    pd_staking_withdraw_unbonded_V1_t staking_withdraw_unbonded_V1;
    pd_staking_validate_V1_t staking_validate_V1;
    pd_staking_nominate_V1_t staking_nominate_V1;
    pd_staking_chill_V1_t staking_chill_V1;
    pd_staking_set_payee_V1_t staking_set_payee_V1;
    pd_staking_set_controller_V1_t staking_set_controller_V1;
    pd_staking_payout_stakers_V1_t staking_payout_stakers_V1;
    pd_staking_rebond_V1_t staking_rebond_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_system_remark_with_event_V1_t system_remark_with_event_V1;
    pd_multisig_as_multi_threshold_1_V1_t multisig_as_multi_threshold_1_V1;
    pd_multisig_as_multi_V1_t multisig_as_multi_V1;
    pd_multisig_approve_as_multi_V1_t multisig_approve_as_multi_V1;
    pd_multisig_cancel_as_multi_V1_t multisig_cancel_as_multi_V1;
    pd_nominationpools_join_V1_t nominationpools_join_V1;
    pd_nominationpools_bond_extra_V1_t nominationpools_bond_extra_V1;
    pd_nominationpools_claim_payout_V1_t nominationpools_claim_payout_V1;
    pd_nominationpools_unbond_V1_t nominationpools_unbond_V1;
    pd_nominationpools_withdraw_unbonded_V1_t nominationpools_withdraw_unbonded_V1;
    pd_nominationpools_create_V1_t nominationpools_create_V1;
    pd_nominationpools_nominate_V1_t nominationpools_nominate_V1;
    pd_nominationpools_set_state_V1_t nominationpools_set_state_V1;
    pd_nominationpools_set_metadata_V1_t nominationpools_set_metadata_V1;
    pd_nominationpools_update_roles_V1_t nominationpools_update_roles_V1;
    pd_nominationpools_chill_V1_t nominationpools_chill_V1;
    pd_nominationpools_set_claim_permission_V1_t nominationpools_set_claim_permission_V1;
    pd_nominationpools_claim_payout_other_V1_t nominationpools_claim_payout_other_V1;
    pd_nominationpools_set_commission_V1_t nominationpools_set_commission_V1;
    pd_nominationpools_set_commission_max_V1_t nominationpools_set_commission_max_V1;
    pd_nominationpools_set_commission_change_rate_V1_t nominationpools_set_commission_change_rate_V1;
    pd_nominationpools_claim_commission_V1_t nominationpools_claim_commission_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
