/*
 * Copyright (c) 2019-2021, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_internal_trusted_storage.h"

#include "tfm_hal_its.h"
#include "tfm_hal_ps.h"
#include "flash/its_flash.h"
#include "flash_fs/its_flash_fs.h"
#include "psa_manifest/pid.h"
#include "tfm_memory_utils.h"
#include "tfm_its_defs.h"
#include "tfm_its_req_mngr.h"
#include "its_utils.h"
#include "tfm_sp_log.h"

/**
 * \brief Perform encryption/decryption of the buffer using the
 *        tfm_hal_its_aead APIs
 *
 * \param[in]   finfo         Pointer to \ref its_flash_fs_file_info_t
 * \param[in]   fid           File identifier
 * \param[in]   fid_size      File identifier size in bytes
 * \param[in]   input         Input buffer
 * \param[in]   input_size    Input size in bytes
 * \param[out]  output        Output buffer
 * \param[in]   output_size   Output size in bytes
 * \param[in]   is_encrypt    Set the operation type (encryption/decryption)
 *
 * \return PSA_SUCCESS on succesfull operation or a valid PSA error code
 *
 */
psa_status_t tfm_its_crypt_file(struct its_flash_fs_file_info_t *finfo,
                                uint8_t *fid,
                                size_t fid_size,
                                uint8_t *input,
                                size_t input_size,
                                uint8_t *output,
                                size_t output_size,
                                bool is_encrypt);

