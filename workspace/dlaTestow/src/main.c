/*
 * main.c
 *
 *  Created on: 21.10.2016
 *      Author: lukasz.zarnecki
 */

#include <stdio.h>
#include <stdlib.h>

/* HAL */
#include "stm32f2xx_hal.h"
/* Timer */
#include "../inc/timer/timer.h"
/* SHA */
#include "../inc/sha/test_sha.h"
/* AES */
#include "../inc/aes/test_aes.h"


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

    TIM_HandleTypeDef timerHandle;
    TimerInit(&timerHandle);
    uint8_t iv[16] ;
    uint8_t key[16] ;
    Aes aes;
    test_aes_init(&timerHandle, &aes, key, iv, NUMBER_OF_MEASUREMENTS);
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
