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

// Modules names
static const char* STR_MO_SYSTEM = "System";
static const char* STR_MO_UTILITY = "Utility";
static const char* STR_MO_BALANCES = "Balances";
static const char* STR_MO_STAKING = "Staking";
static const char* STR_MO_SESSION = "Session";
static const char* STR_MO_TECHNICALCOMMITTEE = "Technicalcommittee";
static const char* STR_MO_GRANDPA = "Grandpa";
static const char* STR_MO_SCHEDULER = "Scheduler";
static const char* STR_MO_DATAAVAILABILITY = "Dataavailability";
static const char* STR_MO_MULTISIG = "Multisig";
static const char* STR_MO_NOMINATIONPOOLS = "Nominationpools";
static const char* STR_MO_IDENTITY = "Identity";
static const char* STR_MO_MANDATE = "Mandate";
static const char* STR_MO_VECTOR = "Vector";
static const char* STR_MO_PROXY = "Proxy";

// Methods names
static const char* STR_ME_REMARK = "Remark";
static const char* STR_ME_SET_HEAP_PAGES = "Set heap pages";
static const char* STR_ME_SET_CODE = "Set code";
static const char* STR_ME_SET_CODE_WITHOUT_CHECKS = "Set code without checks";
static const char* STR_ME_REMARK_WITH_EVENT = "Remark with event";
static const char* STR_ME_AUTHORIZE_UPGRADE = "Authorize upgrade";
static const char* STR_ME_AUTHORIZE_UPGRADE_WITHOUT_CHECKS = "Authorize upgrade without checks";
static const char* STR_ME_APPLY_AUTHORIZED_UPGRADE = "Apply authorized upgrade";
static const char* STR_ME_BATCH = "Batch";
static const char* STR_ME_BATCH_ALL = "Batch all";
static const char* STR_ME_FORCE_BATCH = "Force batch";
static const char* STR_ME_WITH_WEIGHT = "With weight";
static const char* STR_ME_TRANSFER_ALLOW_DEATH = "Transfer allow death";
static const char* STR_ME_FORCE_TRANSFER = "Force transfer";
static const char* STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char* STR_ME_TRANSFER_ALL = "Transfer all";
static const char* STR_ME_FORCE_UNRESERVE = "Force unreserve";
static const char* STR_ME_UPGRADE_ACCOUNTS = "Upgrade accounts";
static const char* STR_ME_FORCE_SET_BALANCE = "Force set balance";
static const char* STR_ME_FORCE_ADJUST_TOTAL_ISSUANCE = "Force adjust total issuance";
static const char* STR_ME_BOND = "Bond";
static const char* STR_ME_BOND_EXTRA = "Bond extra";
static const char* STR_ME_UNBOND = "Unbond";
static const char* STR_ME_WITHDRAW_UNBONDED = "Withdraw Unbonded";
static const char* STR_ME_VALIDATE = "Validate";
static const char* STR_ME_NOMINATE = "Nominate";
static const char* STR_ME_CHILL = "Chill";
static const char* STR_ME_SET_PAYEE = "Set payee";
static const char* STR_ME_SET_CONTROLLER = "Set controller";
static const char* STR_ME_SET_VALIDATOR_COUNT = "Set validator count";
static const char* STR_ME_INCREASE_VALIDATOR_COUNT = "Increase validator count";
static const char* STR_ME_SCALE_VALIDATOR_COUNT = "Scale validator count";
static const char* STR_ME_FORCE_NO_ERAS = "Force no eras";
static const char* STR_ME_FORCE_NEW_ERA = "Force new era";
static const char* STR_ME_SET_INVULNERABLES = "Set invulnerables";
static const char* STR_ME_FORCE_UNSTAKE = "Force unstake";
static const char* STR_ME_FORCE_NEW_ERA_ALWAYS = "Force new era always";
static const char* STR_ME_CANCEL_DEFERRED_SLASH = "Cancel deferred slash";
static const char* STR_ME_PAYOUT_STAKERS = "Payout stakers";
static const char* STR_ME_REBOND = "Rebond";
static const char* STR_ME_REAP_STASH = "Reap stash";
static const char* STR_ME_KICK = "Kick";
static const char* STR_ME_SET_STAKING_CONFIGS = "Set staking configs";
static const char* STR_ME_CHILL_OTHER = "Chill other";
static const char* STR_ME_FORCE_APPLY_MIN_COMMISSION = "Force apply min commission";
static const char* STR_ME_SET_MIN_COMMISSION = "Set min commission";
static const char* STR_ME_PAYOUT_STAKERS_BY_PAGE = "Payout stakers by page";
static const char* STR_ME_UPDATE_PAYEE = "Update payee";
static const char* STR_ME_SET_KEYS = "Set keys";
static const char* STR_ME_PURGE_KEYS = "Purge keys";
static const char* STR_ME_SET_MEMBERS = "Set members";
static const char* STR_ME_EXECUTE = "Execute";
static const char* STR_ME_PROPOSE = "Propose";
static const char* STR_ME_VOTE = "Vote";
static const char* STR_ME_NOTE_STALLED = "Note stalled";
static const char* STR_ME_SCHEDULE_AFTER = "Schedule after";
static const char* STR_ME_CREATE_APPLICATION_KEY = "Create application key";
static const char* STR_ME_SUBMIT_DATA = "Submit data";
static const char* STR_ME_SUBMIT_BLOCK_LENGTH_PROPOSAL = "Submit block length proposal";
static const char* STR_ME_SET_APPLICATION_KEY = "Set application key";
static const char* STR_ME_SET_SUBMIT_DATA_FEE_MODIFIER = "Set submit data fee modifier";
static const char* STR_ME_AS_MULTI_THRESHOLD_1 = "As multi threshold 1";
static const char* STR_ME_AS_MULTI = "As multi";
static const char* STR_ME_APPROVE_AS_MULTI = "Approve as multi";
static const char* STR_ME_CANCEL_AS_MULTI = "Cancel as multi";
static const char* STR_ME_JOIN = "Join";
static const char* STR_ME_CLAIM_PAYOUT = "Claim payout";
static const char* STR_ME_POOL_WITHDRAW_UNBONDED = "Pool withdraw unbonded";
static const char* STR_ME_CREATE = "Create";
static const char* STR_ME_CREATE_WITH_POOL_ID = "Create with pool id";
static const char* STR_ME_SET_STATE = "Set state";
static const char* STR_ME_SET_METADATA = "Set metadata";
static const char* STR_ME_SET_CONFIGS = "Set configs";
static const char* STR_ME_UPDATE_ROLES = "Update roles";
static const char* STR_ME_BOND_EXTRA_OTHER = "Bond extra other";
static const char* STR_ME_SET_CLAIM_PERMISSION = "Set claim permission";
static const char* STR_ME_CLAIM_PAYOUT_OTHER = "Claim payout other";
static const char* STR_ME_SET_COMMISSION = "Set commission";
static const char* STR_ME_SET_COMMISSION_MAX = "Set commission max";
static const char* STR_ME_SET_COMMISSION_CHANGE_RATE = "Set commission change rate";
static const char* STR_ME_CLAIM_COMMISSION = "Claim commission";
static const char* STR_ME_ADJUST_POOL_DEPOSIT = "Adjust pool deposit";
static const char* STR_ME_SET_COMMISSION_CLAIM_PERMISSION = "Set commission claim permission";
static const char* STR_ME_SET_IDENTITY = "Set identity";
static const char* STR_ME_CLEAR_IDENTITY = "Clear identity";
static const char* STR_ME_MANDATE = "Mandate";
static const char* STR_ME_SEND_MESSAGE = "Send message";
static const char* STR_ME_PROXY = "Proxy";
static const char* STR_ME_ADD_PROXY = "Add proxy";
static const char* STR_ME_REMOVE_PROXY = "Remove proxy";

