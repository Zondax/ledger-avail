# Avail 1.39.x

## System

| Name                             | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                         |
| -------------------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Remark                           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Set heap pages                   |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`pages<br/>                   |
| Set code                         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`code<br/>                  |
| Set code without checks          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set storage                      |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage                     |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix                      |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Authorize upgrade                |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Hash`code_hash<br/>              |
| Authorize upgrade without checks |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Hash`code_hash<br/>              |
| Apply authorized upgrade         |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Vecu8`code<br/>                  |

## Utility

| Name          | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                       |
| ------------- | ------------------ | ------------------ | ------------------ | ------- | ----------------------------------------------- |
| Batch         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| As derivative |                    |                    |                    |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| Dispatch as   |                    |                    |                    |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| With weight   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>`Weight`weight<br/>              |

## Babe

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                              |
| ---------------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofHeader`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofHeader`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Plan config change           |        |           |                  |         | `NextConfigDescriptor`config<br/>                                                      |

## Timestamp

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ---- | ------ | --------- | ---------------- | ------- | -------------------- |
| Set  |        |           |                  |         | `Compactu64`now<br/> |

## Indices

| Name           | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                               |
| -------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------- |
| Claim          |        |           |                  |         | `AccountIndex`index<br/>                                                |
| Transfer       |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>`AccountIndex`index<br/>                  |
| Free           |        |           |                  |         | `AccountIndex`index<br/>                                                |
| Force transfer |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>`AccountIndex`index<br/>`bool`freeze<br/> |
| Freeze         |        |           |                  |         | `AccountIndex`index<br/>                                                |

## Balances

| Name                        | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                               |
| --------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------- |
| Transfer allow death        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Force transfer              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/> |
| Transfer keep alive         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Transfer all                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                      |
| Force unreserve             |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                        |
| Upgrade accounts            |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`who<br/>                                                                  |
| Force set balance           |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>                               |
| Force adjust total issuance |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AdjustmentDirection`direction<br/>`CompactBalance`delta<br/>                           |

## ElectionProviderMultiPhase

| Name                          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                  |
| ----------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------ |
| Submit unsigned               |        |           |                  |         | `BoxRawSolutionSolutionOfMinerConfig`raw_solution<br/>`SolutionOrSnapshotSize`witness<br/> |
| Set minimum untrusted score   |        |           |                  |         | `OptionElectionScore`maybe_next_score<br/>                                                 |
| Set emergency election result |        |           |                  |         | `SupportsAccountId`supports<br/>                                                           |
| Submit                        |        |           |                  |         | `BoxRawSolutionSolutionOfMinerConfig`raw_solution<br/>                                     |
| Governance fallback           |        |           |                  |         | `Optionu32`maybe_max_voters<br/>`Optionu32`maybe_max_targets<br/>                          |

## Staking

| Name                       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                                                 |
| -------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Bond                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`RewardDestination`payee<br/>                                                                                                                                                                                  |
| Bond extra                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Unbond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Withdraw Unbonded          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`num_slashing_spans<br/>                                                                                                                                                                                                              |
| Validate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ValidatorPrefs`prefs<br/>                                                                                                                                                                                                                |
| Nominate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountIdLookupOfT`targets<br/>                                                                                                                                                                                                       |
| Chill                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Set payee                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `RewardDestination`payee<br/>                                                                                                                                                                                                             |
| Set controller             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Set validator count        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`new\_<br/>                                                                                                                                                                                                                    |
| Increase validator count   |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`additional<br/>                                                                                                                                                                                                               |
| Scale validator count      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Percent`factor<br/>                                                                                                                                                                                                                      |
| Force no eras              |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Force new era              |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Set invulnerables          |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`invulnerables<br/>                                                                                                                                                                                                          |
| Force unstake              |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Force new era always       |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Cancel deferred slash      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `EraIndex`era<br/>`Vecu32`slash_indices<br/>                                                                                                                                                                                              |
| Payout stakers             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`validator_stash<br/>`EraIndex`era<br/>                                                                                                                                                                                         |
| Rebond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Reap stash                 |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Kick                       |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountIdLookupOfT`who<br/>                                                                                                                                                                                                           |
| Set staking configs        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `ConfigOpBalanceOfT`min_nominator_bond<br/>`ConfigOpBalanceOfT`min_validator_bond<br/>`ConfigOpu32`max_nominator_count<br/>`ConfigOpu32`max_validator_count<br/>`ConfigOpPercent`chill_threshold<br/>`ConfigOpPerbill`min_commission<br/> |
| Chill other                |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>                                                                                                                                                                                                                     |
| Force apply min commission |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`validator_stash<br/>                                                                                                                                                                                                           |
| Set min commission         |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Perbill`new\_<br/>                                                                                                                                                                                                                       |
| Payout stakers by page     |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`validator_stash<br/>`EraIndex`era<br/>`Page`page<br/>                                                                                                                                                                          |
| Update payee               |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`controller<br/>                                                                                                                                                                                                                |
| Deprecate controller batch |                    |                    |                    |                    | `BoundedVecAccountIdMaxControllersInDeprecationBatch`controllers<br/>                                                                                                                                                                     |

