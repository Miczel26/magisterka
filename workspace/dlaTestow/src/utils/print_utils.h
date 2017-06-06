/*
 * print_measurements.h
 *
 *  Created on: 19.12.2016
 *      Author: lukasz.zarnecki
 */

#ifndef UTILS_PRINT_UTILS_H_
#define UTILS_PRINT_UTILS_H_

#include "inttypes.h"

/*
 * XCube structures:
 * AccHw_ECCprivKey_stt, AccHw_ECCprivKey_stt, BigNum_stt
 */
#include "stm32f2xx_hal.h"
#include "AccHw_crypto.h"

void PrintMeasurements(uint32_t *measurements, uint32_t numberOfMeasurements, uint32_t status);
void PrintMeasurementsByStage(int numberOfMeasurements, uint32_t *measurements_init, uint32_t *measurements_append, uint32_t *measurements_final, uint32_t status);
void PrintHexString(uint8_t *value, uint32_t size);

/*
 * Print ECC private key
 */
void PrintBigNum(BigNum_stt *bigNum);
void PrintEccPrivateKey(AccHw_ECCprivKey_stt *privKey);
void PrintEccPublicKey(AccHw_ECpoint_stt *pubKey);

/*
 * Common text messages
 */
extern const uint8_t *shaTypeText[];
extern const uint8_t *hmacInputBytesSizeText[];
extern const uint8_t *shaBlockTypeText[];
extern const uint8_t *eccCurvesNameText[];

#endif /* UTILS_PRINT_UTILS_H_ */
