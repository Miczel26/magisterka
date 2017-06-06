/*
 * rng.c
 *
 *  Created on: 28.11.2016
 *      Author: lukasz.zarnecki
 */

#include "stm32f2xx_hal.h"
#include "crypto.h"

#define INCLUDE_RNG

#include "rng.h"

/*
 * String of entropy
 */
static const uint8_t entropyData[32] =
{
    0x91, 0x20, 0x1a, 0x18, 0x9b, 0x6d, 0x1a, 0xa7,
    0x0e, 0x79, 0x57, 0x6f, 0x36, 0xb6, 0xaa, 0x88,
    0x55, 0xfd, 0x4a, 0x7f, 0x97, 0xe9, 0x71, 0x69,
    0xb6, 0x60, 0x88, 0x78, 0xe1, 0x9c, 0x8b, 0xa5
};

int32_t InitRNG(RNGstate_stt *P_pRNGstate)
{
    /* Structure for the parmeters of initialization */
    RNGinitInput_stt RNGinit_st;

    /* Nonce */
    uint8_t nonce[4] = {0, 1, 2, 3};

    uint32_t status = RNG_ERR_UNINIT_STATE;

    /* Initialize the RNGinit structure */
    RNGinit_st.pmEntropyData = (uint8_t*)entropyData;
    RNGinit_st.mEntropyDataSize = sizeof(entropyData);
    RNGinit_st.pmNonce = nonce;
    RNGinit_st.mNonceSize = sizeof(nonce);

    /* There is no personalization data in this case */
    RNGinit_st.mPersDataSize = 0;
    RNGinit_st.pmPersData = NULL;

    /* Init the random engine */
    status = RNGinit(&RNGinit_st, P_pRNGstate);
    if (0 != status)
    {
        status = RNG_ERR_UNINIT_STATE;
    }
    else
    {
        status = RNG_SUCCESS;
    }

    return status;
}
