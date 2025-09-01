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

void turn_LED_on(uint8_t LED, uint8_t delay)
{
    switch (LED)
    {
    case 0:
        cyhal_gpio_write(PIN_LED_R4, LED_ON);
        cyhal_system_delay_ms(delay);
        cyhal_gpio_write(PIN_LED_R4, LED_OFF);
        break;
    case 1:
        cyhal_gpio_write(PIN_LED_R3, LED_ON);
        cyhal_system_delay_ms(delay);
        cyhal_gpio_write(PIN_LED_R3, LED_OFF);
        break;
    case 2:
        cyhal_gpio_write(PIN_LED_R2, LED_ON);
        cyhal_system_delay_ms(delay);
        cyhal_gpio_write(PIN_LED_R2, LED_OFF);
        break;
    case 3:
        cyhal_gpio_write(PIN_LED_R1, LED_ON);
        cyhal_system_delay_ms(delay);
        cyhal_gpio_write(PIN_LED_R1, LED_OFF);
        break;
    case 4:
        cyhal_gpio_write(PIN_LED_Y4, LED_ON);
        cyhal_system_delay_ms(delay);
        cyhal_gpio_write(PIN_LED_Y4, LED_OFF);
        break;
    case 5:
        cyhal_gpio_write(PIN_LED_Y3, LED_ON);
        cyhal_system_delay_ms(delay);
        cyhal_gpio_write(PIN_LED_Y3, LED_OFF);
        break;
    case 6:
        cyhal_gpio_write(PIN_LED_Y2, LED_ON);
        cyhal_system_delay_ms(delay);
        cyhal_gpio_write(PIN_LED_Y2, LED_OFF);
        break;

    case 7:
        cyhal_gpio_write(PIN_LED_Y1, LED_ON);
        cyhal_system_delay_ms(delay);
        cyhal_gpio_write(PIN_LED_Y1, LED_OFF);
        break;
    case 8:
        cyhal_gpio_write(PIN_LED_G4, LED_ON);
        cyhal_system_delay_ms(50);
        cyhal_gpio_write(PIN_LED_G4, LED_OFF);
        break;
    case 9:
        cyhal_gpio_write(PIN_LED_G3, LED_ON);
        cyhal_system_delay_ms(50);
        cyhal_gpio_write(PIN_LED_G3, LED_OFF);
        break;
    case 10:
        cyhal_gpio_write(PIN_LED_G2, LED_ON);
        cyhal_system_delay_ms(50);
        cyhal_gpio_write(PIN_LED_G2, LED_OFF);
        break;
    case 11:
        cyhal_gpio_write(PIN_LED_G1, LED_ON);
        cyhal_system_delay_ms(50);
        cyhal_gpio_write(PIN_LED_G1, LED_OFF);
        break;
    default:
        break;
    }
}

int main(void)
{
    bool buzzer_on = false;
    bool status_rx_upstream = false;
    bool status_rx_downstream = false;
    bool game_over;
    bool active_LED_on;
    uint8_t upstream_msg[80];
    uint8_t downstream_msg[80];
    uint8_t delay;
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

        game_over = true;

        if (ALERT_BUTTON_PRESSED)
        {
            game_over = false;
            ALERT_BUTTON_PRESSED = false;
        }

        delay = 50;
        uint8_t i;
        while (game_over == false)
        {
            i++;
            if (i == 12)
            {
                i = 0;
            }
            turn_LED_on(i, delay);
            if ((i == 8) || (i == 9) || (i == 10) || (i == 11))
            {
                active_LED_on = true;
            }
            else
            {
                active_LED_on = false;
            }
            if (active_LED_on && ALERT_BUTTON_PRESSED)
            {
                delay -= 5;
                buzzer_on = true;
                if (buzzer_on)
                {
                    ece315_buzzer_start();
                    cyhal_system_delay_ms(100);
                    ece315_buzzer_stop();
                    buzzer_on = false;
                }
                ALERT_BUTTON_PRESSED = false;
            }
            else if ((active_LED_on == false) && ALERT_BUTTON_PRESSED)
            {
                game_over = true;
                ALERT_BUTTON_PRESSED = false;
            }
        }

        if (game_over)
        {
            if (ALERT_LEDS_OFF)
            {
                ALERT_LEDS_OFF = false;
                ece315_leds_all_off();
            }

            if (ALERT_LEDS_ON)
            {
                ALERT_LEDS_ON = false;
                ece315_leds_all_on();
            }
        }
    }
}

/* [] END OF FILE */
