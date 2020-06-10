/* This is algorand's implementation of Pointproofs */

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#if !defined(GROUP_SWITCHED)
#define COMMIT_LEN 49
#endif

#if defined(GROUP_SWITCHED)
#define COMMIT_LEN 97
#endif

#if !defined(GROUP_SWITCHED)
#define POINTPROOFSG1_LEN 48
#endif

#if defined(GROUP_SWITCHED)
#define POINTPROOFSG1_LEN 96
#endif

#if !defined(GROUP_SWITCHED)
#define POINTPROOFSG2_LEN 96
#endif

#if defined(GROUP_SWITCHED)
#define POINTPROOFSG2_LEN 48
#endif

#if !defined(GROUP_SWITCHED)
#define PP_LEN 98313
#endif

#if defined(GROUP_SWITCHED)
#define PP_LEN 196617
#endif

#if !defined(GROUP_SWITCHED)
#define PROOF_LEN 49
#endif

#if defined(GROUP_SWITCHED)
#define PROOF_LEN 97
#endif

#if !defined(GROUP_SWITCHED)
#define VP_LEN 98889
#endif

#if defined(GROUP_SWITCHED)
#define VP_LEN 49737
#endif

/**
 * deserialized prover parameter struct
 */
typedef struct pointproofs_pp {
  void *data;
} pointproofs_pp;

/**
 * values
 */
typedef struct pointproofs_value {
  const uint8_t *data;
  size_t len;
} pointproofs_value;

/**
 * deserialized commitment struct
 */
typedef struct pointproofs_commitment {
  void *data;
} pointproofs_commitment;

/**
 * serialized commitment struct
 */
typedef struct pointproofs_commitment_bytes {
  uint8_t data[COMMIT_LEN];
} pointproofs_commitment_bytes;

/**
 * deserialized proof struct
 */
typedef struct pointproofs_proof {
  void *data;
} pointproofs_proof;

/**
 * deserialized verifier parameter struct
 */
typedef struct pointproofs_vp {
  void *data;
} pointproofs_vp;

/**
 * non-serialized
 */
typedef struct pointproofs_params {
  pointproofs_pp prover;
  pointproofs_vp verifier;
} pointproofs_params;

/**
 * serialized prover parameter struct
 */
typedef struct pointproofs_pp_bytes {
  uint8_t data[PP_LEN];
} pointproofs_pp_bytes;

/**
 * serialized proof struct
 */
typedef struct pointproofs_proof_bytes {
  uint8_t data[PROOF_LEN];
} pointproofs_proof_bytes;

/**
 * serialized verifer parameter struct
 */
typedef struct pointproofs_vp_bytes {
  uint8_t data[VP_LEN];
} pointproofs_vp_bytes;

/**
 * Generate a commitment
 */
int32_t pointproofs_commit(pointproofs_pp prover,
                           const pointproofs_value *values,
                           uintptr_t n,
                           pointproofs_commitment *commit);

/**
 * Deserializeing bytes into commitments
 */
int32_t pointproofs_commit_deserial(pointproofs_commitment_bytes commit_bytes,
                                    pointproofs_commitment *commit);

/**
 * Serializing commitments into bytes
 */
int32_t pointproofs_commit_serial(pointproofs_commitment commit,
                                  pointproofs_commitment_bytes *bytes);

/**
 * update an existing commitment
 */
int32_t pointproofs_commit_update(pointproofs_pp prover,
                                  pointproofs_commitment com,
                                  size_t changed_idx,
                                  pointproofs_value val_old,
                                  pointproofs_value val_new,
                                  pointproofs_commitment *new_com);

/**
 * Free commitment
 */
void pointproofs_free_commit(pointproofs_commitment commit);

/**
 * Free proof
 */
void pointproofs_free_proof(pointproofs_proof proof);

/**
 * Free prover parameter
 */
void pointproofs_free_prover_params(pointproofs_pp pp);

