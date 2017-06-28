#include "sha256-moje.h"

int Sha_1_Init(Sha* sha)
{
    /* STM32F2 struct notes:
     * sha->buffer  = first 4 bytes used to hold partial block if needed
     * sha->buffLen = num bytes currently stored in sha->buffer
     * sha->loLen   = num bytes that have been written to STM32 FIFO
     */
    memset(sha->buffer, 0, SHA_REG_SIZE);
    sha->buffLen = 0;
    sha->loLen = 0;

    /* initialize HASH peripheral */
    HASH_DeInit();

    /* configure algo used, algo mode, datatype */
    HASH->CR &= ~ (HASH_CR_ALGO | HASH_CR_DATATYPE | HASH_CR_MODE);
    HASH->CR |= (HASH_AlgoSelection_SHA1 | HASH_AlgoMode_HASH
                 | HASH_DataType_8b);

    /* reset HASH processor */
    HASH->CR |= HASH_CR_INIT;

    return 0;
}

int Sha_1_Update(Sha* sha, const uint8_t* data, uint32_t len)
{
	uint32_t i = 0;
	uint32_t fill = 0;
	uint32_t diff = 0;

    /* if saved partial block is available */
    if (sha->buffLen) {
        fill = 4 - sha->buffLen;

        /* if enough data to fill, fill and push to FIFO */
        if (fill <= len) {
        	memcpy(sha->buffer + sha->buffLen, data, fill);
            HASH_DataIn(*(uint32_t*)sha->buffer);

            data += fill;
            len -= fill;
            sha->loLen += 4;
            sha->buffLen = 0;
        } else {
            /* append partial to existing stored block */
            memcpy(sha->buffer + sha->buffLen, data, len);
            sha->buffLen += len;
            return 0;
        }
    }

    /* write input block in the IN FIFO */
    for(i = 0; i < len; i += 4)
    {
        diff = len - i;
        if ( diff < 4) {
            /* store incomplete last block, not yet in FIFO */
            memset(sha->buffer, 0, SHA_REG_SIZE);
            memcpy((uint8_t*)sha->buffer, data, diff);
            sha->buffLen = diff;
        } else {
            HASH_DataIn(*(uint32_t*)data);
            data+=4;
        }
    }

    /* keep track of total data length thus far */
    sha->loLen += (len - sha->buffLen);

    return 0;
}

int Sha_1_Final(Sha* sha, uint8_t* hash)
{
    __IO uint16_t nbvalidbitsdata = 0;

    /* finish reading any trailing bytes into FIFO */
    if (sha->buffLen) {
        HASH_DataIn(*(uint32_t*)sha->buffer);
        sha->loLen += sha->buffLen;
    }

    /* calculate number of valid bits in last word of input data */
    nbvalidbitsdata = 8 * (sha->loLen % SHA_REG_SIZE);

    /* configure number of valid bits in last word of the data */
    HASH_SetLastWordValidBitsNbr(nbvalidbitsdata);

    /* start HASH processor */
    HASH_StartDigest();

    /* wait until Busy flag == RESET */
    while (HASH_GetFlagStatus(HASH_FLAG_BUSY) != RESET) {}

    /* read message digest */
    sha->digest[0] = HASH->HR[0];
    sha->digest[1] = HASH->HR[1];
    sha->digest[2] = HASH->HR[2];
    sha->digest[3] = HASH->HR[3];
    sha->digest[4] = HASH->HR[4];

    asm("REV %[value], %[value]" : [value] "+r" (sha->digest[0]) );
    asm("REV %[value], %[value]" : [value] "+r" (sha->digest[1]) );
    asm("REV %[value], %[value]" : [value] "+r" (sha->digest[2]) );
    asm("REV %[value], %[value]" : [value] "+r" (sha->digest[3]) );
    asm("REV %[value], %[value]" : [value] "+r" (sha->digest[4]) );

    memcpy(hash, sha->digest, SHA_DIGEST_SIZE);

    return 0;  /* reset state */
}

void test_sha_1(TIM_HandleTypeDef *timerHandle, uint8_t nrOfMeasurments)
{
	Sha sha;
	uint8_t output[SHA_DIGEST_SIZE];

	printf("Sha-1 One block: \n");
	        for (int i = 0; i < nrOfMeasurments; ++i)
	        {
	            TimerStart(timerHandle);
	            Sha_1_Init(&sha);
	            printf("%d;", TimerStop(timerHandle));

	            TimerStart(timerHandle);
	            Sha_1_Update(&sha, Sha1OneBlock, sizeof(Sha1OneBlock));
	            printf("%d;", TimerStop(timerHandle));

	            TimerStart(timerHandle);
	            Sha_1_Final(&sha, output);
	            printf("%d\n", TimerStop(timerHandle));
	        }

	        for (int i = 0; i < nrOfMeasurments; ++i)
	       	        {
	       	            TimerStart(timerHandle);
	       	            Sha_1_Init(&sha);
	       	            printf("%d;", TimerStop(timerHandle));

	       	            TimerStart(timerHandle);
	       	            Sha_1_Update(&sha, Sha1TwoBlocks, sizeof(Sha1TwoBlocks));
	       	            printf("%d;", TimerStop(timerHandle));

	       	            TimerStart(timerHandle);
	       	            Sha_1_Final(&sha, output);
	       	            printf("%d\n", TimerStop(timerHandle));
	       	        }

	        for (int i = 0; i < nrOfMeasurments; ++i)
	       	        {
	       	            TimerStart(timerHandle);
	       	            Sha_1_Init(&sha);
	       	            printf("%d;", TimerStop(timerHandle));

	       	            TimerStart(timerHandle);
	       	            Sha_1_Update(&sha, Sha1_1024BytesBlocks, sizeof(Sha1_1024BytesBlocks));
	       	            printf("%d;", TimerStop(timerHandle));

	       	            TimerStart(timerHandle);
	       	            Sha_1_Final(&sha, output);
	       	            printf("%d\n", TimerStop(timerHandle));
	       	        }

}