## Session

| Name       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                        |
| ---------- | ------------------ | ------------------ | ------------------ | ------------------ | -------------------------------- |
| Set keys   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                  |

## TechnicalCommittee

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                     |
| ------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------- |
| Set members         |        |           |                  |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                          |
| Execute             |        |           |                  |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                          |
| Propose             |        |           |                  |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                |
| Vote                |        |           |                  |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                   |
| Disapprove proposal |        |           |                  |         | `Hash`proposal_hash<br/>                                                                                      |
| Close               |        |           |                  |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |

## Grandpa

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                       |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Note stalled                 |        |           |                  |         | `BlockNumber`delay<br/>`BlockNumber`best_finalized_block_number<br/>                            |

## Treasury

| Name             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                          |
| ---------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| Propose spend    |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/>                                                                    |
| Reject proposal  |        |           |                  |         | `Compactu32`proposal_id<br/>                                                                                                       |
| Approve proposal |        |           |                  |         | `Compactu32`proposal_id<br/>                                                                                                       |
| Spend local      |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/>                                                                    |
| Remove approval  |        |           |                  |         | `Compactu32`proposal_id<br/>                                                                                                       |
| Spend            |        |           |                  |         | `BoxAssetKind`asset_kind<br/>`CompactBalance`amount<br/>`BoxBeneficiaryLookupOf`beneficiary<br/>`OptionBlockNumber`valid_from<br/> |
| Payout           |        |           |                  |         | `SpendIndex`index<br/>                                                                                                             |
| Check status     |        |           |                  |         | `SpendIndex`index<br/>                                                                                                             |
| Void spend       |        |           |                  |         | `SpendIndex`index<br/>                                                                                                             |

## Sudo

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                   |
| --------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------- |
| Sudo                  |        |           |                  |         | `Call`call<br/>                             |
| Sudo unchecked weight |        |           |                  |         | `Call`call<br/>`Weight`weight<br/>          |
| Set key               |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>              |
| Sudo as               |        |           |                  |         | `AccountIdLookupOfT`who<br/>`Call`call<br/> |
| Remove key            |        |           |                  |         |                                             |

## ImOnline

| Name      | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                  |
| --------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------ |
| Heartbeat |        |           |                  |         | `HeartbeatBlockNumber`heartbeat<br/>`AuthorityIdasRuntimeAppPublicSignature`signature<br/> |

## Scheduler

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                  |
| -------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| Schedule             |        |           |                  |         | `BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                   |
| Cancel               |        |           |                  |         | `BlockNumber`when<br/>`u32`index<br/>                                                                                                      |
| Schedule named       |        |           |                  |         | `TaskName`id<br/>`BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>  |
| Cancel named         |        |           |                  |         | `TaskName`id<br/>                                                                                                                          |
| Schedule after       |        |           |                  |         | `BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                  |
| Schedule named after |        |           |                  |         | `TaskName`id<br/>`BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/> |

## DataAvailability