/**
 * Free verifier parameter
 */
void pointproofs_free_verifier_params(pointproofs_vp vp);

/**
 * Generating a pair of parameters
 */
int32_t pointproofs_paramgen(const uint8_t *seedbuf,
                             size_t seedlen,
                             uint8_t ciphersuite,
                             size_t n,
                             pointproofs_params *param);

int32_t pointproofs_pp_deserial(pointproofs_pp_bytes pprover, pointproofs_pp *prover);

/**
 * Serializing a prove parameter into bytes
 */
int32_t pointproofs_pp_serial(pointproofs_pp pprover, pointproofs_pp_bytes *bytes);

/**
 * Deserializeing bytes into proofs
 */
int32_t pointproofs_proof_deserial(pointproofs_proof_bytes proof_bytes, pointproofs_proof *proof);

/**
 * Serializing proofs into bytes
 */
int32_t pointproofs_proof_serial(pointproofs_proof proof, pointproofs_proof_bytes *bytes);

/**
 * update an existing proof
 */
int32_t pointproofs_proof_update(pointproofs_pp prover,
                                 pointproofs_proof proof,
                                 size_t idx,
                                 size_t changed_idx,
                                 pointproofs_value val_old,
                                 pointproofs_value val_new,
                                 pointproofs_proof *new_proof);

/**
 * Generate a proof
 */
int32_t pointproofs_prove(pointproofs_pp prover,
                          const pointproofs_value *values,
                          uintptr_t n,
                          size_t idx,
                          pointproofs_proof *proof);

/**
 * aggregate proofs within a same commitment
 */
int32_t pointproofs_same_commit_aggregate(pointproofs_commitment com,
                                          const pointproofs_proof *proofs,
                                          const size_t *set,
                                          const pointproofs_value *values,
                                          size_t nvalues,
                                          size_t param_n,
                                          pointproofs_proof *agg_proof);

/**
 * verify an aggregated proof within a same commitment
 */
bool pointproofs_same_commit_batch_verify(pointproofs_vp verifier,
                                          pointproofs_commitment com,
                                          pointproofs_proof proof,
                                          const size_t *set,
                                          const pointproofs_value *values,
                                          size_t nvalues);

/**
 * verify the proof against the value and commitment
 */
bool pointproofs_verify(pointproofs_vp verifier,
                        pointproofs_commitment com,
                        pointproofs_proof proof,
                        pointproofs_value value,
                        size_t idx);

int32_t pointproofs_vp_deserial(pointproofs_vp_bytes pverifier, pointproofs_vp *verifier);

/**
 * Serializing a prove parameter into bytes
 */
int32_t pointproofs_vp_serial(pointproofs_vp pverifier, pointproofs_vp_bytes *bytes);

/**
 * aggregated proofs cross commitments
 */
int32_t pointproofs_x_commit_aggregate_full(const pointproofs_commitment *com,
                                            const pointproofs_proof *proof,
                                            const size_t *set,
                                            const pointproofs_value *values,
                                            const size_t *commit_indices,
                                            size_t no_commits,
                                            size_t param_n,
                                            pointproofs_proof *x_proof);

/**
 * aggregated proofs cross commitments
 */
int32_t pointproofs_x_commit_aggregate_partial(const pointproofs_commitment *com,
                                               const pointproofs_proof *agg_proof,
                                               const size_t *set,
                                               const pointproofs_value *values,
                                               const size_t *commit_indices,
                                               size_t no_commits,
                                               size_t param_n,
                                               pointproofs_proof *x_proof);

/**
 * verify an aggregated proof across commitments
 */
bool pointproofs_x_commit_batch_verify(pointproofs_vp verifier,
                                       const pointproofs_commitment *com,
                                       pointproofs_proof proof,
                                       const size_t *set,
                                       const pointproofs_value *values,
                                       const size_t *commit_indices,
                                       size_t no_commits);
