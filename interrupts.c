/**
 * @file interrupts.c
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "interrupts.h"

/*****************************************************************************/
/*  Function Declaration                                                     */
/*****************************************************************************/
void Handler_Timer(void *handler_arg, cyhal_timer_event_t event);

/*****************************************************************************/
/*  Global Variables                                                         */
/*****************************************************************************/

/* Timer object used */
cyhal_timer_t timer_obj;
cyhal_timer_cfg_t timer_cfg;
/*****************************************************************************/
/*  Interrupt Handlers                                                       */
/*****************************************************************************/
/**
 * @brief
 *  Function used as Timer Handler
 */
void Handler_Timer(void *handler_arg, cyhal_timer_event_t event)
{
}

/**
 * @brief 
 *  Enables a TCPWM Timer that will generate interrupts 
 * @param ticks 
 *  Sets the rate of interrupts based on the number of MCU (48MHz) 
 *  clock ticks
 */
void ece315_timer_init(uint32_t ticks)
{
   timer_init(&timer_obj, &timer_cfg, ticks,Handler_Timer); 
}
