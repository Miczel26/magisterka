
#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

#include "stm32f2xx_hal.h"

void TimerInit(TIM_HandleTypeDef *timerHandler);
void TimerStart(TIM_HandleTypeDef *timerHandle);
uint32_t TimerStop(TIM_HandleTypeDef *timerHandler);

#endif /* TIMER_TIMER_H_ */
