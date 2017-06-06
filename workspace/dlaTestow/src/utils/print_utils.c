/*
 * print_measurements.c
 *
 *  Created on: 19.12.2016
 *      Author: lukasz.zarnecki
 */

#include "print_utils.h"

#include "stdio.h"

void PrintMeasurements(uint32_t *measurements, uint32_t numberOfMeasurements, uint32_t status)
{
    printf("Status: %d\n", status);
    printf("Measurements:\n");

    for(uint32_t i = 0; i < numberOfMeasurements; i++)
    {
        printf("%u\n", measurements[i]);
    }
}

void PrintHexString(uint8_t *array, uint32_t arraySize)
{
    printf("Hex string size: %d\n", arraySize);

    for(uint32_t i = 0; i < arraySize; i++)
    {
        // Hex format, upper case letters and preceding zeros
        printf("%02X", array[i]);
    }
    printf("\n");
}

/*
 * Print values of measurements for each steps: init, append, final
 */
void PrintMeasurementsByStage(int numberOfMeasurements, uint32_t *measurements_init, uint32_t *measurements_append, uint32_t *measurements_final, uint32_t status)
{
    printf("Init stage measurements:\n");
    PrintMeasurements(measurements_init, numberOfMeasurements, status);
    printf("Append stage measurements:\n");
    PrintMeasurements(measurements_append, numberOfMeasurements, status);
    printf("Final stage measurements:\n");
    PrintMeasurements(measurements_final, numberOfMeasurements, status);
}

/*
 * Print ECC private key
 */
void PrintBigNum(BigNum_stt *bigNum)
{
    for(uint16_t i = bigNum->mNumDigits; i > 0 ; i--)
    {
        printf("%x", bigNum->pmDigit[i - 1]);
    }
}

void PrintEccPrivateKey(AccHw_ECCprivKey_stt *privKey)
{
    PrintBigNum(privKey->pmD);
    printf("\n");
}

void PrintEccPublicKey(AccHw_ECpoint_stt *pubKey)
{
    printf("x: ");
    PrintBigNum(pubKey->pmX);
    printf("\n");
    printf("y: ");
    PrintBigNum(pubKey->pmY);
    printf("\n");
    printf("z: ");
    PrintBigNum(pubKey->pmZ);
    printf("\n");
}

/*
 * Common text messages
 */
const uint8_t *shaTypeText[] = {"SHA1", "SHA224", "SHA256", "SHA384", "SHA512"};
const uint8_t *shaBlockTypeText[] = {"one block", "two blocks"};

const uint8_t *hmacInputBytesSizeText[] = {"0 bytes", "128 bytes", "512 bytes", "1024 bytes"};

const uint8_t *eccCurvesNameText[] = {"brainpool p192r1", "brainpool p256r1", "brainpool p384r1", "brainpool p512r1"};


