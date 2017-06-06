/*
 * test_sha.c
 *
 *  Created on: 19.12.2016
 *      Author: lukasz.zarnecki
 */
#include "../../inc/sha/test_sha_oneshot.h"

#include "../../test_vectors/sha/ShaOneShotData.h"
#include "../../inc/timer/timer.h"


/*
 * Aggregation of test vectors data
 */
void test_sha_oneshot(TIM_HandleTypeDef *timerHandle, uint8_t shaType, uint8_t nrOfMeasurments)
{
    switch (shaType)
    {
    case SHA:
    {
        byte output[SHA_DIGEST_SIZE];
        printf("Sha One block: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_ShaHash(Sha1OneShotOneBlock, sizeof(Sha1OneShotOneBlock),
                    output);
            printf("%d\n", TimerStop(timerHandle));
        }

        printf("Sha Two blocks: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_ShaHash(Sha1OneShotTwoBlock, sizeof(Sha1OneShotTwoBlock),
                    output);
            printf("%d\n", TimerStop(timerHandle));
        }
        break;
    }
    case SHA256:
    {
        byte output[SHA256_DIGEST_SIZE];
        printf("Sha256 One block: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_Sha256Hash(Sha256OneShotOneBlock, sizeof(Sha256OneShotOneBlock),
                    output);
            printf("%d\n", TimerStop(timerHandle));
        }

        printf("Sha256 Two blocks: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_Sha256Hash(Sha256OneShotTwoBlock, sizeof(Sha256OneShotTwoBlock),
                    output);
            printf("%d\n", TimerStop(timerHandle));
        }
        break;
    }
    case SHA384:
    {
        byte output[SHA384_DIGEST_SIZE];
        printf("Sha384 One block: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_Sha384Hash(Sha384OneShotOneBlock, sizeof(Sha384OneShotOneBlock),
                    output);
            printf("%d\n", TimerStop(timerHandle));
        }

        printf("Sha384 Two blocks: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_Sha384Hash(Sha384OneShotTwoBlock, sizeof(Sha384OneShotTwoBlock),
                    output);
            printf("%d\n", TimerStop(timerHandle));
        }
        break;
    }
    case SHA512:
    {
        byte output[SHA512_DIGEST_SIZE];
        printf("Sha512 One block: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_Sha512Hash(Sha512OneShotOneBlock, sizeof(Sha512OneShotOneBlock),
                    output);
            printf("%d\n", TimerStop(timerHandle));
        }

        printf("Sha512 Two blocks: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_Sha512Hash(Sha512OneShotTwoBlock, sizeof(Sha512OneShotTwoBlock),
                    output);
            printf("%d\n", TimerStop(timerHandle));
        }
        break;
    }
    }
}
