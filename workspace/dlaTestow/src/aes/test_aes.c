/*
 * test_sha.c
 *
 *  Created on: 19.12.2016
 *      Author: lukasz.zarnecki
 */
#include "../../inc/aes/test_aes.h"
#include "../../inc/timer/timer.h"

#include "../../test_vectors/aes/AesData.h"


/*
 * Aggregation of test vectors data
 */
void test_aes(TIM_HandleTypeDef *timerHandle, Aes *aes, uint8_t nrOfMeasurments)
{
    byte cipher[256];
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_AesSetKey(aes, AesKey, 16, AesIV, AES_ENCRYPTION);
            wc_AesCbcEncrypt(aes, AesOneBlock, AesOneBlock, sizeof(AesOneBlock));
            printf("%d\n", TimerStop(timerHandle));
        }
}
