/**
 * @file interrupts.h
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__

#include "drivers/ece315.h"

void ece315_timer_init(uint32_t ticks);

#endif