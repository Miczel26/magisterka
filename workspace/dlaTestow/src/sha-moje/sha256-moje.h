/****************************** MACROS ******************************/
#define SHA256_BLOCK_SIZE 32            // SHA256 outputs a 32 byte digest

#include "../../inc/timer/timer.h"
#include "../../test_vectors/sha/ShaData.h"
#include "stm32f2xx.h"
#include "stm32f2xx_hash.h"
#include <stdlib.h>

#define SHA_BLOCK_SIZE    ( 64 )
#define SHA_DIGEST_SIZE   ( 20 )
#define SHA_REG_SIZE      (  4 )
#define SHA_PAD_SIZE 	  ( 56 )
/**************************** DATA TYPES ****************************/
typedef struct Sha {
    uint32_t  buffLen;   /* in bytes          */
    uint32_t  loLen;     /* length in bytes   */
    uint32_t  hiLen;     /* length in bytes   */
    uint32_t  buffer[ 16 ] ;
    uint32_t  digest[ 5 ];
} Sha;

/*********************** FUNCTION DECLARATIONS **********************/
int Sha_1_Init(Sha* sha);
int Sha_1_Update(Sha* sha, const uint8_t* data, uint32_t len);
int Sha_1_Final(Sha* sha, uint8_t* hash);
void test_sha_1(TIM_HandleTypeDef *timerHandle, uint8_t nrOfMeasurments);

