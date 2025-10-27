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

#include "substrate_dispatch_V1.h"

#include <stdint.h>

#include "substrate_strings.h"
#include "zxmacros.h"
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_utility_batch_V1(parser_context_t *c, pd_utility_batch_V1_t *m) {
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V1(parser_context_t *c, pd_utility_batch_all_V1_t *m) {
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V1(parser_context_t *c, pd_utility_force_batch_V1_t *m) {
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V1(parser_context_t *c,
                                                                       pd_balances_transfer_allow_death_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V1(parser_context_t *c, pd_balances_force_transfer_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V1(parser_context_t *c,
                                                                      pd_balances_transfer_keep_alive_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V1(parser_context_t *c, pd_balances_transfer_all_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V1(parser_context_t *c, pd_staking_bond_V1_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V1(parser_context_t *c, pd_staking_bond_extra_V1_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V1(parser_context_t *c, pd_staking_unbond_V1_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V1(parser_context_t *c,
                                                                   pd_staking_withdraw_unbonded_V1_t *m) {
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V1(parser_context_t *c, pd_staking_validate_V1_t *m) {
    CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V1(parser_context_t *c, pd_staking_nominate_V1_t *m) {
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V1(parser_context_t *c, pd_staking_chill_V1_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V1(parser_context_t *c, pd_staking_set_payee_V1_t *m) {
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V1(parser_context_t *c, pd_staking_set_controller_V1_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V1(parser_context_t *c, pd_staking_payout_stakers_V1_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V1(parser_context_t *c, pd_staking_rebond_V1_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V1(parser_context_t *c, pd_session_set_keys_V1_t *m) {
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V1(parser_context_t *c, pd_session_purge_keys_V1_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V1(parser_context_t *c, pd_system_remark_V1_t *m) {
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V1(parser_context_t *c, pd_system_set_heap_pages_V1_t *m) {
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V1(parser_context_t *c, pd_system_set_code_V1_t *m) {
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V1(parser_context_t *c,
                                                                        pd_system_set_code_without_checks_V1_t *m) {
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V1(parser_context_t *c, pd_system_remark_with_event_V1_t *m) {
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_authorize_upgrade_V1(parser_context_t *c, pd_system_authorize_upgrade_V1_t *m) {
    CHECK_ERROR(_readHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_authorize_upgrade_without_checks_V1(
    parser_context_t *c, pd_system_authorize_upgrade_without_checks_V1_t *m) {
    CHECK_ERROR(_readHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_apply_authorized_upgrade_V1(parser_context_t *c,
                                                                         pd_system_apply_authorized_upgrade_V1_t *m) {
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V1(parser_context_t *c, pd_utility_with_weight_V1_t *m) {
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V1(parser_context_t *c, pd_balances_force_unreserve_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V1(parser_context_t *c,
                                                                   pd_balances_upgrade_accounts_V1_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V1(parser_context_t *c,
                                                                    pd_balances_force_set_balance_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_balances_force_adjust_total_issuance_V1(parser_context_t *c, pd_balances_force_adjust_total_issuance_V1_t *m) {
    CHECK_ERROR(_readAdjustmentDirection(c, &m->direction))
    CHECK_ERROR(_readCompactBalance(c, &m->delta))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V1(parser_context_t *c,
                                                                     pd_staking_set_validator_count_V1_t *m) {
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V1(parser_context_t *c,
                                                                          pd_staking_increase_validator_count_V1_t *m) {
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V1(parser_context_t *c,
                                                                       pd_staking_scale_validator_count_V1_t *m) {
    CHECK_ERROR(_readPercent(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V1(parser_context_t *c, pd_staking_force_no_eras_V1_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V1(parser_context_t *c, pd_staking_force_new_era_V1_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V1(parser_context_t *c,
                                                                   pd_staking_set_invulnerables_V1_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V1(parser_context_t *c, pd_staking_force_unstake_V1_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V1(parser_context_t *c,
                                                                      pd_staking_force_new_era_always_V1_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V1(parser_context_t *c,
                                                                       pd_staking_cancel_deferred_slash_V1_t *m) {
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V1(parser_context_t *c, pd_staking_reap_stash_V1_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V1(parser_context_t *c, pd_staking_kick_V1_t *m) {
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_configs_V1(parser_context_t *c,
                                                                     pd_staking_set_staking_configs_V1_t *m) {
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_nominator_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_validator_bond))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_nominator_count))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_validator_count))
    CHECK_ERROR(_readConfigOpPercent(c, &m->chill_threshold))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->min_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V1(parser_context_t *c, pd_staking_chill_other_V1_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V1(parser_context_t *c,
                                                                            pd_staking_force_apply_min_commission_V1_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_commission_V1(parser_context_t *c,
                                                                    pd_staking_set_min_commission_V1_t *m) {
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_by_page_V1(parser_context_t *c,
                                                                        pd_staking_payout_stakers_by_page_V1_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readPage(c, &m->page))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_update_payee_V1(parser_context_t *c, pd_staking_update_payee_V1_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V1(parser_context_t *c,
                                                                        pd_technicalcommittee_set_members_V1_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId(c, &m->prime))
    CHECK_ERROR(_readMemberCount(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V1(parser_context_t *c,
                                                                    pd_technicalcommittee_execute_V1_t *m) {
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V1(parser_context_t *c,
                                                                    pd_technicalcommittee_propose_V1_t *m) {
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V1(parser_context_t *c, pd_technicalcommittee_vote_V1_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V1(parser_context_t *c, pd_grandpa_note_stalled_V1_t *m) {
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V1(parser_context_t *c, pd_scheduler_schedule_after_V1_t *m) {
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionschedulePeriodBlockNumber(c, &m->maybe_periodic))
    CHECK_ERROR(_readschedulePriority(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dataavailability_create_application_key_V1(
    parser_context_t *c, pd_dataavailability_create_application_key_V1_t *m) {
    CHECK_ERROR(_readAppKey(c, &m->key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dataavailability_submit_data_V1(parser_context_t *c,
                                                                      pd_dataavailability_submit_data_V1_t *m) {
    CHECK_ERROR(_readAppData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dataavailability_submit_block_length_proposal_V1(
    parser_context_t *c, pd_dataavailability_submit_block_length_proposal_V1_t *m) {
    CHECK_ERROR(_readu32(c, &m->rows))
    CHECK_ERROR(_readu32(c, &m->cols))
    return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_dataavailability_set_application_key_V1(parser_context_t *c, pd_dataavailability_set_application_key_V1_t *m) {
    CHECK_ERROR(_readAppKey(c, &m->old_key))
    CHECK_ERROR(_readAppKey(c, &m->new_key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dataavailability_set_submit_data_fee_modifier_V1(
    parser_context_t *c, pd_dataavailability_set_submit_data_fee_modifier_V1_t *m) {
    CHECK_ERROR(_readDispatchFeeModifier(c, &m->modifier))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V1(parser_context_t *c,
                                                                       pd_multisig_as_multi_threshold_1_V1_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V1(parser_context_t *c, pd_multisig_as_multi_V1_t *m) {
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V1(parser_context_t *c,
                                                                   pd_multisig_approve_as_multi_V1_t *m) {
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V1(parser_context_t *c, pd_multisig_cancel_as_multi_V1_t *m) {
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_join_V1(parser_context_t *c, pd_nominationpools_join_V1_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_bond_extra_V1(parser_context_t *c,
                                                                    pd_nominationpools_bond_extra_V1_t *m) {
    CHECK_ERROR(_readBondExtraBalanceOfT(c, &m->extra))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_claim_payout_V1(parser_context_t *c,
                                                                      pd_nominationpools_claim_payout_V1_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_unbond_V1(parser_context_t *c, pd_nominationpools_unbond_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account))
    CHECK_ERROR(_readCompactBalance(c, &m->unbonding_points))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_pool_withdraw_unbonded_V1(
    parser_context_t *c, pd_nominationpools_pool_withdraw_unbonded_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_withdraw_unbonded_V1(parser_context_t *c,
                                                                           pd_nominationpools_withdraw_unbonded_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_create_V1(parser_context_t *c, pd_nominationpools_create_V1_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->root))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->nominator))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->bouncer))
    return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_nominationpools_create_with_pool_id_V1(parser_context_t *c, pd_nominationpools_create_with_pool_id_V1_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->root))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->nominator))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->bouncer))
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_nominate_V1(parser_context_t *c, pd_nominationpools_nominate_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readVecAccountId(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_state_V1(parser_context_t *c,
                                                                   pd_nominationpools_set_state_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readPoolState(c, &m->state))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_metadata_V1(parser_context_t *c,
                                                                      pd_nominationpools_set_metadata_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readVecu8(c, &m->metadata))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_configs_V1(parser_context_t *c,
                                                                     pd_nominationpools_set_configs_V1_t *m) {
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_join_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_create_bond))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_pools))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_members))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_members_per_pool))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->global_max_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_update_roles_V1(parser_context_t *c,
                                                                      pd_nominationpools_update_roles_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readConfigOpAccountId(c, &m->new_root))
    CHECK_ERROR(_readConfigOpAccountId(c, &m->new_nominator))
    CHECK_ERROR(_readConfigOpAccountId(c, &m->new_bouncer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_chill_V1(parser_context_t *c, pd_nominationpools_chill_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_bond_extra_other_V1(parser_context_t *c,
                                                                          pd_nominationpools_bond_extra_other_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member))
    CHECK_ERROR(_readBondExtraBalanceOfT(c, &m->extra))
    return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_nominationpools_set_claim_permission_V1(parser_context_t *c, pd_nominationpools_set_claim_permission_V1_t *m) {
    CHECK_ERROR(_readClaimPermission(c, &m->permission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_claim_payout_other_V1(parser_context_t *c,
                                                                            pd_nominationpools_claim_payout_other_V1_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->other))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_commission_V1(parser_context_t *c,
                                                                        pd_nominationpools_set_commission_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readOptionTuplePerbillAccountId(c, &m->new_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_commission_max_V1(parser_context_t *c,
                                                                            pd_nominationpools_set_commission_max_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readPerbill(c, &m->max_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_commission_change_rate_V1(
    parser_context_t *c, pd_nominationpools_set_commission_change_rate_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readCommissionChangeRateBlockNumber(c, &m->change_rate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_claim_commission_V1(parser_context_t *c,
                                                                          pd_nominationpools_claim_commission_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_nominationpools_adjust_pool_deposit_V1(parser_context_t *c, pd_nominationpools_adjust_pool_deposit_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_commission_claim_permission_V1(
    parser_context_t *c, pd_nominationpools_set_commission_claim_permission_V1_t *m) {
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readOptionCommissionClaimPermissionAccountId(c, &m->permission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V1(parser_context_t *c, pd_identity_set_identity_V1_t *m) {
    CHECK_ERROR(_readIdentityInfo(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V1(parser_context_t *c, pd_identity_clear_identity_V1_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_mandate_mandate_V1(parser_context_t *c, pd_mandate_mandate_V1_t *m) {
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vector_execute_V1(parser_context_t *c, pd_vector_execute_V1_t *m) {
    CHECK_ERROR(_readCompactu64(c, &m->slot))
    CHECK_ERROR(_readAddressedMessage(c, &m->addr_message))
    CHECK_ERROR(_readValidProof(c, &m->account_proof))
    CHECK_ERROR(_readValidProof(c, &m->storage_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vector_send_message_V1(parser_context_t *c, pd_vector_send_message_V1_t *m) {
    CHECK_ERROR(_readMessage(c, &m->message))
    CHECK_ERROR(_readH256(c, &m->to))
    CHECK_ERROR(_readCompactu32(c, &m->domain))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V1(parser_context_t *c, pd_proxy_proxy_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V1(parser_context_t *c, pd_proxy_add_proxy_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V1(parser_context_t *c, pd_proxy_remove_proxy_V1_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

parser_error_t _readMethod_V1(parser_context_t *c, uint8_t moduleIdx, uint8_t callIdx, pd_Method_V1_t *method) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 256: /* module 1 call 0 */
            CHECK_ERROR(_readMethod_utility_batch_V1(c, &method->basic.utility_batch_V1))
            break;
        case 258: /* module 1 call 2 */
            CHECK_ERROR(_readMethod_utility_batch_all_V1(c, &method->basic.utility_batch_all_V1))
            break;
        case 260: /* module 1 call 4 */
            CHECK_ERROR(_readMethod_utility_force_batch_V1(c, &method->basic.utility_force_batch_V1))
            break;
        case 1536: /* module 6 call 0 */
            CHECK_ERROR(_readMethod_balances_transfer_allow_death_V1(c, &method->nested.balances_transfer_allow_death_V1))
            break;
        case 1538: /* module 6 call 2 */
            CHECK_ERROR(_readMethod_balances_force_transfer_V1(c, &method->nested.balances_force_transfer_V1))
            break;
        case 1539: /* module 6 call 3 */
            CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V1(c, &method->nested.balances_transfer_keep_alive_V1))
            break;
        case 1540: /* module 6 call 4 */
            CHECK_ERROR(_readMethod_balances_transfer_all_V1(c, &method->nested.balances_transfer_all_V1))
            break;
        case 2560: /* module 10 call 0 */
            CHECK_ERROR(_readMethod_staking_bond_V1(c, &method->nested.staking_bond_V1))
            break;
        case 2561: /* module 10 call 1 */
            CHECK_ERROR(_readMethod_staking_bond_extra_V1(c, &method->nested.staking_bond_extra_V1))
            break;
        case 2562: /* module 10 call 2 */
            CHECK_ERROR(_readMethod_staking_unbond_V1(c, &method->nested.staking_unbond_V1))
            break;
        case 2563: /* module 10 call 3 */
            CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V1(c, &method->nested.staking_withdraw_unbonded_V1))
            break;
        case 2564: /* module 10 call 4 */
            CHECK_ERROR(_readMethod_staking_validate_V1(c, &method->nested.staking_validate_V1))
            break;
        case 2565: /* module 10 call 5 */
            CHECK_ERROR(_readMethod_staking_nominate_V1(c, &method->nested.staking_nominate_V1))
            break;
        case 2566: /* module 10 call 6 */
            CHECK_ERROR(_readMethod_staking_chill_V1(c, &method->nested.staking_chill_V1))
            break;
        case 2567: /* module 10 call 7 */
            CHECK_ERROR(_readMethod_staking_set_payee_V1(c, &method->nested.staking_set_payee_V1))
            break;
        case 2568: /* module 10 call 8 */
            CHECK_ERROR(_readMethod_staking_set_controller_V1(c, &method->nested.staking_set_controller_V1))
            break;
        case 2578: /* module 10 call 18 */
            CHECK_ERROR(_readMethod_staking_payout_stakers_V1(c, &method->nested.staking_payout_stakers_V1))
            break;
        case 2579: /* module 10 call 19 */
            CHECK_ERROR(_readMethod_staking_rebond_V1(c, &method->nested.staking_rebond_V1))
            break;
        case 2816: /* module 11 call 0 */
            CHECK_ERROR(_readMethod_session_set_keys_V1(c, &method->nested.session_set_keys_V1))
            break;
        case 2817: /* module 11 call 1 */
            CHECK_ERROR(_readMethod_session_purge_keys_V1(c, &method->nested.session_purge_keys_V1))
            break;

        case 0: /* module 0 call 0 */
            CHECK_ERROR(_readMethod_system_remark_V1(c, &method->nested.system_remark_V1))
            break;
        case 1: /* module 0 call 1 */
            CHECK_ERROR(_readMethod_system_set_heap_pages_V1(c, &method->nested.system_set_heap_pages_V1))
            break;
        case 2: /* module 0 call 2 */
            CHECK_ERROR(_readMethod_system_set_code_V1(c, &method->nested.system_set_code_V1))
            break;
        case 3: /* module 0 call 3 */
            CHECK_ERROR(_readMethod_system_set_code_without_checks_V1(c, &method->nested.system_set_code_without_checks_V1))
            break;
        case 7: /* module 0 call 7 */
            CHECK_ERROR(_readMethod_system_remark_with_event_V1(c, &method->nested.system_remark_with_event_V1))
            break;
        case 9: /* module 0 call 9 */
            CHECK_ERROR(_readMethod_system_authorize_upgrade_V1(c, &method->basic.system_authorize_upgrade_V1))
            break;
        case 10: /* module 0 call 10 */
            CHECK_ERROR(_readMethod_system_authorize_upgrade_without_checks_V1(
                c, &method->basic.system_authorize_upgrade_without_checks_V1))
            break;
        case 11: /* module 0 call 11 */
            CHECK_ERROR(_readMethod_system_apply_authorized_upgrade_V1(c, &method->basic.system_apply_authorized_upgrade_V1))
            break;
        case 261: /* module 1 call 5 */
            CHECK_ERROR(_readMethod_utility_with_weight_V1(c, &method->basic.utility_with_weight_V1))
            break;
        case 1541: /* module 6 call 5 */
            CHECK_ERROR(_readMethod_balances_force_unreserve_V1(c, &method->basic.balances_force_unreserve_V1))
            break;
        case 1542: /* module 6 call 6 */
            CHECK_ERROR(_readMethod_balances_upgrade_accounts_V1(c, &method->basic.balances_upgrade_accounts_V1))
            break;
        case 1544: /* module 6 call 8 */
            CHECK_ERROR(_readMethod_balances_force_set_balance_V1(c, &method->basic.balances_force_set_balance_V1))
            break;
        case 1545: /* module 6 call 9 */
            CHECK_ERROR(_readMethod_balances_force_adjust_total_issuance_V1(
                c, &method->basic.balances_force_adjust_total_issuance_V1))
            break;
        case 2569: /* module 10 call 9 */
            CHECK_ERROR(_readMethod_staking_set_validator_count_V1(c, &method->basic.staking_set_validator_count_V1))
            break;
        case 2570: /* module 10 call 10 */
            CHECK_ERROR(
                _readMethod_staking_increase_validator_count_V1(c, &method->basic.staking_increase_validator_count_V1))
            break;
        case 2571: /* module 10 call 11 */
            CHECK_ERROR(_readMethod_staking_scale_validator_count_V1(c, &method->basic.staking_scale_validator_count_V1))
            break;
        case 2572: /* module 10 call 12 */
            CHECK_ERROR(_readMethod_staking_force_no_eras_V1(c, &method->basic.staking_force_no_eras_V1))
            break;
        case 2573: /* module 10 call 13 */
            CHECK_ERROR(_readMethod_staking_force_new_era_V1(c, &method->basic.staking_force_new_era_V1))
            break;
        case 2574: /* module 10 call 14 */
            CHECK_ERROR(_readMethod_staking_set_invulnerables_V1(c, &method->basic.staking_set_invulnerables_V1))
            break;
        case 2575: /* module 10 call 15 */
            CHECK_ERROR(_readMethod_staking_force_unstake_V1(c, &method->basic.staking_force_unstake_V1))
            break;
        case 2576: /* module 10 call 16 */
            CHECK_ERROR(_readMethod_staking_force_new_era_always_V1(c, &method->basic.staking_force_new_era_always_V1))
            break;
        case 2577: /* module 10 call 17 */
            CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V1(c, &method->basic.staking_cancel_deferred_slash_V1))
            break;
        case 2580: /* module 10 call 20 */
            CHECK_ERROR(_readMethod_staking_reap_stash_V1(c, &method->basic.staking_reap_stash_V1))
            break;
        case 2581: /* module 10 call 21 */
            CHECK_ERROR(_readMethod_staking_kick_V1(c, &method->basic.staking_kick_V1))
            break;
        case 2582: /* module 10 call 22 */
            CHECK_ERROR(_readMethod_staking_set_staking_configs_V1(c, &method->basic.staking_set_staking_configs_V1))
            break;
        case 2583: /* module 10 call 23 */
            CHECK_ERROR(_readMethod_staking_chill_other_V1(c, &method->basic.staking_chill_other_V1))
            break;
        case 2584: /* module 10 call 24 */
            CHECK_ERROR(
                _readMethod_staking_force_apply_min_commission_V1(c, &method->basic.staking_force_apply_min_commission_V1))
            break;
        case 2585: /* module 10 call 25 */
            CHECK_ERROR(_readMethod_staking_set_min_commission_V1(c, &method->basic.staking_set_min_commission_V1))
            break;
        case 2586: /* module 10 call 26 */
            CHECK_ERROR(_readMethod_staking_payout_stakers_by_page_V1(c, &method->basic.staking_payout_stakers_by_page_V1))
            break;
        case 2587: /* module 10 call 27 */
            CHECK_ERROR(_readMethod_staking_update_payee_V1(c, &method->basic.staking_update_payee_V1))
            break;
        case 3584: /* module 14 call 0 */
            CHECK_ERROR(_readMethod_technicalcommittee_set_members_V1(c, &method->basic.technicalcommittee_set_members_V1))
            break;
        case 3585: /* module 14 call 1 */
            CHECK_ERROR(_readMethod_technicalcommittee_execute_V1(c, &method->basic.technicalcommittee_execute_V1))
            break;
        case 3586: /* module 14 call 2 */
            CHECK_ERROR(_readMethod_technicalcommittee_propose_V1(c, &method->basic.technicalcommittee_propose_V1))
            break;
        case 3587: /* module 14 call 3 */
            CHECK_ERROR(_readMethod_technicalcommittee_vote_V1(c, &method->basic.technicalcommittee_vote_V1))
            break;
        case 4354: /* module 17 call 2 */
            CHECK_ERROR(_readMethod_grandpa_note_stalled_V1(c, &method->basic.grandpa_note_stalled_V1))
            break;
        case 6148: /* module 24 call 4 */
            CHECK_ERROR(_readMethod_scheduler_schedule_after_V1(c, &method->basic.scheduler_schedule_after_V1))
            break;
        case 7424: /* module 29 call 0 */
            CHECK_ERROR(_readMethod_dataavailability_create_application_key_V1(
                c, &method->basic.dataavailability_create_application_key_V1))
            break;
        case 7425: /* module 29 call 1 */
            CHECK_ERROR(_readMethod_dataavailability_submit_data_V1(c, &method->basic.dataavailability_submit_data_V1))
            break;
        case 7426: /* module 29 call 2 */
            CHECK_ERROR(_readMethod_dataavailability_submit_block_length_proposal_V1(
                c, &method->basic.dataavailability_submit_block_length_proposal_V1))
            break;
        case 7427: /* module 29 call 3 */
            CHECK_ERROR(_readMethod_dataavailability_set_application_key_V1(
                c, &method->basic.dataavailability_set_application_key_V1))
            break;
        case 7428: /* module 29 call 4 */
            CHECK_ERROR(_readMethod_dataavailability_set_submit_data_fee_modifier_V1(
                c, &method->basic.dataavailability_set_submit_data_fee_modifier_V1))
            break;
        case 8704: /* module 34 call 0 */
            CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V1(c, &method->nested.multisig_as_multi_threshold_1_V1))
            break;
        case 8705: /* module 34 call 1 */
            CHECK_ERROR(_readMethod_multisig_as_multi_V1(c, &method->nested.multisig_as_multi_V1))
            break;
        case 8706: /* module 34 call 2 */
            CHECK_ERROR(_readMethod_multisig_approve_as_multi_V1(c, &method->nested.multisig_approve_as_multi_V1))
            break;
        case 8707: /* module 34 call 3 */
            CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V1(c, &method->nested.multisig_cancel_as_multi_V1))
            break;
        case 9216: /* module 36 call 0 */
            CHECK_ERROR(_readMethod_nominationpools_join_V1(c, &method->nested.nominationpools_join_V1))
            break;
        case 9217: /* module 36 call 1 */
            CHECK_ERROR(_readMethod_nominationpools_bond_extra_V1(c, &method->nested.nominationpools_bond_extra_V1))
            break;
        case 9218: /* module 36 call 2 */
            CHECK_ERROR(_readMethod_nominationpools_claim_payout_V1(c, &method->nested.nominationpools_claim_payout_V1))
            break;
        case 9219: /* module 36 call 3 */
            CHECK_ERROR(_readMethod_nominationpools_unbond_V1(c, &method->nested.nominationpools_unbond_V1))
            break;
        case 9220: /* module 36 call 4 */
            CHECK_ERROR(_readMethod_nominationpools_pool_withdraw_unbonded_V1(
                c, &method->basic.nominationpools_pool_withdraw_unbonded_V1))
            break;
        case 9221: /* module 36 call 5 */
            CHECK_ERROR(
                _readMethod_nominationpools_withdraw_unbonded_V1(c, &method->nested.nominationpools_withdraw_unbonded_V1))
            break;
        case 9222: /* module 36 call 6 */
            CHECK_ERROR(_readMethod_nominationpools_create_V1(c, &method->nested.nominationpools_create_V1))
            break;
        case 9223: /* module 36 call 7 */
            CHECK_ERROR(
                _readMethod_nominationpools_create_with_pool_id_V1(c, &method->basic.nominationpools_create_with_pool_id_V1))
            break;
        case 9224: /* module 36 call 8 */
            CHECK_ERROR(_readMethod_nominationpools_nominate_V1(c, &method->nested.nominationpools_nominate_V1))
            break;
        case 9225: /* module 36 call 9 */
            CHECK_ERROR(_readMethod_nominationpools_set_state_V1(c, &method->nested.nominationpools_set_state_V1))
            break;
        case 9226: /* module 36 call 10 */
            CHECK_ERROR(_readMethod_nominationpools_set_metadata_V1(c, &method->nested.nominationpools_set_metadata_V1))
            break;
        case 9227: /* module 36 call 11 */
            CHECK_ERROR(_readMethod_nominationpools_set_configs_V1(c, &method->basic.nominationpools_set_configs_V1))
            break;
        case 9228: /* module 36 call 12 */
            CHECK_ERROR(_readMethod_nominationpools_update_roles_V1(c, &method->nested.nominationpools_update_roles_V1))
            break;
        case 9229: /* module 36 call 13 */
            CHECK_ERROR(_readMethod_nominationpools_chill_V1(c, &method->nested.nominationpools_chill_V1))
            break;
        case 9230: /* module 36 call 14 */
            CHECK_ERROR(
                _readMethod_nominationpools_bond_extra_other_V1(c, &method->basic.nominationpools_bond_extra_other_V1))
            break;
        case 9231: /* module 36 call 15 */
            CHECK_ERROR(_readMethod_nominationpools_set_claim_permission_V1(
                c, &method->nested.nominationpools_set_claim_permission_V1))
            break;
        case 9232: /* module 36 call 16 */
            CHECK_ERROR(
                _readMethod_nominationpools_claim_payout_other_V1(c, &method->nested.nominationpools_claim_payout_other_V1))
            break;
        case 9233: /* module 36 call 17 */
            CHECK_ERROR(_readMethod_nominationpools_set_commission_V1(c, &method->nested.nominationpools_set_commission_V1))
            break;
        case 9234: /* module 36 call 18 */
            CHECK_ERROR(
                _readMethod_nominationpools_set_commission_max_V1(c, &method->nested.nominationpools_set_commission_max_V1))
            break;
        case 9235: /* module 36 call 19 */
            CHECK_ERROR(_readMethod_nominationpools_set_commission_change_rate_V1(
                c, &method->nested.nominationpools_set_commission_change_rate_V1))
            break;
        case 9236: /* module 36 call 20 */
            CHECK_ERROR(
                _readMethod_nominationpools_claim_commission_V1(c, &method->nested.nominationpools_claim_commission_V1))
            break;
        case 9237: /* module 36 call 21 */
            CHECK_ERROR(
                _readMethod_nominationpools_adjust_pool_deposit_V1(c, &method->basic.nominationpools_adjust_pool_deposit_V1))
            break;
        case 9238: /* module 36 call 22 */
            CHECK_ERROR(_readMethod_nominationpools_set_commission_claim_permission_V1(
                c, &method->basic.nominationpools_set_commission_claim_permission_V1))
            break;
        case 9473: /* module 37 call 1 */
            CHECK_ERROR(_readMethod_identity_set_identity_V1(c, &method->basic.identity_set_identity_V1))
            break;
        case 9475: /* module 37 call 3 */
            CHECK_ERROR(_readMethod_identity_clear_identity_V1(c, &method->basic.identity_clear_identity_V1))
            break;
        case 9728: /* module 38 call 0 */
            CHECK_ERROR(_readMethod_mandate_mandate_V1(c, &method->basic.mandate_mandate_V1))
            break;
        case 9985: /* module 39 call 1 */
            CHECK_ERROR(_readMethod_vector_execute_V1(c, &method->basic.vector_execute_V1))
            break;
        case 9987: /* module 39 call 3 */
            CHECK_ERROR(_readMethod_vector_send_message_V1(c, &method->basic.vector_send_message_V1))
            break;
        case 10240: /* module 40 call 0 */
            CHECK_ERROR(_readMethod_proxy_proxy_V1(c, &method->nested.proxy_proxy_V1))
            break;
        case 10241: /* module 40 call 1 */
            CHECK_ERROR(_readMethod_proxy_add_proxy_V1(c, &method->nested.proxy_add_proxy_V1))
            break;
        case 10242: /* module 40 call 2 */
            CHECK_ERROR(_readMethod_proxy_remove_proxy_V1(c, &method->nested.proxy_remove_proxy_V1))
            break;
        default:
            return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char *_getMethod_ModuleName_V1(uint8_t moduleIdx) {
    switch (moduleIdx) {
        case 1:
            return STR_MO_UTILITY;
        case 6:
            return STR_MO_BALANCES;
        case 10:
            return STR_MO_STAKING;
        case 11:
            return STR_MO_SESSION;
        case 0:
            return STR_MO_SYSTEM;
        case 14:
            return STR_MO_TECHNICALCOMMITTEE;
        case 17:
            return STR_MO_GRANDPA;
        case 24:
            return STR_MO_SCHEDULER;
        case 29:
            return STR_MO_DATAAVAILABILITY;
        case 34:
            return STR_MO_MULTISIG;
        case 36:
            return STR_MO_NOMINATIONPOOLS;
        case 37:
            return STR_MO_IDENTITY;
        case 38:
            return STR_MO_MANDATE;
        case 39:
            return STR_MO_VECTOR;
        case 40:
            return STR_MO_PROXY;
        default:
            return NULL;
    }

    return NULL;
}

const char *_getMethod_Name_V1(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 256: /* module 1 call 0 */
            return STR_ME_BATCH;
        case 258: /* module 1 call 2 */
            return STR_ME_BATCH_ALL;
        case 260: /* module 1 call 4 */
            return STR_ME_FORCE_BATCH;
        case 1536: /* module 6 call 0 */
            return STR_ME_TRANSFER_ALLOW_DEATH;
        case 1538: /* module 6 call 2 */
            return STR_ME_FORCE_TRANSFER;
        case 1539: /* module 6 call 3 */
            return STR_ME_TRANSFER_KEEP_ALIVE;
        case 1540: /* module 6 call 4 */
            return STR_ME_TRANSFER_ALL;
        case 2560: /* module 10 call 0 */
            return STR_ME_BOND;
        case 2561: /* module 10 call 1 */
            return STR_ME_BOND_EXTRA;
        case 2562: /* module 10 call 2 */
            return STR_ME_UNBOND;
        case 2563: /* module 10 call 3 */
            return STR_ME_WITHDRAW_UNBONDED;
        case 2564: /* module 10 call 4 */
            return STR_ME_VALIDATE;
        case 2565: /* module 10 call 5 */
            return STR_ME_NOMINATE;
        case 2566: /* module 10 call 6 */
            return STR_ME_CHILL;
        case 2567: /* module 10 call 7 */
            return STR_ME_SET_PAYEE;
        case 2568: /* module 10 call 8 */
            return STR_ME_SET_CONTROLLER;
        case 2578: /* module 10 call 18 */
            return STR_ME_PAYOUT_STAKERS;
        case 2579: /* module 10 call 19 */
            return STR_ME_REBOND;
        case 2816: /* module 11 call 0 */
            return STR_ME_SET_KEYS;
        case 2817: /* module 11 call 1 */
            return STR_ME_PURGE_KEYS;
        default:
            return _getMethod_Name_V1_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char *_getMethod_Name_V1_ParserFull(uint16_t callPrivIdx) {
    switch (callPrivIdx) {
        case 0: /* module 0 call 0 */
            return STR_ME_REMARK;
        case 1: /* module 0 call 1 */
            return STR_ME_SET_HEAP_PAGES;
        case 2: /* module 0 call 2 */
            return STR_ME_SET_CODE;
        case 3: /* module 0 call 3 */
            return STR_ME_SET_CODE_WITHOUT_CHECKS;
        case 7: /* module 0 call 7 */
            return STR_ME_REMARK_WITH_EVENT;
        case 9: /* module 0 call 9 */
            return STR_ME_AUTHORIZE_UPGRADE;
        case 10: /* module 0 call 10 */
            return STR_ME_AUTHORIZE_UPGRADE_WITHOUT_CHECKS;
        case 11: /* module 0 call 11 */
            return STR_ME_APPLY_AUTHORIZED_UPGRADE;
        case 261: /* module 1 call 5 */
            return STR_ME_WITH_WEIGHT;
        case 1541: /* module 6 call 5 */
            return STR_ME_FORCE_UNRESERVE;
        case 1542: /* module 6 call 6 */
            return STR_ME_UPGRADE_ACCOUNTS;
        case 1544: /* module 6 call 8 */
            return STR_ME_FORCE_SET_BALANCE;
        case 1545: /* module 6 call 9 */
            return STR_ME_FORCE_ADJUST_TOTAL_ISSUANCE;
        case 2569: /* module 10 call 9 */
            return STR_ME_SET_VALIDATOR_COUNT;
        case 2570: /* module 10 call 10 */
            return STR_ME_INCREASE_VALIDATOR_COUNT;
        case 2571: /* module 10 call 11 */
            return STR_ME_SCALE_VALIDATOR_COUNT;
        case 2572: /* module 10 call 12 */
            return STR_ME_FORCE_NO_ERAS;
        case 2573: /* module 10 call 13 */
            return STR_ME_FORCE_NEW_ERA;
        case 2574: /* module 10 call 14 */
            return STR_ME_SET_INVULNERABLES;
        case 2575: /* module 10 call 15 */
            return STR_ME_FORCE_UNSTAKE;
        case 2576: /* module 10 call 16 */
            return STR_ME_FORCE_NEW_ERA_ALWAYS;
        case 2577: /* module 10 call 17 */
            return STR_ME_CANCEL_DEFERRED_SLASH;
        case 2580: /* module 10 call 20 */
            return STR_ME_REAP_STASH;
        case 2581: /* module 10 call 21 */
            return STR_ME_KICK;
        case 2582: /* module 10 call 22 */
            return STR_ME_SET_STAKING_CONFIGS;
        case 2583: /* module 10 call 23 */
            return STR_ME_CHILL_OTHER;
        case 2584: /* module 10 call 24 */
            return STR_ME_FORCE_APPLY_MIN_COMMISSION;
        case 2585: /* module 10 call 25 */
            return STR_ME_SET_MIN_COMMISSION;
        case 2586: /* module 10 call 26 */
            return STR_ME_PAYOUT_STAKERS_BY_PAGE;
        case 2587: /* module 10 call 27 */
            return STR_ME_UPDATE_PAYEE;
        case 3584: /* module 14 call 0 */
            return STR_ME_SET_MEMBERS;
        case 3585: /* module 14 call 1 */
            return STR_ME_EXECUTE;
        case 3586: /* module 14 call 2 */
            return STR_ME_PROPOSE;
        case 3587: /* module 14 call 3 */
            return STR_ME_VOTE;
        case 4354: /* module 17 call 2 */
            return STR_ME_NOTE_STALLED;
        case 6148: /* module 24 call 4 */
            return STR_ME_SCHEDULE_AFTER;
        case 7424: /* module 29 call 0 */
            return STR_ME_CREATE_APPLICATION_KEY;
        case 7425: /* module 29 call 1 */
            return STR_ME_SUBMIT_DATA;
        case 7426: /* module 29 call 2 */
            return STR_ME_SUBMIT_BLOCK_LENGTH_PROPOSAL;
        case 7427: /* module 29 call 3 */
            return STR_ME_SET_APPLICATION_KEY;
        case 7428: /* module 29 call 4 */
            return STR_ME_SET_SUBMIT_DATA_FEE_MODIFIER;
        case 8704: /* module 34 call 0 */
            return STR_ME_AS_MULTI_THRESHOLD_1;
        case 8705: /* module 34 call 1 */
            return STR_ME_AS_MULTI;
        case 8706: /* module 34 call 2 */
            return STR_ME_APPROVE_AS_MULTI;
        case 8707: /* module 34 call 3 */
            return STR_ME_CANCEL_AS_MULTI;
        case 9216: /* module 36 call 0 */
            return STR_ME_JOIN;
        case 9217: /* module 36 call 1 */
            return STR_ME_BOND_EXTRA;
        case 9218: /* module 36 call 2 */
            return STR_ME_CLAIM_PAYOUT;
        case 9219: /* module 36 call 3 */
            return STR_ME_UNBOND;
        case 9220: /* module 36 call 4 */
            return STR_ME_POOL_WITHDRAW_UNBONDED;
        case 9221: /* module 36 call 5 */
            return STR_ME_WITHDRAW_UNBONDED;
        case 9222: /* module 36 call 6 */
            return STR_ME_CREATE;
        case 9223: /* module 36 call 7 */
            return STR_ME_CREATE_WITH_POOL_ID;
        case 9224: /* module 36 call 8 */
            return STR_ME_NOMINATE;
        case 9225: /* module 36 call 9 */
            return STR_ME_SET_STATE;
        case 9226: /* module 36 call 10 */
            return STR_ME_SET_METADATA;
        case 9227: /* module 36 call 11 */
            return STR_ME_SET_CONFIGS;
        case 9228: /* module 36 call 12 */
            return STR_ME_UPDATE_ROLES;
        case 9229: /* module 36 call 13 */
            return STR_ME_CHILL;
        case 9230: /* module 36 call 14 */
            return STR_ME_BOND_EXTRA_OTHER;
        case 9231: /* module 36 call 15 */
            return STR_ME_SET_CLAIM_PERMISSION;
        case 9232: /* module 36 call 16 */
            return STR_ME_CLAIM_PAYOUT_OTHER;
        case 9233: /* module 36 call 17 */
            return STR_ME_SET_COMMISSION;
        case 9234: /* module 36 call 18 */
            return STR_ME_SET_COMMISSION_MAX;
        case 9235: /* module 36 call 19 */
            return STR_ME_SET_COMMISSION_CHANGE_RATE;
        case 9236: /* module 36 call 20 */
            return STR_ME_CLAIM_COMMISSION;
        case 9237: /* module 36 call 21 */
            return STR_ME_ADJUST_POOL_DEPOSIT;
        case 9238: /* module 36 call 22 */
            return STR_ME_SET_COMMISSION_CLAIM_PERMISSION;
        case 9473: /* module 37 call 1 */
            return STR_ME_SET_IDENTITY;
        case 9475: /* module 37 call 3 */
            return STR_ME_CLEAR_IDENTITY;
        case 9728: /* module 38 call 0 */
            return STR_ME_MANDATE;
        case 9985: /* module 39 call 1 */
            return STR_ME_EXECUTE;
        case 9987: /* module 39 call 3 */
            return STR_ME_SEND_MESSAGE;
        case 10240: /* module 40 call 0 */
            return STR_ME_PROXY;
        case 10241: /* module 40 call 1 */
            return STR_ME_ADD_PROXY;
        case 10242: /* module 40 call 2 */
            return STR_ME_REMOVE_PROXY;
        default:
            return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V1(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 256: /* module 1 call 0 */
            return 1;
        case 258: /* module 1 call 2 */
            return 1;
        case 260: /* module 1 call 4 */
            return 1;
        case 1536: /* module 6 call 0 */
            return 2;
        case 1538: /* module 6 call 2 */
            return 3;
        case 1539: /* module 6 call 3 */
            return 2;
        case 1540: /* module 6 call 4 */
            return 2;
        case 2560: /* module 10 call 0 */
            return 2;
        case 2561: /* module 10 call 1 */
            return 1;
        case 2562: /* module 10 call 2 */
            return 1;
        case 2563: /* module 10 call 3 */
            return 1;
        case 2564: /* module 10 call 4 */
            return 1;
        case 2565: /* module 10 call 5 */
            return 1;
        case 2566: /* module 10 call 6 */
            return 0;
        case 2567: /* module 10 call 7 */
            return 1;
        case 2568: /* module 10 call 8 */
            return 0;
        case 2578: /* module 10 call 18 */
            return 2;
        case 2579: /* module 10 call 19 */
            return 1;
        case 2816: /* module 11 call 0 */
            return 2;
        case 2817: /* module 11 call 1 */
            return 0;
        case 0: /* module 0 call 0 */
            return 1;
        case 1: /* module 0 call 1 */
            return 1;
        case 2: /* module 0 call 2 */
            return 1;
        case 3: /* module 0 call 3 */
            return 1;
        case 7: /* module 0 call 7 */
            return 1;
        case 9: /* module 0 call 9 */
            return 1;
        case 10: /* module 0 call 10 */
            return 1;
        case 11: /* module 0 call 11 */
            return 1;
        case 261: /* module 1 call 5 */
            return 2;
        case 1541: /* module 6 call 5 */
            return 2;
        case 1542: /* module 6 call 6 */
            return 1;
        case 1544: /* module 6 call 8 */
            return 2;
        case 1545: /* module 6 call 9 */
            return 2;
        case 2569: /* module 10 call 9 */
            return 1;
        case 2570: /* module 10 call 10 */
            return 1;
        case 2571: /* module 10 call 11 */
            return 1;
        case 2572: /* module 10 call 12 */
            return 0;
        case 2573: /* module 10 call 13 */
            return 0;
        case 2574: /* module 10 call 14 */
            return 1;
        case 2575: /* module 10 call 15 */
            return 2;
        case 2576: /* module 10 call 16 */
            return 0;
        case 2577: /* module 10 call 17 */
            return 2;
        case 2580: /* module 10 call 20 */
            return 2;
        case 2581: /* module 10 call 21 */
            return 1;
        case 2582: /* module 10 call 22 */
            return 6;
        case 2583: /* module 10 call 23 */
            return 1;
        case 2584: /* module 10 call 24 */
            return 1;
        case 2585: /* module 10 call 25 */
            return 1;
        case 2586: /* module 10 call 26 */
            return 3;
        case 2587: /* module 10 call 27 */
            return 1;
        case 3584: /* module 14 call 0 */
            return 3;
        case 3585: /* module 14 call 1 */
            return 2;
        case 3586: /* module 14 call 2 */
            return 3;
        case 3587: /* module 14 call 3 */
            return 3;
        case 4354: /* module 17 call 2 */
            return 2;
        case 6148: /* module 24 call 4 */
            return 4;
        case 7424: /* module 29 call 0 */
            return 1;
        case 7425: /* module 29 call 1 */
            return 1;
        case 7426: /* module 29 call 2 */
            return 2;
        case 7427: /* module 29 call 3 */
            return 2;
        case 7428: /* module 29 call 4 */
            return 1;
        case 8704: /* module 34 call 0 */
            return 2;
        case 8705: /* module 34 call 1 */
            return 5;
        case 8706: /* module 34 call 2 */
            return 5;
        case 8707: /* module 34 call 3 */
            return 4;
        case 9216: /* module 36 call 0 */
            return 2;
        case 9217: /* module 36 call 1 */
            return 1;
        case 9218: /* module 36 call 2 */
            return 0;
        case 9219: /* module 36 call 3 */
            return 2;
        case 9220: /* module 36 call 4 */
            return 2;
        case 9221: /* module 36 call 5 */
            return 2;
        case 9222: /* module 36 call 6 */
            return 4;
        case 9223: /* module 36 call 7 */
            return 5;
        case 9224: /* module 36 call 8 */
            return 2;
        case 9225: /* module 36 call 9 */
            return 2;
        case 9226: /* module 36 call 10 */
            return 2;
        case 9227: /* module 36 call 11 */
            return 6;
        case 9228: /* module 36 call 12 */
            return 4;
        case 9229: /* module 36 call 13 */
            return 1;
        case 9230: /* module 36 call 14 */
            return 2;
        case 9231: /* module 36 call 15 */
            return 1;
        case 9232: /* module 36 call 16 */
            return 1;
        case 9233: /* module 36 call 17 */
            return 2;
        case 9234: /* module 36 call 18 */
            return 2;
        case 9235: /* module 36 call 19 */
            return 2;
        case 9236: /* module 36 call 20 */
            return 1;
        case 9237: /* module 36 call 21 */
            return 1;
        case 9238: /* module 36 call 22 */
            return 2;
        case 9473: /* module 37 call 1 */
            return 1;
        case 9475: /* module 37 call 3 */
            return 0;
        case 9728: /* module 38 call 0 */
            return 1;
        case 9985: /* module 39 call 1 */
            return 4;
        case 9987: /* module 39 call 3 */
            return 3;
        case 10240: /* module 40 call 0 */
            return 3;
        case 10241: /* module 40 call 1 */
            return 3;
        case 10242: /* module 40 call 2 */
            return 3;
        default:
            return 0;
    }

    return 0;
}

const char *_getMethod_ItemName_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 256: /* module 1 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_calls;
                default:
                    return NULL;
            }
        case 258: /* module 1 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_calls;
                default:
                    return NULL;
            }
        case 260: /* module 1 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_calls;
                default:
                    return NULL;
            }
        case 1536: /* module 6 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1538: /* module 6 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_source;
                case 1:
                    return STR_IT_dest;
                case 2:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1539: /* module 6 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1540: /* module 6 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_keep_alive;
                default:
                    return NULL;
            }
        case 2560: /* module 10 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                case 1:
                    return STR_IT_payee;
                default:
                    return NULL;
            }
        case 2561: /* module 10 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 2562: /* module 10 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 2563: /* module 10 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 2564: /* module 10 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_prefs;
                default:
                    return NULL;
            }
        case 2565: /* module 10 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_targets;
                default:
                    return NULL;
            }
        case 2566: /* module 10 call 6 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2567: /* module 10 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_payee;
                default:
                    return NULL;
            }
        case 2568: /* module 10 call 8 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2578: /* module 10 call 18 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_validator_stash;
                case 1:
                    return STR_IT_era;
                default:
                    return NULL;
            }
        case 2579: /* module 10 call 19 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 2816: /* module 11 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_keys;
                case 1:
                    return STR_IT_proof;
                default:
                    return NULL;
            }
        case 2817: /* module 11 call 1 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 0: /* module 0 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_remark;
                default:
                    return NULL;
            }
        case 1: /* module 0 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pages;
                default:
                    return NULL;
            }
        case 2: /* module 0 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code;
                default:
                    return NULL;
            }
        case 3: /* module 0 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code;
                default:
                    return NULL;
            }
        case 7: /* module 0 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_remark;
                default:
                    return NULL;
            }
        case 9: /* module 0 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code_hash;
                default:
                    return NULL;
            }
        case 10: /* module 0 call 10 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code_hash;
                default:
                    return NULL;
            }
        case 11: /* module 0 call 11 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code;
                default:
                    return NULL;
            }
        case 261: /* module 1 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_call;
                case 1:
                    return STR_IT_weight;
                default:
                    return NULL;
            }
        case 1541: /* module 6 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1542: /* module 6 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                default:
                    return NULL;
            }
        case 1544: /* module 6 call 8 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                case 1:
                    return STR_IT_new_free;
                default:
                    return NULL;
            }
        case 1545: /* module 6 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_direction;
                case 1:
                    return STR_IT_delta;
                default:
                    return NULL;
            }
        case 2569: /* module 10 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_;
                default:
                    return NULL;
            }
        case 2570: /* module 10 call 10 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_additional;
                default:
                    return NULL;
            }
        case 2571: /* module 10 call 11 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_factor;
                default:
                    return NULL;
            }
        case 2572: /* module 10 call 12 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2573: /* module 10 call 13 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2574: /* module 10 call 14 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_invulnerables;
                default:
                    return NULL;
            }
        case 2575: /* module 10 call 15 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 2576: /* module 10 call 16 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2577: /* module 10 call 17 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_era;
                case 1:
                    return STR_IT_slash_indices;
                default:
                    return NULL;
            }
        case 2580: /* module 10 call 20 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 2581: /* module 10 call 21 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                default:
                    return NULL;
            }
        case 2582: /* module 10 call 22 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_min_nominator_bond;
                case 1:
                    return STR_IT_min_validator_bond;
                case 2:
                    return STR_IT_max_nominator_count;
                case 3:
                    return STR_IT_max_validator_count;
                case 4:
                    return STR_IT_chill_threshold;
                case 5:
                    return STR_IT_min_commission;
                default:
                    return NULL;
            }
        case 2583: /* module 10 call 23 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                default:
                    return NULL;
            }
        case 2584: /* module 10 call 24 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_validator_stash;
                default:
                    return NULL;
            }
        case 2585: /* module 10 call 25 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_;
                default:
                    return NULL;
            }
        case 2586: /* module 10 call 26 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_validator_stash;
                case 1:
                    return STR_IT_era;
                case 2:
                    return STR_IT_page;
                default:
                    return NULL;
            }
        case 2587: /* module 10 call 27 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_controller;
                default:
                    return NULL;
            }
        case 3584: /* module 14 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_members;
                case 1:
                    return STR_IT_prime;
                case 2:
                    return STR_IT_old_count;
                default:
                    return NULL;
            }
        case 3585: /* module 14 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_proposal;
                case 1:
                    return STR_IT_length_bound;
                default:
                    return NULL;
            }
        case 3586: /* module 14 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_threshold;
                case 1:
                    return STR_IT_proposal;
                case 2:
                    return STR_IT_length_bound;
                default:
                    return NULL;
            }
        case 3587: /* module 14 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_proposal;
                case 1:
                    return STR_IT_index;
                case 2:
                    return STR_IT_approve;
                default:
                    return NULL;
            }
        case 4354: /* module 17 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_delay;
                case 1:
                    return STR_IT_best_finalized_block_number;
                default:
                    return NULL;
            }
        case 6148: /* module 24 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_after;
                case 1:
                    return STR_IT_maybe_periodic;
                case 2:
                    return STR_IT_priority;
                case 3:
                    return STR_IT_call;
                default:
                    return NULL;
            }
        case 7424: /* module 29 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_key;
                default:
                    return NULL;
            }
        case 7425: /* module 29 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_data;
                default:
                    return NULL;
            }
        case 7426: /* module 29 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_rows;
                case 1:
                    return STR_IT_cols;
                default:
                    return NULL;
            }
        case 7427: /* module 29 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_old_key;
                case 1:
                    return STR_IT_new_key;
                default:
                    return NULL;
            }
        case 7428: /* module 29 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_modifier;
                default:
                    return NULL;
            }
        case 8704: /* module 34 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_other_signatories;
                case 1:
                    return STR_IT_call;
                default:
                    return NULL;
            }
        case 8705: /* module 34 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_threshold;
                case 1:
                    return STR_IT_other_signatories;
                case 2:
                    return STR_IT_maybe_timepoint;
                case 3:
                    return STR_IT_call;
                case 4:
                    return STR_IT_max_weight;
                default:
                    return NULL;
            }
        case 8706: /* module 34 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_threshold;
                case 1:
                    return STR_IT_other_signatories;
                case 2:
                    return STR_IT_maybe_timepoint;
                case 3:
                    return STR_IT_call_hash;
                case 4:
                    return STR_IT_max_weight;
                default:
                    return NULL;
            }
        case 8707: /* module 34 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_threshold;
                case 1:
                    return STR_IT_other_signatories;
                case 2:
                    return STR_IT_timepoint;
                case 3:
                    return STR_IT_call_hash;
                default:
                    return NULL;
            }
        case 9216: /* module 36 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                case 1:
                    return STR_IT_pool_id;
                default:
                    return NULL;
            }
        case 9217: /* module 36 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_extra;
                default:
                    return NULL;
            }
        case 9218: /* module 36 call 2 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 9219: /* module 36 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_member_account;
                case 1:
                    return STR_IT_unbonding_points;
                default:
                    return NULL;
            }
        case 9220: /* module 36 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 9221: /* module 36 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_member_account;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 9222: /* module 36 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                case 1:
                    return STR_IT_root;
                case 2:
                    return STR_IT_nominator;
                case 3:
                    return STR_IT_bouncer;
                default:
                    return NULL;
            }
        case 9223: /* module 36 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                case 1:
                    return STR_IT_root;
                case 2:
                    return STR_IT_nominator;
                case 3:
                    return STR_IT_bouncer;
                case 4:
                    return STR_IT_pool_id;
                default:
                    return NULL;
            }
        case 9224: /* module 36 call 8 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_validators;
                default:
                    return NULL;
            }
        case 9225: /* module 36 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_state;
                default:
                    return NULL;
            }
        case 9226: /* module 36 call 10 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_metadata;
                default:
                    return NULL;
            }
        case 9227: /* module 36 call 11 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_min_join_bond;
                case 1:
                    return STR_IT_min_create_bond;
                case 2:
                    return STR_IT_max_pools;
                case 3:
                    return STR_IT_max_members;
                case 4:
                    return STR_IT_max_members_per_pool;
                case 5:
                    return STR_IT_global_max_commission;
                default:
                    return NULL;
            }
        case 9228: /* module 36 call 12 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_new_root;
                case 2:
                    return STR_IT_new_nominator;
                case 3:
                    return STR_IT_new_bouncer;
                default:
                    return NULL;
            }
        case 9229: /* module 36 call 13 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                default:
                    return NULL;
            }
        case 9230: /* module 36 call 14 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_member;
                case 1:
                    return STR_IT_extra;
                default:
                    return NULL;
            }
        case 9231: /* module 36 call 15 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_permission;
                default:
                    return NULL;
            }
        case 9232: /* module 36 call 16 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_other;
                default:
                    return NULL;
            }
        case 9233: /* module 36 call 17 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_new_commission;
                default:
                    return NULL;
            }
        case 9234: /* module 36 call 18 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_max_commission;
                default:
                    return NULL;
            }
        case 9235: /* module 36 call 19 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_change_rate;
                default:
                    return NULL;
            }
        case 9236: /* module 36 call 20 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                default:
                    return NULL;
            }
        case 9237: /* module 36 call 21 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                default:
                    return NULL;
            }
        case 9238: /* module 36 call 22 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_permission;
                default:
                    return NULL;
            }
        case 9473: /* module 37 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_info;
                default:
                    return NULL;
            }
        case 9475: /* module 37 call 3 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 9728: /* module 38 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_call;
                default:
                    return NULL;
            }
        case 9985: /* module 39 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_slot;
                case 1:
                    return STR_IT_addr_message;
                case 2:
                    return STR_IT_account_proof;
                case 3:
                    return STR_IT_storage_proof;
                default:
                    return NULL;
            }
        case 9987: /* module 39 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_message;
                case 1:
                    return STR_IT_to;
                case 2:
                    return STR_IT_domain;
                default:
                    return NULL;
            }
        case 10240: /* module 40 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_real;
                case 1:
                    return STR_IT_force_proxy_type;
                case 2:
                    return STR_IT_call;
                default:
                    return NULL;
            }
        case 10241: /* module 40 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_delegate;
                case 1:
                    return STR_IT_proxy_type;
                case 2:
                    return STR_IT_delay;
                default:
                    return NULL;
            }
        case 10242: /* module 40 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_delegate;
                case 1:
                    return STR_IT_proxy_type;
                case 2:
                    return STR_IT_delay;
                default:
                    return NULL;
            }
        default:
            return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V1(pd_Method_V1_t *m, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
                                       char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 256: /* module 1 call 0 */
            switch (itemIdx) {
                case 0: /* utility_batch_V1 - calls */;
                    return _toStringVecCall(&m->basic.utility_batch_V1.calls, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 258: /* module 1 call 2 */
            switch (itemIdx) {
                case 0: /* utility_batch_all_V1 - calls */;
                    return _toStringVecCall(&m->basic.utility_batch_all_V1.calls, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 260: /* module 1 call 4 */
            switch (itemIdx) {
                case 0: /* utility_force_batch_V1 - calls */;
                    return _toStringVecCall(&m->basic.utility_force_batch_V1.calls, outValue, outValueLen, pageIdx,
                                            pageCount);
                default:
                    return parser_no_data;
            }
        case 1536: /* module 6 call 0 */
            switch (itemIdx) {
                case 0: /* balances_transfer_allow_death_V1 - dest */;
                    return _toStringAccountIdLookupOfT(&m->nested.balances_transfer_allow_death_V1.dest, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 1: /* balances_transfer_allow_death_V1 - amount */;
                    return _toStringCompactBalance(&m->nested.balances_transfer_allow_death_V1.amount, outValue, outValueLen,
                                                   pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1538: /* module 6 call 2 */
            switch (itemIdx) {
                case 0: /* balances_force_transfer_V1 - source */;
                    return _toStringAccountIdLookupOfT(&m->nested.balances_force_transfer_V1.source, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* balances_force_transfer_V1 - dest */;
                    return _toStringAccountIdLookupOfT(&m->nested.balances_force_transfer_V1.dest, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 2: /* balances_force_transfer_V1 - amount */;
                    return _toStringCompactBalance(&m->nested.balances_force_transfer_V1.amount, outValue, outValueLen,
                                                   pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1539: /* module 6 call 3 */
            switch (itemIdx) {
                case 0: /* balances_transfer_keep_alive_V1 - dest */;
                    return _toStringAccountIdLookupOfT(&m->nested.balances_transfer_keep_alive_V1.dest, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 1: /* balances_transfer_keep_alive_V1 - amount */;
                    return _toStringCompactBalance(&m->nested.balances_transfer_keep_alive_V1.amount, outValue, outValueLen,
                                                   pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1540: /* module 6 call 4 */
            switch (itemIdx) {
                case 0: /* balances_transfer_all_V1 - dest */;
                    return _toStringAccountIdLookupOfT(&m->nested.balances_transfer_all_V1.dest, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* balances_transfer_all_V1 - keep_alive */;
                    return _toStringbool(&m->nested.balances_transfer_all_V1.keep_alive, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 2560: /* module 10 call 0 */
            switch (itemIdx) {
                case 0: /* staking_bond_V1 - amount */;
                    return _toStringCompactBalance(&m->nested.staking_bond_V1.amount, outValue, outValueLen, pageIdx,
                                                   pageCount);
                case 1: /* staking_bond_V1 - payee */;
                    return _toStringRewardDestination(&m->nested.staking_bond_V1.payee, outValue, outValueLen, pageIdx,
                                                      pageCount);
                default:
                    return parser_no_data;
            }
        case 2561: /* module 10 call 1 */
            switch (itemIdx) {
                case 0: /* staking_bond_extra_V1 - amount */;
                    return _toStringCompactBalance(&m->nested.staking_bond_extra_V1.amount, outValue, outValueLen, pageIdx,
                                                   pageCount);
                default:
                    return parser_no_data;
            }
        case 2562: /* module 10 call 2 */
            switch (itemIdx) {
                case 0: /* staking_unbond_V1 - amount */;
                    return _toStringCompactBalance(&m->nested.staking_unbond_V1.amount, outValue, outValueLen, pageIdx,
                                                   pageCount);
                default:
                    return parser_no_data;
            }
        case 2563: /* module 10 call 3 */
            switch (itemIdx) {
                case 0: /* staking_withdraw_unbonded_V1 - num_slashing_spans */;
                    return _toStringu32(&m->nested.staking_withdraw_unbonded_V1.num_slashing_spans, outValue, outValueLen,
                                        pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2564: /* module 10 call 4 */
            switch (itemIdx) {
                case 0: /* staking_validate_V1 - prefs */;
                    return _toStringValidatorPrefs(&m->nested.staking_validate_V1.prefs, outValue, outValueLen, pageIdx,
                                                   pageCount);
                default:
                    return parser_no_data;
            }
        case 2565: /* module 10 call 5 */
            switch (itemIdx) {
                case 0: /* staking_nominate_V1 - targets */;
                    return _toStringVecAccountIdLookupOfT(&m->nested.staking_nominate_V1.targets, outValue, outValueLen,
                                                          pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2566: /* module 10 call 6 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2567: /* module 10 call 7 */
            switch (itemIdx) {
                case 0: /* staking_set_payee_V1 - payee */;
                    return _toStringRewardDestination(&m->nested.staking_set_payee_V1.payee, outValue, outValueLen, pageIdx,
                                                      pageCount);
                default:
                    return parser_no_data;
            }
        case 2568: /* module 10 call 8 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2578: /* module 10 call 18 */
            switch (itemIdx) {
                case 0: /* staking_payout_stakers_V1 - validator_stash */;
                    return _toStringAccountId(&m->nested.staking_payout_stakers_V1.validator_stash, outValue, outValueLen,
                                              pageIdx, pageCount);
                case 1: /* staking_payout_stakers_V1 - era */;
                    return _toStringEraIndex(&m->nested.staking_payout_stakers_V1.era, outValue, outValueLen, pageIdx,
                                             pageCount);
                default:
                    return parser_no_data;
            }
        case 2579: /* module 10 call 19 */
            switch (itemIdx) {
                case 0: /* staking_rebond_V1 - amount */;
                    return _toStringCompactBalance(&m->nested.staking_rebond_V1.amount, outValue, outValueLen, pageIdx,
                                                   pageCount);
                default:
                    return parser_no_data;
            }
        case 2816: /* module 11 call 0 */
            switch (itemIdx) {
                case 0: /* session_set_keys_V1 - keys */;
                    return _toStringKeys(&m->nested.session_set_keys_V1.keys, outValue, outValueLen, pageIdx, pageCount);
                case 1: /* session_set_keys_V1 - proof */;
                    return _toStringBytes(&m->nested.session_set_keys_V1.proof, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2817: /* module 11 call 1 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 0: /* module 0 call 0 */
            switch (itemIdx) {
                case 0: /* system_remark_V1 - remark */;
                    return _toStringBytes(&m->nested.system_remark_V1.remark, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1: /* module 0 call 1 */
            switch (itemIdx) {
                case 0: /* system_set_heap_pages_V1 - pages */;
                    return _toStringu64(&m->nested.system_set_heap_pages_V1.pages, outValue, outValueLen, pageIdx,
                                        pageCount);
                default:
                    return parser_no_data;
            }
        case 2: /* module 0 call 2 */
            switch (itemIdx) {
                case 0: /* system_set_code_V1 - code */;
                    return _toStringBytes(&m->nested.system_set_code_V1.code, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 3: /* module 0 call 3 */
            switch (itemIdx) {
                case 0: /* system_set_code_without_checks_V1 - code */;
                    return _toStringVecu8(&m->nested.system_set_code_without_checks_V1.code, outValue, outValueLen, pageIdx,
                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 7: /* module 0 call 7 */
            switch (itemIdx) {
                case 0: /* system_remark_with_event_V1 - remark */;
                    return _toStringBytes(&m->nested.system_remark_with_event_V1.remark, outValue, outValueLen, pageIdx,
                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 9: /* module 0 call 9 */
            switch (itemIdx) {
                case 0: /* system_authorize_upgrade_V1 - code_hash */;
                    return _toStringHash(&m->basic.system_authorize_upgrade_V1.code_hash, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 10: /* module 0 call 10 */
            switch (itemIdx) {
                case 0: /* system_authorize_upgrade_without_checks_V1 - code_hash */;
                    return _toStringHash(&m->basic.system_authorize_upgrade_without_checks_V1.code_hash, outValue,
                                         outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 11: /* module 0 call 11 */
            switch (itemIdx) {
                case 0: /* system_apply_authorized_upgrade_V1 - code */;
                    return _toStringVecu8(&m->basic.system_apply_authorized_upgrade_V1.code, outValue, outValueLen, pageIdx,
                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 261: /* module 1 call 5 */
            switch (itemIdx) {
                case 0: /* utility_with_weight_V1 - call */;
                    return _toStringCall(&m->basic.utility_with_weight_V1.call, outValue, outValueLen, pageIdx, pageCount);
                case 1: /* utility_with_weight_V1 - weight */;
                    return _toStringWeight(&m->basic.utility_with_weight_V1.weight, outValue, outValueLen, pageIdx,
                                           pageCount);
                default:
                    return parser_no_data;
            }
        case 1541: /* module 6 call 5 */
            switch (itemIdx) {
                case 0: /* balances_force_unreserve_V1 - who */;
                    return _toStringAccountIdLookupOfT(&m->basic.balances_force_unreserve_V1.who, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* balances_force_unreserve_V1 - amount */;
                    return _toStringBalance(&m->basic.balances_force_unreserve_V1.amount, outValue, outValueLen, pageIdx,
                                            pageCount);
                default:
                    return parser_no_data;
            }
        case 1542: /* module 6 call 6 */
            switch (itemIdx) {
                case 0: /* balances_upgrade_accounts_V1 - who */;
                    return _toStringVecAccountId(&m->basic.balances_upgrade_accounts_V1.who, outValue, outValueLen, pageIdx,
                                                 pageCount);
                default:
                    return parser_no_data;
            }
        case 1544: /* module 6 call 8 */
            switch (itemIdx) {
                case 0: /* balances_force_set_balance_V1 - who */;
                    return _toStringAccountIdLookupOfT(&m->basic.balances_force_set_balance_V1.who, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* balances_force_set_balance_V1 - new_free */;
                    return _toStringCompactBalance(&m->basic.balances_force_set_balance_V1.new_free, outValue, outValueLen,
                                                   pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1545: /* module 6 call 9 */
            switch (itemIdx) {
                case 0: /* balances_force_adjust_total_issuance_V1 - direction */;
                    return _toStringAdjustmentDirection(&m->basic.balances_force_adjust_total_issuance_V1.direction,
                                                        outValue, outValueLen, pageIdx, pageCount);
                case 1: /* balances_force_adjust_total_issuance_V1 - delta */;
                    return _toStringCompactBalance(&m->basic.balances_force_adjust_total_issuance_V1.delta, outValue,
                                                   outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2569: /* module 10 call 9 */
            switch (itemIdx) {
                case 0: /* staking_set_validator_count_V1 - new_ */;
                    return _toStringCompactu32(&m->basic.staking_set_validator_count_V1.new_, outValue, outValueLen, pageIdx,
                                               pageCount);
                default:
                    return parser_no_data;
            }
        case 2570: /* module 10 call 10 */
            switch (itemIdx) {
                case 0: /* staking_increase_validator_count_V1 - additional */;
                    return _toStringCompactu32(&m->basic.staking_increase_validator_count_V1.additional, outValue,
                                               outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2571: /* module 10 call 11 */
            switch (itemIdx) {
                case 0: /* staking_scale_validator_count_V1 - factor */;
                    return _toStringPercent(&m->basic.staking_scale_validator_count_V1.factor, outValue, outValueLen,
                                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2572: /* module 10 call 12 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2573: /* module 10 call 13 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2574: /* module 10 call 14 */
            switch (itemIdx) {
                case 0: /* staking_set_invulnerables_V1 - invulnerables */;
                    return _toStringVecAccountId(&m->basic.staking_set_invulnerables_V1.invulnerables, outValue, outValueLen,
                                                 pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2575: /* module 10 call 15 */
            switch (itemIdx) {
                case 0: /* staking_force_unstake_V1 - stash */;
                    return _toStringAccountId(&m->basic.staking_force_unstake_V1.stash, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 1: /* staking_force_unstake_V1 - num_slashing_spans */;
                    return _toStringu32(&m->basic.staking_force_unstake_V1.num_slashing_spans, outValue, outValueLen,
                                        pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2576: /* module 10 call 16 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2577: /* module 10 call 17 */
            switch (itemIdx) {
                case 0: /* staking_cancel_deferred_slash_V1 - era */;
                    return _toStringEraIndex(&m->basic.staking_cancel_deferred_slash_V1.era, outValue, outValueLen, pageIdx,
                                             pageCount);
                case 1: /* staking_cancel_deferred_slash_V1 - slash_indices */;
                    return _toStringVecu32(&m->basic.staking_cancel_deferred_slash_V1.slash_indices, outValue, outValueLen,
                                           pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2580: /* module 10 call 20 */
            switch (itemIdx) {
                case 0: /* staking_reap_stash_V1 - stash */;
                    return _toStringAccountId(&m->basic.staking_reap_stash_V1.stash, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 1: /* staking_reap_stash_V1 - num_slashing_spans */;
                    return _toStringu32(&m->basic.staking_reap_stash_V1.num_slashing_spans, outValue, outValueLen, pageIdx,
                                        pageCount);
                default:
                    return parser_no_data;
            }
        case 2581: /* module 10 call 21 */
            switch (itemIdx) {
                case 0: /* staking_kick_V1 - who */;
                    return _toStringVecAccountIdLookupOfT(&m->basic.staking_kick_V1.who, outValue, outValueLen, pageIdx,
                                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 2582: /* module 10 call 22 */
            switch (itemIdx) {
                case 0: /* staking_set_staking_configs_V1 - min_nominator_bond */;
                    return _toStringConfigOpBalanceOfT(&m->basic.staking_set_staking_configs_V1.min_nominator_bond, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 1: /* staking_set_staking_configs_V1 - min_validator_bond */;
                    return _toStringConfigOpBalanceOfT(&m->basic.staking_set_staking_configs_V1.min_validator_bond, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 2: /* staking_set_staking_configs_V1 - max_nominator_count */;
                    return _toStringConfigOpu32(&m->basic.staking_set_staking_configs_V1.max_nominator_count, outValue,
                                                outValueLen, pageIdx, pageCount);
                case 3: /* staking_set_staking_configs_V1 - max_validator_count */;
                    return _toStringConfigOpu32(&m->basic.staking_set_staking_configs_V1.max_validator_count, outValue,
                                                outValueLen, pageIdx, pageCount);
                case 4: /* staking_set_staking_configs_V1 - chill_threshold */;
                    return _toStringConfigOpPercent(&m->basic.staking_set_staking_configs_V1.chill_threshold, outValue,
                                                    outValueLen, pageIdx, pageCount);
                case 5: /* staking_set_staking_configs_V1 - min_commission */;
                    return _toStringConfigOpPerbill(&m->basic.staking_set_staking_configs_V1.min_commission, outValue,
                                                    outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2583: /* module 10 call 23 */
            switch (itemIdx) {
                case 0: /* staking_chill_other_V1 - stash */;
                    return _toStringAccountId(&m->basic.staking_chill_other_V1.stash, outValue, outValueLen, pageIdx,
                                              pageCount);
                default:
                    return parser_no_data;
            }
        case 2584: /* module 10 call 24 */
            switch (itemIdx) {
                case 0: /* staking_force_apply_min_commission_V1 - validator_stash */;
                    return _toStringAccountId(&m->basic.staking_force_apply_min_commission_V1.validator_stash, outValue,
                                              outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2585: /* module 10 call 25 */
            switch (itemIdx) {
                case 0: /* staking_set_min_commission_V1 - new_ */;
                    return _toStringPerbill(&m->basic.staking_set_min_commission_V1.new_, outValue, outValueLen, pageIdx,
                                            pageCount);
                default:
                    return parser_no_data;
            }
        case 2586: /* module 10 call 26 */
            switch (itemIdx) {
                case 0: /* staking_payout_stakers_by_page_V1 - validator_stash */;
                    return _toStringAccountId(&m->basic.staking_payout_stakers_by_page_V1.validator_stash, outValue,
                                              outValueLen, pageIdx, pageCount);
                case 1: /* staking_payout_stakers_by_page_V1 - era */;
                    return _toStringEraIndex(&m->basic.staking_payout_stakers_by_page_V1.era, outValue, outValueLen, pageIdx,
                                             pageCount);
                case 2: /* staking_payout_stakers_by_page_V1 - page */;
                    return _toStringPage(&m->basic.staking_payout_stakers_by_page_V1.page, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 2587: /* module 10 call 27 */
            switch (itemIdx) {
                case 0: /* staking_update_payee_V1 - controller */;
                    return _toStringAccountId(&m->basic.staking_update_payee_V1.controller, outValue, outValueLen, pageIdx,
                                              pageCount);
                default:
                    return parser_no_data;
            }
        case 3584: /* module 14 call 0 */
            switch (itemIdx) {
                case 0: /* technicalcommittee_set_members_V1 - new_members */;
                    return _toStringVecAccountId(&m->basic.technicalcommittee_set_members_V1.new_members, outValue,
                                                 outValueLen, pageIdx, pageCount);
                case 1: /* technicalcommittee_set_members_V1 - prime */;
                    return _toStringOptionAccountId(&m->basic.technicalcommittee_set_members_V1.prime, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 2: /* technicalcommittee_set_members_V1 - old_count */;
                    return _toStringMemberCount(&m->basic.technicalcommittee_set_members_V1.old_count, outValue, outValueLen,
                                                pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 3585: /* module 14 call 1 */
            switch (itemIdx) {
                case 0: /* technicalcommittee_execute_V1 - proposal */;
                    return _toStringProposal(&m->basic.technicalcommittee_execute_V1.proposal, outValue, outValueLen,
                                             pageIdx, pageCount);
                case 1: /* technicalcommittee_execute_V1 - length_bound */;
                    return _toStringCompactu32(&m->basic.technicalcommittee_execute_V1.length_bound, outValue, outValueLen,
                                               pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 3586: /* module 14 call 2 */
            switch (itemIdx) {
                case 0: /* technicalcommittee_propose_V1 - threshold */;
                    return _toStringCompactu32(&m->basic.technicalcommittee_propose_V1.threshold, outValue, outValueLen,
                                               pageIdx, pageCount);
                case 1: /* technicalcommittee_propose_V1 - proposal */;
                    return _toStringProposal(&m->basic.technicalcommittee_propose_V1.proposal, outValue, outValueLen,
                                             pageIdx, pageCount);
                case 2: /* technicalcommittee_propose_V1 - length_bound */;
                    return _toStringCompactu32(&m->basic.technicalcommittee_propose_V1.length_bound, outValue, outValueLen,
                                               pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 3587: /* module 14 call 3 */
            switch (itemIdx) {
                case 0: /* technicalcommittee_vote_V1 - proposal */;
                    return _toStringHash(&m->basic.technicalcommittee_vote_V1.proposal, outValue, outValueLen, pageIdx,
                                         pageCount);
                case 1: /* technicalcommittee_vote_V1 - index */;
                    return _toStringCompactu32(&m->basic.technicalcommittee_vote_V1.index, outValue, outValueLen, pageIdx,
                                               pageCount);
                case 2: /* technicalcommittee_vote_V1 - approve */;
                    return _toStringbool(&m->basic.technicalcommittee_vote_V1.approve, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 4354: /* module 17 call 2 */
            switch (itemIdx) {
                case 0: /* grandpa_note_stalled_V1 - delay */;
                    return _toStringBlockNumber(&m->basic.grandpa_note_stalled_V1.delay, outValue, outValueLen, pageIdx,
                                                pageCount);
                case 1: /* grandpa_note_stalled_V1 - best_finalized_block_number */;
                    return _toStringBlockNumber(&m->basic.grandpa_note_stalled_V1.best_finalized_block_number, outValue,
                                                outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 6148: /* module 24 call 4 */
            switch (itemIdx) {
                case 0: /* scheduler_schedule_after_V1 - after */;
                    return _toStringBlockNumber(&m->basic.scheduler_schedule_after_V1.after, outValue, outValueLen, pageIdx,
                                                pageCount);
                case 1: /* scheduler_schedule_after_V1 - maybe_periodic */;
                    return _toStringOptionschedulePeriodBlockNumber(&m->basic.scheduler_schedule_after_V1.maybe_periodic,
                                                                    outValue, outValueLen, pageIdx, pageCount);
                case 2: /* scheduler_schedule_after_V1 - priority */;
                    return _toStringschedulePriority(&m->basic.scheduler_schedule_after_V1.priority, outValue, outValueLen,
                                                     pageIdx, pageCount);
                case 3: /* scheduler_schedule_after_V1 - call */;
                    return _toStringCall(&m->basic.scheduler_schedule_after_V1.call, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 7424: /* module 29 call 0 */
            switch (itemIdx) {
                case 0: /* dataavailability_create_application_key_V1 - key */;
                    return _toStringAppKey(&m->basic.dataavailability_create_application_key_V1.key, outValue, outValueLen,
                                           pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 7425: /* module 29 call 1 */
            switch (itemIdx) {
                case 0: /* dataavailability_submit_data_V1 - data */;
                    return _toStringAppData(&m->basic.dataavailability_submit_data_V1.data, outValue, outValueLen, pageIdx,
                                            pageCount);
                default:
                    return parser_no_data;
            }
        case 7426: /* module 29 call 2 */
            switch (itemIdx) {
                case 0: /* dataavailability_submit_block_length_proposal_V1 - rows */;
                    return _toStringu32(&m->basic.dataavailability_submit_block_length_proposal_V1.rows, outValue,
                                        outValueLen, pageIdx, pageCount);
                case 1: /* dataavailability_submit_block_length_proposal_V1 - cols */;
                    return _toStringu32(&m->basic.dataavailability_submit_block_length_proposal_V1.cols, outValue,
                                        outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 7427: /* module 29 call 3 */
            switch (itemIdx) {
                case 0: /* dataavailability_set_application_key_V1 - old_key */;
                    return _toStringAppKey(&m->basic.dataavailability_set_application_key_V1.old_key, outValue, outValueLen,
                                           pageIdx, pageCount);
                case 1: /* dataavailability_set_application_key_V1 - new_key */;
                    return _toStringAppKey(&m->basic.dataavailability_set_application_key_V1.new_key, outValue, outValueLen,
                                           pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 7428: /* module 29 call 4 */
            switch (itemIdx) {
                case 0: /* dataavailability_set_submit_data_fee_modifier_V1 - modifier */;
                    return _toStringDispatchFeeModifier(&m->basic.dataavailability_set_submit_data_fee_modifier_V1.modifier,
                                                        outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8704: /* module 34 call 0 */
            switch (itemIdx) {
                case 0: /* multisig_as_multi_threshold_1_V1 - other_signatories */;
                    return _toStringVecAccountId(&m->nested.multisig_as_multi_threshold_1_V1.other_signatories, outValue,
                                                 outValueLen, pageIdx, pageCount);
                case 1: /* multisig_as_multi_threshold_1_V1 - call */;
                    return _toStringCall(&m->nested.multisig_as_multi_threshold_1_V1.call, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 8705: /* module 34 call 1 */
            switch (itemIdx) {
                case 0: /* multisig_as_multi_V1 - threshold */;
                    return _toStringu16(&m->nested.multisig_as_multi_V1.threshold, outValue, outValueLen, pageIdx,
                                        pageCount);
                case 1: /* multisig_as_multi_V1 - other_signatories */;
                    return _toStringVecAccountId(&m->nested.multisig_as_multi_V1.other_signatories, outValue, outValueLen,
                                                 pageIdx, pageCount);
                case 2: /* multisig_as_multi_V1 - maybe_timepoint */;
                    return _toStringOptionTimepoint(&m->nested.multisig_as_multi_V1.maybe_timepoint, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 3: /* multisig_as_multi_V1 - call */;
                    return _toStringCall(&m->nested.multisig_as_multi_V1.call, outValue, outValueLen, pageIdx, pageCount);
                case 4: /* multisig_as_multi_V1 - max_weight */;
                    return _toStringWeight(&m->nested.multisig_as_multi_V1.max_weight, outValue, outValueLen, pageIdx,
                                           pageCount);
                default:
                    return parser_no_data;
            }
        case 8706: /* module 34 call 2 */
            switch (itemIdx) {
                case 0: /* multisig_approve_as_multi_V1 - threshold */;
                    return _toStringu16(&m->nested.multisig_approve_as_multi_V1.threshold, outValue, outValueLen, pageIdx,
                                        pageCount);
                case 1: /* multisig_approve_as_multi_V1 - other_signatories */;
                    return _toStringVecAccountId(&m->nested.multisig_approve_as_multi_V1.other_signatories, outValue,
                                                 outValueLen, pageIdx, pageCount);
                case 2: /* multisig_approve_as_multi_V1 - maybe_timepoint */;
                    return _toStringOptionTimepoint(&m->nested.multisig_approve_as_multi_V1.maybe_timepoint, outValue,
                                                    outValueLen, pageIdx, pageCount);
                case 3: /* multisig_approve_as_multi_V1 - call_hash */;
                    return _toStringH256(&m->nested.multisig_approve_as_multi_V1.call_hash, outValue, outValueLen, pageIdx,
                                         pageCount);
                case 4: /* multisig_approve_as_multi_V1 - max_weight */;
                    return _toStringWeight(&m->nested.multisig_approve_as_multi_V1.max_weight, outValue, outValueLen,
                                           pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8707: /* module 34 call 3 */
            switch (itemIdx) {
                case 0: /* multisig_cancel_as_multi_V1 - threshold */;
                    return _toStringu16(&m->nested.multisig_cancel_as_multi_V1.threshold, outValue, outValueLen, pageIdx,
                                        pageCount);
                case 1: /* multisig_cancel_as_multi_V1 - other_signatories */;
                    return _toStringVecAccountId(&m->nested.multisig_cancel_as_multi_V1.other_signatories, outValue,
                                                 outValueLen, pageIdx, pageCount);
                case 2: /* multisig_cancel_as_multi_V1 - timepoint */;
                    return _toStringTimepoint(&m->nested.multisig_cancel_as_multi_V1.timepoint, outValue, outValueLen,
                                              pageIdx, pageCount);
                case 3: /* multisig_cancel_as_multi_V1 - call_hash */;
                    return _toStringH256(&m->nested.multisig_cancel_as_multi_V1.call_hash, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 9216: /* module 36 call 0 */
            switch (itemIdx) {
                case 0: /* nominationpools_join_V1 - amount */;
                    return _toStringCompactBalance(&m->nested.nominationpools_join_V1.amount, outValue, outValueLen, pageIdx,
                                                   pageCount);
                case 1: /* nominationpools_join_V1 - pool_id */;
                    return _toStringPoolId(&m->nested.nominationpools_join_V1.pool_id, outValue, outValueLen, pageIdx,
                                           pageCount);
                default:
                    return parser_no_data;
            }
        case 9217: /* module 36 call 1 */
            switch (itemIdx) {
                case 0: /* nominationpools_bond_extra_V1 - extra */;
                    return _toStringBondExtraBalanceOfT(&m->nested.nominationpools_bond_extra_V1.extra, outValue,
                                                        outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9218: /* module 36 call 2 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 9219: /* module 36 call 3 */
            switch (itemIdx) {
                case 0: /* nominationpools_unbond_V1 - member_account */;
                    return _toStringAccountIdLookupOfT(&m->nested.nominationpools_unbond_V1.member_account, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 1: /* nominationpools_unbond_V1 - unbonding_points */;
                    return _toStringCompactBalance(&m->nested.nominationpools_unbond_V1.unbonding_points, outValue,
                                                   outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9220: /* module 36 call 4 */
            switch (itemIdx) {
                case 0: /* nominationpools_pool_withdraw_unbonded_V1 - pool_id */;
                    return _toStringPoolId(&m->basic.nominationpools_pool_withdraw_unbonded_V1.pool_id, outValue,
                                           outValueLen, pageIdx, pageCount);
                case 1: /* nominationpools_pool_withdraw_unbonded_V1 - num_slashing_spans */;
                    return _toStringu32(&m->basic.nominationpools_pool_withdraw_unbonded_V1.num_slashing_spans, outValue,
                                        outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9221: /* module 36 call 5 */
            switch (itemIdx) {
                case 0: /* nominationpools_withdraw_unbonded_V1 - member_account */;
                    return _toStringAccountIdLookupOfT(&m->nested.nominationpools_withdraw_unbonded_V1.member_account,
                                                       outValue, outValueLen, pageIdx, pageCount);
                case 1: /* nominationpools_withdraw_unbonded_V1 - num_slashing_spans */;
                    return _toStringu32(&m->nested.nominationpools_withdraw_unbonded_V1.num_slashing_spans, outValue,
                                        outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9222: /* module 36 call 6 */
            switch (itemIdx) {
                case 0: /* nominationpools_create_V1 - amount */;
                    return _toStringCompactBalance(&m->nested.nominationpools_create_V1.amount, outValue, outValueLen,
                                                   pageIdx, pageCount);
                case 1: /* nominationpools_create_V1 - root */;
                    return _toStringAccountIdLookupOfT(&m->nested.nominationpools_create_V1.root, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 2: /* nominationpools_create_V1 - nominator */;
                    return _toStringAccountIdLookupOfT(&m->nested.nominationpools_create_V1.nominator, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 3: /* nominationpools_create_V1 - bouncer */;
                    return _toStringAccountIdLookupOfT(&m->nested.nominationpools_create_V1.bouncer, outValue, outValueLen,
                                                       pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9223: /* module 36 call 7 */
            switch (itemIdx) {
                case 0: /* nominationpools_create_with_pool_id_V1 - amount */;
                    return _toStringCompactBalance(&m->basic.nominationpools_create_with_pool_id_V1.amount, outValue,
                                                   outValueLen, pageIdx, pageCount);
                case 1: /* nominationpools_create_with_pool_id_V1 - root */;
                    return _toStringAccountIdLookupOfT(&m->basic.nominationpools_create_with_pool_id_V1.root, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 2: /* nominationpools_create_with_pool_id_V1 - nominator */;
                    return _toStringAccountIdLookupOfT(&m->basic.nominationpools_create_with_pool_id_V1.nominator, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 3: /* nominationpools_create_with_pool_id_V1 - bouncer */;
                    return _toStringAccountIdLookupOfT(&m->basic.nominationpools_create_with_pool_id_V1.bouncer, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 4: /* nominationpools_create_with_pool_id_V1 - pool_id */;
                    return _toStringPoolId(&m->basic.nominationpools_create_with_pool_id_V1.pool_id, outValue, outValueLen,
                                           pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9224: /* module 36 call 8 */
            switch (itemIdx) {
                case 0: /* nominationpools_nominate_V1 - pool_id */;
                    return _toStringPoolId(&m->nested.nominationpools_nominate_V1.pool_id, outValue, outValueLen, pageIdx,
                                           pageCount);
                case 1: /* nominationpools_nominate_V1 - validators */;
                    return _toStringVecAccountId(&m->nested.nominationpools_nominate_V1.validators, outValue, outValueLen,
                                                 pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9225: /* module 36 call 9 */
            switch (itemIdx) {
                case 0: /* nominationpools_set_state_V1 - pool_id */;
                    return _toStringPoolId(&m->nested.nominationpools_set_state_V1.pool_id, outValue, outValueLen, pageIdx,
                                           pageCount);
                case 1: /* nominationpools_set_state_V1 - state */;
                    return _toStringPoolState(&m->nested.nominationpools_set_state_V1.state, outValue, outValueLen, pageIdx,
                                              pageCount);
                default:
                    return parser_no_data;
            }
        case 9226: /* module 36 call 10 */
            switch (itemIdx) {
                case 0: /* nominationpools_set_metadata_V1 - pool_id */;
                    return _toStringPoolId(&m->nested.nominationpools_set_metadata_V1.pool_id, outValue, outValueLen,
                                           pageIdx, pageCount);
                case 1: /* nominationpools_set_metadata_V1 - metadata */;
                    return _toStringVecu8(&m->nested.nominationpools_set_metadata_V1.metadata, outValue, outValueLen,
                                          pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9227: /* module 36 call 11 */
            switch (itemIdx) {
                case 0: /* nominationpools_set_configs_V1 - min_join_bond */;
                    return _toStringConfigOpBalanceOfT(&m->basic.nominationpools_set_configs_V1.min_join_bond, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 1: /* nominationpools_set_configs_V1 - min_create_bond */;
                    return _toStringConfigOpBalanceOfT(&m->basic.nominationpools_set_configs_V1.min_create_bond, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 2: /* nominationpools_set_configs_V1 - max_pools */;
                    return _toStringConfigOpu32(&m->basic.nominationpools_set_configs_V1.max_pools, outValue, outValueLen,
                                                pageIdx, pageCount);
                case 3: /* nominationpools_set_configs_V1 - max_members */;
                    return _toStringConfigOpu32(&m->basic.nominationpools_set_configs_V1.max_members, outValue, outValueLen,
                                                pageIdx, pageCount);
                case 4: /* nominationpools_set_configs_V1 - max_members_per_pool */;
                    return _toStringConfigOpu32(&m->basic.nominationpools_set_configs_V1.max_members_per_pool, outValue,
                                                outValueLen, pageIdx, pageCount);
                case 5: /* nominationpools_set_configs_V1 - global_max_commission */;
                    return _toStringConfigOpPerbill(&m->basic.nominationpools_set_configs_V1.global_max_commission, outValue,
                                                    outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9228: /* module 36 call 12 */
            switch (itemIdx) {
                case 0: /* nominationpools_update_roles_V1 - pool_id */;
                    return _toStringPoolId(&m->nested.nominationpools_update_roles_V1.pool_id, outValue, outValueLen,
                                           pageIdx, pageCount);
                case 1: /* nominationpools_update_roles_V1 - new_root */;
                    return _toStringConfigOpAccountId(&m->nested.nominationpools_update_roles_V1.new_root, outValue,
                                                      outValueLen, pageIdx, pageCount);
                case 2: /* nominationpools_update_roles_V1 - new_nominator */;
                    return _toStringConfigOpAccountId(&m->nested.nominationpools_update_roles_V1.new_nominator, outValue,
                                                      outValueLen, pageIdx, pageCount);
                case 3: /* nominationpools_update_roles_V1 - new_bouncer */;
                    return _toStringConfigOpAccountId(&m->nested.nominationpools_update_roles_V1.new_bouncer, outValue,
                                                      outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9229: /* module 36 call 13 */
            switch (itemIdx) {
                case 0: /* nominationpools_chill_V1 - pool_id */;
                    return _toStringPoolId(&m->nested.nominationpools_chill_V1.pool_id, outValue, outValueLen, pageIdx,
                                           pageCount);
                default:
                    return parser_no_data;
            }
        case 9230: /* module 36 call 14 */
            switch (itemIdx) {
                case 0: /* nominationpools_bond_extra_other_V1 - member */;
                    return _toStringAccountIdLookupOfT(&m->basic.nominationpools_bond_extra_other_V1.member, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 1: /* nominationpools_bond_extra_other_V1 - extra */;
                    return _toStringBondExtraBalanceOfT(&m->basic.nominationpools_bond_extra_other_V1.extra, outValue,
                                                        outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9231: /* module 36 call 15 */
            switch (itemIdx) {
                case 0: /* nominationpools_set_claim_permission_V1 - permission */;
                    return _toStringClaimPermission(&m->nested.nominationpools_set_claim_permission_V1.permission, outValue,
                                                    outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9232: /* module 36 call 16 */
            switch (itemIdx) {
                case 0: /* nominationpools_claim_payout_other_V1 - other */;
                    return _toStringAccountId(&m->nested.nominationpools_claim_payout_other_V1.other, outValue, outValueLen,
                                              pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9233: /* module 36 call 17 */
            switch (itemIdx) {
                case 0: /* nominationpools_set_commission_V1 - pool_id */;
                    return _toStringPoolId(&m->nested.nominationpools_set_commission_V1.pool_id, outValue, outValueLen,
                                           pageIdx, pageCount);
                case 1: /* nominationpools_set_commission_V1 - new_commission */;
                    return _toStringOptionTuplePerbillAccountId(&m->nested.nominationpools_set_commission_V1.new_commission,
                                                                outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9234: /* module 36 call 18 */
            switch (itemIdx) {
                case 0: /* nominationpools_set_commission_max_V1 - pool_id */;
                    return _toStringPoolId(&m->nested.nominationpools_set_commission_max_V1.pool_id, outValue, outValueLen,
                                           pageIdx, pageCount);
                case 1: /* nominationpools_set_commission_max_V1 - max_commission */;
                    return _toStringPerbill(&m->nested.nominationpools_set_commission_max_V1.max_commission, outValue,
                                            outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9235: /* module 36 call 19 */
            switch (itemIdx) {
                case 0: /* nominationpools_set_commission_change_rate_V1 - pool_id */;
                    return _toStringPoolId(&m->nested.nominationpools_set_commission_change_rate_V1.pool_id, outValue,
                                           outValueLen, pageIdx, pageCount);
                case 1: /* nominationpools_set_commission_change_rate_V1 - change_rate */;
                    return _toStringCommissionChangeRateBlockNumber(
                        &m->nested.nominationpools_set_commission_change_rate_V1.change_rate, outValue, outValueLen, pageIdx,
                        pageCount);
                default:
                    return parser_no_data;
            }
        case 9236: /* module 36 call 20 */
            switch (itemIdx) {
                case 0: /* nominationpools_claim_commission_V1 - pool_id */;
                    return _toStringPoolId(&m->nested.nominationpools_claim_commission_V1.pool_id, outValue, outValueLen,
                                           pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9237: /* module 36 call 21 */
            switch (itemIdx) {
                case 0: /* nominationpools_adjust_pool_deposit_V1 - pool_id */;
                    return _toStringPoolId(&m->basic.nominationpools_adjust_pool_deposit_V1.pool_id, outValue, outValueLen,
                                           pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9238: /* module 36 call 22 */
            switch (itemIdx) {
                case 0: /* nominationpools_set_commission_claim_permission_V1 - pool_id */;
                    return _toStringPoolId(&m->basic.nominationpools_set_commission_claim_permission_V1.pool_id, outValue,
                                           outValueLen, pageIdx, pageCount);
                case 1: /* nominationpools_set_commission_claim_permission_V1 - permission */;
                    return _toStringOptionCommissionClaimPermissionAccountId(
                        &m->basic.nominationpools_set_commission_claim_permission_V1.permission, outValue, outValueLen,
                        pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9473: /* module 37 call 1 */
            switch (itemIdx) {
                case 0: /* identity_set_identity_V1 - info */;
                    return _toStringIdentityInfo(&m->basic.identity_set_identity_V1.info, outValue, outValueLen, pageIdx,
                                                 pageCount);
                default:
                    return parser_no_data;
            }
        case 9475: /* module 37 call 3 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 9728: /* module 38 call 0 */
            switch (itemIdx) {
                case 0: /* mandate_mandate_V1 - call */;
                    return _toStringCall(&m->basic.mandate_mandate_V1.call, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9985: /* module 39 call 1 */
            switch (itemIdx) {
                case 0: /* vector_execute_V1 - slot */;
                    return _toStringCompactu64(&m->basic.vector_execute_V1.slot, outValue, outValueLen, pageIdx, pageCount);
                case 1: /* vector_execute_V1 - addr_message */;
                    return _toStringAddressedMessage(&m->basic.vector_execute_V1.addr_message, outValue, outValueLen,
                                                     pageIdx, pageCount);
                case 2: /* vector_execute_V1 - account_proof */;
                    return _toStringValidProof(&m->basic.vector_execute_V1.account_proof, outValue, outValueLen, pageIdx,
                                               pageCount);
                case 3: /* vector_execute_V1 - storage_proof */;
                    return _toStringValidProof(&m->basic.vector_execute_V1.storage_proof, outValue, outValueLen, pageIdx,
                                               pageCount);
                default:
                    return parser_no_data;
            }
        case 9987: /* module 39 call 3 */
            switch (itemIdx) {
                case 0: /* vector_send_message_V1 - message */;
                    return _toStringMessage(&m->basic.vector_send_message_V1.message, outValue, outValueLen, pageIdx,
                                            pageCount);
                case 1: /* vector_send_message_V1 - to */;
                    return _toStringH256(&m->basic.vector_send_message_V1.to, outValue, outValueLen, pageIdx, pageCount);
                case 2: /* vector_send_message_V1 - domain */;
                    return _toStringCompactu32(&m->basic.vector_send_message_V1.domain, outValue, outValueLen, pageIdx,
                                               pageCount);
                default:
                    return parser_no_data;
            }
        case 10240: /* module 40 call 0 */
            switch (itemIdx) {
                case 0: /* proxy_proxy_V1 - real */;
                    return _toStringAccountIdLookupOfT(&m->nested.proxy_proxy_V1.real, outValue, outValueLen, pageIdx,
                                                       pageCount);
                case 1: /* proxy_proxy_V1 - force_proxy_type */;
                    return _toStringOptionProxyType(&m->nested.proxy_proxy_V1.force_proxy_type, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 2: /* proxy_proxy_V1 - call */;
                    return _toStringCall(&m->nested.proxy_proxy_V1.call, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 10241: /* module 40 call 1 */
            switch (itemIdx) {
                case 0: /* proxy_add_proxy_V1 - delegate */;
                    return _toStringAccountIdLookupOfT(&m->nested.proxy_add_proxy_V1.delegate, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* proxy_add_proxy_V1 - proxy_type */;
                    return _toStringProxyType(&m->nested.proxy_add_proxy_V1.proxy_type, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 2: /* proxy_add_proxy_V1 - delay */;
                    return _toStringBlockNumber(&m->nested.proxy_add_proxy_V1.delay, outValue, outValueLen, pageIdx,
                                                pageCount);
                default:
                    return parser_no_data;
            }
        case 10242: /* module 40 call 2 */
            switch (itemIdx) {
                case 0: /* proxy_remove_proxy_V1 - delegate */;
                    return _toStringAccountIdLookupOfT(&m->nested.proxy_remove_proxy_V1.delegate, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* proxy_remove_proxy_V1 - proxy_type */;
                    return _toStringProxyType(&m->nested.proxy_remove_proxy_V1.proxy_type, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 2: /* proxy_remove_proxy_V1 - delay */;
                    return _toStringBlockNumber(&m->nested.proxy_remove_proxy_V1.delay, outValue, outValueLen, pageIdx,
                                                pageCount);
                default:
                    return parser_no_data;
            }
        default:
            return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V1(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 2563:  // Staking:Withdraw Unbonded
            switch (itemIdx) {
                case 0:  // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 2575:  // Staking:Force unstake
            switch (itemIdx) {
                case 1:  // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 2580:  // Staking:Reap stash
            switch (itemIdx) {
                case 1:  // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 9220:  // NominationPools:Pool withdraw unbonded
            switch (itemIdx) {
                case 1:  // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 9221:  // NominationPools:Withdraw Unbonded
            switch (itemIdx) {
                case 1:  // Num slashing spans
                    return true;
                default:
                    return false;
            }

        default:
            return false;
    }
}

bool _getMethod_IsNestingSupported_V1(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 9:     // System:Authorize upgrade
        case 10:    // System:Authorize upgrade without checks
        case 11:    // System:Apply authorized upgrade
        case 256:   // Utility:Batch
        case 258:   // Utility:Batch all
        case 260:   // Utility:Force batch
        case 261:   // Utility:With weight
        case 1541:  // Balances:Force unreserve
        case 1542:  // Balances:Upgrade accounts
        case 1544:  // Balances:Force set balance
        case 1545:  // Balances:Force adjust total issuance
        case 2569:  // Staking:Set validator count
        case 2570:  // Staking:Increase validator count
        case 2571:  // Staking:Scale validator count
        case 2572:  // Staking:Force no eras
        case 2573:  // Staking:Force new era
        case 2574:  // Staking:Set invulnerables
        case 2575:  // Staking:Force unstake
        case 2576:  // Staking:Force new era always
        case 2577:  // Staking:Cancel deferred slash
        case 2580:  // Staking:Reap stash
        case 2581:  // Staking:Kick
        case 2582:  // Staking:Set staking configs
        case 2583:  // Staking:Chill other
        case 2584:  // Staking:Force apply min commission
        case 2585:  // Staking:Set min commission
        case 2586:  // Staking:Payout stakers by page
        case 2587:  // Staking:Update payee
        case 3584:  // TechnicalCommittee:Set members
        case 3585:  // TechnicalCommittee:Execute
        case 3586:  // TechnicalCommittee:Propose
        case 3587:  // TechnicalCommittee:Vote
        case 4354:  // Grandpa:Note stalled
        case 6148:  // Scheduler:Schedule after
        case 7424:  // DataAvailability:Create application key
        case 7425:  // DataAvailability:Submit data
        case 7426:  // DataAvailability:Submit block length proposal
        case 7427:  // DataAvailability:Set application key
        case 7428:  // DataAvailability:Set submit data fee modifier
        case 9220:  // NominationPools:Pool withdraw unbonded
        case 9223:  // NominationPools:Create with pool id
        case 9227:  // NominationPools:Set configs
        case 9230:  // NominationPools:Bond extra other
        case 9237:  // NominationPools:Adjust pool deposit
        case 9238:  // NominationPools:Set commission claim permission
        case 9473:  // Identity:Set identity
        case 9475:  // Identity:Clear identity
        case 9728:  // Mandate:Mandate
        case 9985:  // Vector:Execute
        case 9987:  // Vector:Send message
            return false;
        default:
            return true;
    }
}
