/*
 * test_ecc_keygen.h
 *
 *  Created on: 31.10.2016
 *      Author: michal.stroka
 */

#ifndef ECC_PERFORMANCE_TEST_TESTS_TEST_ECC_KEYGEN_H_
#define ECC_PERFORMANCE_TEST_TESTS_TEST_ECC_KEYGEN_H_

#include "inttypes.h"
#include "stm32f2xx_hal.h"



int key_generation_test(TIM_HandleTypeDef *, uint32_t *, int, int);

#endif /* ECC_PERFORMANCE_TEST_TESTS_TEST_ECC_KEYGEN_H_ */
