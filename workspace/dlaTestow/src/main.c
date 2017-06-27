/*
 * main.c
 *
 *  Created on: 21.10.2016
 *      Author: michal.stroka
 */

#include <stdio.h>
#include <stdlib.h>

/* HAL */
#include "stm32f2xx_hal.h"
/* Timer */
#include "../inc/timer/timer.h"
/* SHA */
#include "../inc/sha/test_sha.h"
/* SHA-moje */
#include "../inc/sha-moje/sha256-moje.h"
/* AES */
#include "../inc/aes/test_aes.h"

//#include "wolfssl/wolfcrpyt/sha256.h"

/* Semihosting */
extern void initialise_monitor_handles(void);

// Number of measurements in test
#define NUMBER_OF_MEASUREMENTS 30U

int main()
{
    /* STM32F2xx HAL library initialization */
    HAL_Init();
	uint32_t results[NUMBER_OF_MEASUREMENTS];
    /* Semihosting */
    initialise_monitor_handles();
    Aes aes;
    TIM_HandleTypeDef timerHandle;
    TimerInit(&timerHandle);

	printf("WOLF\n");
	test_aes(&timerHandle, &aes, 30);
    /*
     * Examples of execution
     */
    //test_RsaEncrypt(&timerHandle, NUMBER_OF_MEASUREMENTS, measurements);
    //test_ShaOneShot(&timerHandle, NUMBER_OF_MEASUREMENTS, measurements);
    //test_EccSignVerify(&timerHandle, NUMBER_OF_MEASUREMENTS, measurements);
    //test_Sha(&timerHandle, NUMBER_OF_MEASUREMENTS, measurements_init, measurements_append, measurements_final);
    //test_Hmac(&timerHandle, NUMBER_OF_MEASUREMENTS, measurements_init, measurements_append, measurements_final);

    while(1)
    {
		;
    }

    return 0;
}
