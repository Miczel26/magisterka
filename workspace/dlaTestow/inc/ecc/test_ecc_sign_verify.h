/*
 * test_ecc_sign_verify.h
 *
 *  Created on: 08.11.2016
 *      Author: michal.stroka
 */

#ifndef TESTS_ECC_TEST_ECC_SIGN_VERIFY_H_
#define TESTS_ECC_TEST_ECC_SIGN_VERIFY_H_

#include "inttypes.h"
#include "stm32f2xx_hal.h"

#include "wolfssl/wolfcrypt/ecc.h"

int sign_verify_test(TIM_HandleTypeDef *, uint32_t *, int, int);

#endif /* TESTS_ECC_TEST_ECC_SIGN_VERIFY_H_ */
