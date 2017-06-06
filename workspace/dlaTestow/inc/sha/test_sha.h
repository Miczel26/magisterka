/*
 * test_sha.h
 *
 *  Created on: 03.01.2017
 *      Author: michal.stroka
 */

#ifndef TEST_SHA_H_
#define TEST_SHA_H_

#include "inttypes.h"
#include "stm32f2xx_hal.h"
#include "wolfssl/options.h"
#include "wolfssl/wolfcrypt/hash.h"	
#include "wolfssl/wolfcrypt/sha.h"
#include "wolfssl/wolfcrypt/sha256.h"
#include "wolfssl/wolfcrypt/sha512.h"

void test_sha(TIM_HandleTypeDef *timerHandle, uint8_t shaType, uint8_t nrOfMeasurments);

#endif /* TEST_SHA_H_ */
