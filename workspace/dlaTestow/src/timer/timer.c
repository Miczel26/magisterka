#include "timer.h"

void TimerInit(TIM_HandleTypeDef *timerHandle)
{
    timerHandle->Instance = TIM2;

    __TIM2_CLK_ENABLE();
    timerHandle->Init.Prescaler = 1;
    timerHandle->Init.CounterMode = TIM_COUNTERMODE_UP;
    timerHandle->Init.Period = 0xFFFFFFFF;
    timerHandle->Init.ClockDivision = 1;

    HAL_TIM_OC_Init(timerHandle);
}

void TimerStart(TIM_HandleTypeDef *timerHandle)
{
    timerHandle->Instance->CNT = 0;
}

uint32_t TimerStop(TIM_HandleTypeDef *timerHandle)
{
    return timerHandle->Instance->CNT;
}

