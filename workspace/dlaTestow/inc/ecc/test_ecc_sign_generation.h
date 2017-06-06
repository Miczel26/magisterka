/*
 * test_ecc_sign_generation.h
 *
 *  Created on: 07.11.2016
 *      Author: michal.stroka
 */

#ifndef TESTS_ECC_TEST_ECC_SIGN_GENERATION_H_
#define TESTS_ECC_TEST_ECC_SIGN_GENERATION_H_

#include "inttypes.h"
#include "stm32f2xx_hal.h"

#include "wolfssl/wolfcrypt/ecc.h"

int sign_hash_test(TIM_HandleTypeDef *, uint32_t *, uint8_t *, int, int, int);

#endif /* TESTS_ECC_TEST_ECC_SIGN_GENERATION_H_ */
