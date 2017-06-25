/****************************** MACROS ******************************/
#define SHA256_BLOCK_SIZE 32            // SHA256 outputs a 32 byte digest

#include "../../inc/timer/timer.h"
#include "../../test_vectors/sha/ShaData.h"
#include <stdlib.h>

/**************************** DATA TYPES ****************************/
typedef uint8_t BYTE;             // 8-bit byte
typedef uint32_t WORD;             // 32-bit word, change to "long" for 16-bit machines

typedef struct {
    uint8_t data[64];
	uint32_t datalen;
	uint32_t bitlen;
	uint32_t state[8];
} SHA256_CTX;

/*********************** FUNCTION DECLARATIONS **********************/
void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, const BYTE data[], int len);
void sha256_final(SHA256_CTX *ctx, BYTE hash[]);
void sha256_moje_test(TIM_HandleTypeDef *timerHandle);

