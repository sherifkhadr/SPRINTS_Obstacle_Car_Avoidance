/*
 * timer_cfg.c
 *
 * Created: 4/6/2023 5:33:09 AM
 *  Author: Mahmoud Mowafey
 */
#include "timer_config.h"


const ST_TimerConfig_t TimerConfig[]=
{
    {  TIMER0, TMR_DISABLED,  TMR_OVERFLOW_MODE, TMR_NORMAL_PORT_OPERATION_OC_PIN_DISCONNECTED,  TMR_INTERNAL,  TMR_MODULE_CLK, TMR_CLK_1024_FROM_PRESCALER, TMR_ISR_ENABLED },
    {  TIMER1, TMR_DISABLED,  TMR_OVERFLOW_MODE, TMR_NORMAL_PORT_OPERATION_OC_PIN_DISCONNECTED,  TMR_INTERNAL,  TMR_MODULE_CLK, TMR_CLK_1024_FROM_PRESCALER, TMR_ISR_ENABLED },
    {  TIMER2, TMR_DISABLED,  TMR_OVERFLOW_MODE, TMR_NORMAL_PORT_OPERATION_OC_PIN_DISCONNECTED,  TMR_INTERNAL,  TMR_MODULE_CLK, TMR_CLK_1024_FROM_PRESCALER, TMR_ISR_ENABLED }
};




