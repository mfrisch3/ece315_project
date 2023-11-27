/**
 * @file main.c
 * @author Joe Krachey (jkrachey@wisc.edu)
 * @brief
 * @version 0.1
 * @date 2023-10-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "drivers/ece315.h"

int main(void)
{
    bool buzzer_on = false;
    bool status_rx_upstream = false;
    bool status_rx_downstream = false;

    uint8_t upstream_msg[80];
    uint8_t downstream_msg[80];

    /* Enable global interrupts */
    __enable_irq();

    /* Enable the button*/
    ece315_button_init();

    /* Enable LEDs */
    ece315_leds_init();

    // Turn LEDS off
    ece315_leds_all_off();

    /* Initialize the Buzzer to operate at 2.5KHz */
    ece315_buzzer_init(2500);

    for (;;)
    {
        
        if (ALERT_BUTTON_PRESSED)
        {
            ALERT_BUTTON_PRESSED = false;
            buzzer_on = !buzzer_on;

            if (buzzer_on)
            {
                ece315_buzzer_start();
            }
            else
            {
                ece315_buzzer_stop();
            }
        }

        if(ALERT_LEDS_OFF)
        {
            ALERT_LEDS_OFF = false;
            ece315_leds_all_off();
        }
        
        if(ALERT_LEDS_ON)
        {
            ALERT_LEDS_ON = false;
            ece315_leds_all_on();
        }

    }
}

/* [] END OF FILE */