// Items names
static const char* STR_IT_remark = "Remark";
static const char* STR_IT_pages = "Pages";
static const char* STR_IT_code = "Code";
static const char* STR_IT_items = "Items";
static const char* STR_IT_keys = "Keys";
static const char* STR_IT_prefix = "Prefix";
static const char* STR_IT_subkeys = "Subkeys";
static const char* STR_IT_code_hash = "Code hash";
static const char* STR_IT_calls = "Calls";
static const char* STR_IT_index = "Index";
static const char* STR_IT_call = "Call";
static const char* STR_IT_as_origin = "As origin";
static const char* STR_IT_weight = "Weight";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_source = "Source";
static const char* STR_IT_keep_alive = "Keep alive";
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_direction = "Direction";
static const char* STR_IT_delta = "Delta";
static const char* STR_IT_payee = "Payee";
static const char* STR_IT_num_slashing_spans = "Num slashing spans";
static const char* STR_IT_prefs = "Prefs";
static const char* STR_IT_targets = "Targets";
static const char* STR_IT_new_ = "New";
static const char* STR_IT_additional = "Additional";
static const char* STR_IT_factor = "Factor";
static const char* STR_IT_invulnerables = "Invulnerables";
static const char* STR_IT_stash = "Stash";
static const char* STR_IT_era = "Era";
static const char* STR_IT_slash_indices = "Slash indices";
static const char* STR_IT_validator_stash = "Validator stash";
static const char* STR_IT_min_nominator_bond = "Min nominator bond";
static const char* STR_IT_min_validator_bond = "Min validator bond";
static const char* STR_IT_max_nominator_count = "Max nominator count";
static const char* STR_IT_max_validator_count = "Max validator count";
static const char* STR_IT_chill_threshold = "Chill threshold";
static const char* STR_IT_min_commission = "Min commission";
static const char* STR_IT_page = "Page";
static const char* STR_IT_controller = "Controller";
static const char* STR_IT_controllers = "Controllers";
static const char* STR_IT_proof = "Proof";
static const char* STR_IT_new_members = "New members";
static const char* STR_IT_prime = "Prime";
static const char* STR_IT_old_count = "Old count";
static const char* STR_IT_proposal = "Proposal";
static const char* STR_IT_length_bound = "Length bound";
static const char* STR_IT_threshold = "Threshold";
static const char* STR_IT_approve = "Approve";
static const char* STR_IT_proposal_hash = "Proposal hash";
static const char* STR_IT_proposal_weight_bound = "Proposal weight bound";
static const char* STR_IT_equivocation_proof = "Equivocation proof";
static const char* STR_IT_key_owner_proof = "Key owner proof";
static const char* STR_IT_delay = "Delay";
static const char* STR_IT_best_finalized_block_number = "Best finalized block number";
static const char* STR_IT_when = "When";
static const char* STR_IT_maybe_periodic = "Maybe periodic";
static const char* STR_IT_priority = "Priority";
static const char* STR_IT_id = "Id";
static const char* STR_IT_after = "After";
static const char* STR_IT_key = "Key";
static const char* STR_IT_data = "Data";
static const char* STR_IT_rows = "Rows";
static const char* STR_IT_cols = "Cols";
static const char* STR_IT_old_key = "Old key";
static const char* STR_IT_new_key = "New key";
static const char* STR_IT_modifier = "Modifier";
static const char* STR_IT_other_signatories = "Other signatories";
static const char* STR_IT_maybe_timepoint = "Maybe timepoint";
static const char* STR_IT_max_weight = "Max weight";
static const char* STR_IT_call_hash = "Call hash";
static const char* STR_IT_timepoint = "Timepoint";
static const char* STR_IT_pool_id = "Pool id";
static const char* STR_IT_extra = "Extra";
static const char* STR_IT_member_account = "Member account";
static const char* STR_IT_unbonding_points = "Unbonding points";
static const char* STR_IT_root = "Root";
static const char* STR_IT_nominator = "Nominator";
static const char* STR_IT_bouncer = "Bouncer";
static const char* STR_IT_validators = "Validators";
static const char* STR_IT_state = "State";
static const char* STR_IT_metadata = "Metadata";
static const char* STR_IT_min_join_bond = "Min join bond";
static const char* STR_IT_min_create_bond = "Min create bond";
static const char* STR_IT_max_pools = "Max pools";
static const char* STR_IT_max_members = "Max members";
static const char* STR_IT_max_members_per_pool = "Max members per pool";
static const char* STR_IT_global_max_commission = "Global max commission";
static const char* STR_IT_new_root = "New root";
static const char* STR_IT_new_nominator = "New nominator";
static const char* STR_IT_new_bouncer = "New bouncer";
static const char* STR_IT_member = "Member";
static const char* STR_IT_permission = "Permission";
static const char* STR_IT_other = "Other";
static const char* STR_IT_new_commission = "New commission";
static const char* STR_IT_max_commission = "Max commission";
static const char* STR_IT_change_rate = "Change rate";
static const char* STR_IT_account = "Account";
static const char* STR_IT_info = "Info";
static const char* STR_IT_subs = "Subs";
static const char* STR_IT_reg_index = "Reg index";
static const char* STR_IT_max_fee = "Max fee";
static const char* STR_IT_fee = "Fee";
static const char* STR_IT_fields = "Fields";
static const char* STR_IT_target = "Target";
static const char* STR_IT_judgement = "Judgement";
static const char* STR_IT_identity = "Identity";
static const char* STR_IT_sub = "Sub";
static const char* STR_IT_authority = "Authority";
static const char* STR_IT_suffix = "Suffix";
static const char* STR_IT_allocation = "Allocation";
static const char* STR_IT_username = "Username";
static const char* STR_IT_signature = "Signature";
static const char* STR_IT_function_id = "Function id";
static const char* STR_IT_input = "Input";
static const char* STR_IT_output = "Output";
static const char* STR_IT_slot = "Slot";
static const char* STR_IT_addr_message = "Addr message";
static const char* STR_IT_account_proof = "Account proof";
static const char* STR_IT_storage_proof = "Storage proof";
static const char* STR_IT_source_chain_id = "Source chain id";
static const char* STR_IT_frozen = "Frozen";
static const char* STR_IT_message = "Message";
static const char* STR_IT_to = "To";
static const char* STR_IT_domain = "Domain";
static const char* STR_IT_period = "Period";
static const char* STR_IT_poseidon_hash = "Poseidon hash";
static const char* STR_IT_broadcaster_domain = "Broadcaster domain";
static const char* STR_IT_broadcaster = "Broadcaster";
static const char* STR_IT_value = "Value";
static const char* STR_IT_failed_txs = "Failed txs";
static const char* STR_IT_updater = "Updater";
static const char* STR_IT_real = "Real";
static const char* STR_IT_force_proxy_type = "Force proxy type";
static const char* STR_IT_delegate = "Delegate";
static const char* STR_IT_proxy_type = "Proxy type";
static const char* STR_IT_spawner = "Spawner";
static const char* STR_IT_height = "Height";
static const char* STR_IT_ext_index = "Ext index";

#ifdef __cplusplus
}
#endif
