/*
 * test_sha.c
 *
 *  Created on: 19.12.2016
 *      Author: lukasz.zarnecki
 */
#include "../../inc/aes/test_aes.h"
#include "../../inc/timer/timer.h"



/*
 * Aggregation of test vectors data
 */
void test_aes_init(TIM_HandleTypeDef *timerHandle, Aes *aes, const byte *key, const byte *iv, uint8_t nrOfMeasurments)
{
    byte msg[16] = {0};
    byte cipher[16];
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_AesSetKey(aes, key, 16, iv, AES_ENCRYPTION);
            wc_AesCbcEncrypt(aes, cipher, msg, 16);
            printf("%d\n", TimerStop(timerHandle));
        }
}
