/*
 * test_sha.c
 *
 *  Created on: 19.12.2016
 *      Author: lukasz.zarnecki
 */
#include "../../inc/sha/test_sha.h"

#include "../../test_vectors/sha/ShaData.h"
#include "../../inc/timer/timer.h"



/*
 * Aggregation of test vectors data
 */
void test_sha(TIM_HandleTypeDef *timerHandle, uint8_t shaType, uint8_t nrOfMeasurments)
{
    switch (shaType)
    {
    case SHA:
    {
        Sha sha;
        byte output[SHA_DIGEST_SIZE];
        printf("Sha One block: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_InitSha(&sha);
            printf("%d;", TimerStop(timerHandle));

            TimerStart(timerHandle);
            wc_ShaUpdate(&sha, Sha1OneBlock, sizeof(Sha1OneBlock));
            printf("%d;", TimerStop(timerHandle));

            TimerStart(timerHandle);
            wc_ShaFinal(&sha, output);
            printf("%d\n", TimerStop(timerHandle));
        }

        printf("Sha Two blocks: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_InitSha(&sha);
            printf("%d ", TimerStop(timerHandle));

            TimerStart(timerHandle);
            wc_ShaUpdate(&sha, Sha1TwoBlocks, sizeof(Sha1TwoBlocks));
            printf("%d ", TimerStop(timerHandle));

            TimerStart(timerHandle);
            wc_ShaFinal(&sha, output);
            printf("%d\n", TimerStop(timerHandle));
        }

        printf("Sha Two blocks: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_InitSha(&sha);
            printf("%d ", TimerStop(timerHandle));

            TimerStart(timerHandle);
            wc_ShaUpdate(&sha, Sha1_1024BytesBlocks, sizeof(Sha1_1024BytesBlocks));
            printf("%d ", TimerStop(timerHandle));

            TimerStart(timerHandle);
            wc_ShaFinal(&sha, output);
            printf("%d\n", TimerStop(timerHandle));
        }

        break;
    }
    case SHA256:
    {
        Sha256 sha;
        byte output[SHA256_DIGEST_SIZE];
        printf("Sha256 One block: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_InitSha256(&sha);
            printf("%d;", TimerStop(timerHandle));

            TimerStart(timerHandle);
            wc_Sha256Update(&sha, Sha256OneBlock, sizeof(Sha256OneBlock));
            printf("%d;", TimerStop(timerHandle));

            TimerStart(timerHandle);
            wc_Sha256Final(&sha, output);
            printf("%d\n", TimerStop(timerHandle));
        }

        printf("Sha256 Two blocks: \n");
        for (int i = 0; i < nrOfMeasurments; ++i)
        {
            TimerStart(timerHandle);
            wc_InitSha256(&sha);
            printf("%d ", TimerStop(timerHandle));

            TimerStart(timerHandle);
            wc_Sha256Update(&sha, Sha256TwoBlocks, sizeof(Sha256TwoBlocks));
            printf("%d ", TimerStop(timerHandle));

            TimerStart(timerHandle);
            wc_Sha256Final(&sha, output);
            printf("%d\n", TimerStop(timerHandle));
        }
        break;
    }
    
    }
    
}
