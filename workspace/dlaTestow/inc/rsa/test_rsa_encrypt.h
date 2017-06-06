/*
 * test_sha.h
 *
 *  Created on: 03.01.2017
 *      Author: michal.stroka
 */

#ifndef TEST_RSA_PUBLIC_H_
#define TEST_RSA_PUBLIC_H_

#include "inttypes.h"
#include "stm32f2xx_hal.h"
#include "wolfssl/options.h"

#include "wolfssl/wolfcrypt/rsa.h"	

int RsaPublicStandard(uint32_t *results, int keySize, RsaKey *enc, RNG *rng, TIM_HandleTypeDef *timerHandle, int nrOfMeasurement);

#endif /* TEST_RSA_PUBLIC_H_ */