| Name                         | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                |
| ---------------------------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------- |
| Create application key       |        | :heavy_check_mark: | :heavy_check_mark: |         | `AppKey`key<br/>                         |
| Submit data                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `AppData`data<br/>                       |
| Submit block length proposal |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`rows<br/>`u32`cols<br/>             |
| Set application key          |        | :heavy_check_mark: | :heavy_check_mark: |         | `AppKey`old_key<br/>`AppKey`new_key<br/> |
| Set submit data fee modifier |        | :heavy_check_mark: | :heavy_check_mark: |         | `DispatchFeeModifier`modifier<br/>       |

## Preimage

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ------------------ | ------ | --------- | ---------------- | ------- | -------------------- |
| Note preimage      |        |           |                  |         | `Vecu8`bytes<br/>    |
| Unnote preimage    |        |           |                  |         | `Hash`hash<br/>      |
| Request preimage   |        |           |                  |         | `Hash`hash<br/>      |
| Unrequest preimage |        |           |                  |         | `Hash`hash<br/>      |
| Ensure updated     |        |           |                  |         | `VecHash`hashes<br/> |

## Multisig

| Name                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                               |
| -------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## VoterList

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                        |
| --------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------- |
| Rebag                 |        |           |                  |         | `AccountIdLookupOfT`dislocated<br/>                              |
| Put in front of       |        |           |                  |         | `AccountIdLookupOfT`lighter<br/>                                 |
| Put in front of other |        |           |                  |         | `AccountIdLookupOfT`heavier<br/>`AccountIdLookupOfT`lighter<br/> |

## NominationPools

| Name                            | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                               |
| ------------------------------- | ------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Join                            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`PoolId`pool_id<br/>                                                                                                                                                                         |
| Bond extra                      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BondExtraBalanceOfT`extra<br/>                                                                                                                                                                                         |
| Claim payout                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                         |
| Unbond                          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`member_account<br/>`CompactBalance`unbonding_points<br/>                                                                                                                                            |
| Pool withdraw unbonded          |        | :heavy_check_mark: | :heavy_check_mark: |                    | `PoolId`pool_id<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                        |
| Withdraw Unbonded               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`member_account<br/>`u32`num_slashing_spans<br/>                                                                                                                                                     |
| Create                          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`bouncer<br/>                                                                                              |
| Create with pool id             |        | :heavy_check_mark: | :heavy_check_mark: |                    | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`bouncer<br/>`PoolId`pool_id<br/>                                                                          |
| Nominate                        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`VecAccountId`validators<br/>                                                                                                                                                                       |
| Set state                       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`PoolState`state<br/>                                                                                                                                                                               |
| Set metadata                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`Vecu8`metadata<br/>                                                                                                                                                                                |
| Set configs                     |        | :heavy_check_mark: | :heavy_check_mark: |                    | `ConfigOpBalanceOfT`min_join_bond<br/>`ConfigOpBalanceOfT`min_create_bond<br/>`ConfigOpu32`max_pools<br/>`ConfigOpu32`max_members<br/>`ConfigOpu32`max_members_per_pool<br/>`ConfigOpPerbill`global_max_commission<br/> |
| Update roles                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`ConfigOpAccountId`new_root<br/>`ConfigOpAccountId`new_nominator<br/>`ConfigOpAccountId`new_bouncer<br/>                                                                                            |
| Chill                           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Bond extra other                |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`member<br/>`BondExtraBalanceOfT`extra<br/>                                                                                                                                                          |
| Set claim permission            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ClaimPermission`permission<br/>                                                                                                                                                                                        |
| Claim payout other              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`other<br/>                                                                                                                                                                                                   |
| Set commission                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`OptionTuplePerbillAccountId`new_commission<br/>                                                                                                                                                    |
| Set commission max              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`Perbill`max_commission<br/>                                                                                                                                                                        |
| Set commission change rate      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`CommissionChangeRateBlockNumber`change_rate<br/>                                                                                                                                                   |
| Claim commission                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Adjust pool deposit             |        | :heavy_check_mark: | :heavy_check_mark: |                    | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Set commission claim permission |        | :heavy_check_mark: | :heavy_check_mark: |                    | `PoolId`pool_id<br/>`OptionCommissionClaimPermissionAccountId`permission<br/>                                                                                                                                           |

## Identity

| Name                      | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                       |
| ------------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------- |
| Add registrar             |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                                                                |
| Set identity              |        |           |                  |         | `IdentityInfo`info<br/>                                                                                         |
| Set subs                  |        |           |                  |         | `VecTupleAccountIdData`subs<br/>                                                                                |
| Clear identity            |        |           |                  |         |                                                                                                                 |
| Request judgement         |        |           |                  |         | `Compactu32`reg_index<br/>`Compactu128`max_fee<br/>                                                             |
| Cancel request            |        |           |                  |         | `RegistrarIndex`reg_index<br/>                                                                                  |
| Set fee                   |        |           |                  |         | `Compactu32`index<br/>`Compactu128`fee<br/>                                                                     |
| Set account id            |        |           |                  |         | `Compactu32`index<br/>`AccountIdLookupOfT`new\_<br/>                                                            |
| Set fields                |        |           |                  |         | `Compactu32`index<br/>`IdentityInformationasIdentityInformationProviderFieldsIdentifier`fields<br/>             |
| Provide judgement         |        |           |                  |         | `Compactu32`reg_index<br/>`AccountIdLookupOfT`target<br/>`JudgementBalanceOfT`judgement<br/>`Hash`identity<br/> |
| Kill identity             |        |           |                  |         | `AccountIdLookupOfT`target<br/>                                                                                 |
| Add sub                   |        |           |                  |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Rename sub                |        |           |                  |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Remove sub                |        |           |                  |         | `AccountIdLookupOfT`sub<br/>                                                                                    |
| Quit sub                  |        |           |                  |         |                                                                                                                 |
| Add username authority    |        |           |                  |         | `AccountIdLookupOfT`authority<br/>`Vecu8`suffix<br/>`u32`allocation<br/>                                        |
| Remove username authority |        |           |                  |         | `AccountIdLookupOfT`authority<br/>                                                                              |
| Set username for          |        |           |                  |         | `AccountIdLookupOfT`who<br/>`Vecu8`username<br/>`OptionOffchainSignature`signature<br/>                         |
| Accept username           |        |           |                  |         | `UsernameT`username<br/>                                                                                        |
| Remove expired approval   |        |           |                  |         | `UsernameT`username<br/>                                                                                        |
| Set primary username      |        |           |                  |         | `UsernameT`username<br/>                                                                                        |
| Remove dangling username  |        |           |                  |         | `UsernameT`username<br/>                                                                                        |

## Mandate

| Name    | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments       |
| ------- | ------ | --------- | ---------------- | ------- | --------------- |
| Mandate |        |           |                  |         | `Call`call<br/> |

## Vector

| Name                        | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                |
| --------------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------------------ |
| Fulfill call                |        |                    |                    |         | `H256`function_id<br/>`FunctionInput`input<br/>`FunctionOutput`output<br/>`FunctionProof`proof<br/>`Compactu64`slot<br/> |
| Execute                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu64`slot<br/>`AddressedMessage`addr_message<br/>`ValidProof`account_proof<br/>`ValidProof`storage_proof<br/>     |
| Source chain froze          |        |                    |                    |         | `Compactu32`source_chain_id<br/>`bool`frozen<br/>                                                                        |
| Send message                |        | :heavy_check_mark: | :heavy_check_mark: |         | `Message`message<br/>`H256`to<br/>`Compactu32`domain<br/>                                                                |
| Set poseidon hash           |        |                    |                    |         | `Compactu64`period<br/>`BoundedVecu8`poseidon_hash<br/>                                                                  |
| Set broadcaster             |        |                    |                    |         | `Compactu32`broadcaster_domain<br/>`H256`broadcaster<br/>                                                                |
| Set whitelisted domains     |        |                    |                    |         | `BoundedVecu32ConstU3210_000`value<br/>                                                                                  |
| Set configuration           |        |                    |                    |         | `Configuration`value<br/>                                                                                                |
| Set function ids            |        |                    |                    |         | `OptionTupleH256H256`value<br/>                                                                                          |
| Set step verification key   |        |                    |                    |         | `OptionBoundedVecu8ConstU3210_000`value<br/>                                                                             |
| Set rotate verification key |        |                    |                    |         | `OptionBoundedVecu8ConstU3210_000`value<br/>                                                                             |
| Failed send message txs     |        |                    |                    |         | `VecCompactu32`failed_txs<br/>                                                                                           |
| Set updater                 |        |                    |                    |         | `H256`updater<br/>                                                                                                       |

