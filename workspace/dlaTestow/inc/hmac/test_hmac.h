/*
 * test_hmac.h
 *
 *  Created on: 20.12.2016
 *      Author: michal.stroka
 */

#ifndef HMAC_TEST_HMAC_H_
#define HMAC_TEST_HMAC_H_

#include "inttypes.h"
#include "stm32f2xx_hal.h"
#include "wolfssl/options.h"
#include "wolfssl/wolfcrypt/hash.h"	
#include "wolfssl/wolfcrypt/hmac.h"
#include "wolfssl/wolfcrypt/sha.h"
#include "wolfssl/wolfcrypt/sha256.h"
#include "wolfssl/wolfcrypt/sha512.h"

void test_hmac(TIM_HandleTypeDef *timerHandle, uint8_t shaType, uint8_t nrOfMeasurments);


#endif /* HMAC_TEST_HMAC_H_ */
