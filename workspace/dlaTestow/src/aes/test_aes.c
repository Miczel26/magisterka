/*
 * test_sha.c
 *
 *  Created on: 19.12.2016
 *      Author: michal.stroka
 */
#include "../../inc/aes/test_aes.h"
#include "../../inc/timer/timer.h"

#include "../../test_vectors/aes/AesData.h"


/*
 * Aggregation of test vectors data
 */
void test_aes(TIM_HandleTypeDef *timerHandle, Aes *aes, uint8_t nrOfMeasurments)
{
    byte cipher[1024];
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_AesSetKey(aes, AesKey32, 32, AesIV, AES_ENCRYPTION);
            printf("%d ", TimerStop(timerHandle));
            TimerStart(timerHandle);
            wc_AesCbcEncrypt(aes, AesOneBlock, AesOneBlock, sizeof(AesOneBlock));
            printf("%d\n", TimerStop(timerHandle));
        }
        printf("Two block\n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_AesSetKey(aes, AesKey32, 32, AesIV, AES_ENCRYPTION);
            printf("%d ", TimerStop(timerHandle));
            TimerStart(timerHandle);
            wc_AesCbcEncrypt(aes, AesTwoBlock, AesTwoBlock, sizeof(AesTwoBlock));
            printf("%d\n", TimerStop(timerHandle));
        }
        printf("1024 bytes\n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_AesSetKey(aes, AesKey32, 32, AesIV, AES_ENCRYPTION);
            printf("%d ", TimerStop(timerHandle));
            TimerStart(timerHandle);
            wc_AesCbcEncrypt(aes, Aes1024Bytes, Aes1024Bytes, sizeof(Aes1024Bytes));
            printf("%d\n", TimerStop(timerHandle));
        }

}
