/*
 * test_sha.h
 *
 *  Created on: 03.01.2017
 *      Author: michal.stroka
 */

#ifndef TEST_AES_H_
#define TEST_AES_H_

#include "inttypes.h"
#include "stm32f2xx_hal.h"
#include "wolfssl/options.h"
#include "wolfssl/wolfcrypt/aes.h"

void test_aes_init(TIM_HandleTypeDef *timerHandle, Aes *aes, const byte *key, const byte *iv, uint8_t nrOfMeasurments);

#endif /* TEST_SHA_H_ */