## Proxy

| Name                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                  |
| ------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------- |
| Proxy               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>                                         |
| Add proxy           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxy        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxies      |        |                    |                    |                    |                                                                                                                            |
| Create pure         |        |                    |                    |                    | `ProxyType`proxy_type<br/>`BlockNumber`delay<br/>`u16`index<br/>                                                           |
| Kill pure           |        |                    |                    |                    | `AccountIdLookupOfT`spawner<br/>`ProxyType`proxy_type<br/>`u16`index<br/>`Compactu32`height<br/>`Compactu32`ext_index<br/> |
| Announce            |        |                    |                    |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Remove announcement |        |                    |                    |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Reject announcement |        |                    |                    |                    | `AccountIdLookupOfT`delegate<br/>`CallHashOf`call_hash<br/>                                                                |
| Proxy announced     |        |                    |                    |                    | `AccountIdLookupOfT`delegate<br/>`AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>        |

## TxPause

| Name    | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                          |
| ------- | ------ | --------- | ---------------- | ------- | ---------------------------------- |
| Pause   |        |           |                  |         | `RuntimeCallNameOfT`full_name<br/> |
| Unpause |        |           |                  |         | `RuntimeCallNameOfT`ident<br/>     |

## TreasuryCommittee

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                     |
| ------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------- |
| Set members         |        |           |                  |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                          |
| Execute             |        |           |                  |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                          |
| Propose             |        |           |                  |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                |
| Vote                |        |           |                  |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                   |
| Disapprove proposal |        |           |                  |         | `Hash`proposal_hash<br/>                                                                                      |
| Close               |        |           |                  |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |
