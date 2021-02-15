/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

const uint LED_PIN = 25;
const int unitTime = 250;

// Flash one dot
void dot()
{
    gpio_put(LED_PIN, 1);
    sleep_ms(unitTime);
    gpio_put(LED_PIN, 0);
    sleep_ms(unitTime);
}
// Flash one dash
void dash()
{
    gpio_put(LED_PIN, 1);
    sleep_ms(unitTime * 3);
    gpio_put(LED_PIN, 0);
    sleep_ms(unitTime);
}
// Time to wait between two words
void word_space()
{
    sleep_ms(unitTime * 7);
}
// Time to wait between two letters
void letter_space()
{
    sleep_ms(unitTime * 3);
}
void inter_elem()
{
    sleep_ms(unitTime);
}

void char_to_morse(char morse)
{
    switch (morse)
    {
    case 's':
        dot();
        dot();
        dot();
        break;

    case 'o':
        dash();
        dash();
        dash();
        break;
    case 'l':
        dot();
        dash();
        dot();
        dot();
        break;
    case 'v':
        dot();
        dot();
        dot();
        dash();
        break;
    case 'e':
        dot();
        break;
    case 'u':
        dot();
        dot();
        dash();
        break;
    case 't':
        dash();
        break;
    case 'n':
        dash();
        dot();
        break;
    case 'a':
        dot();
        dash();
        break;
    case 'd':
        dash();
        dot();
        dot();
        break;
    case 'b':
        dash();
        dot();
        dot();
        dot();
        break;
    case 'c':
        dash();
        dot();
        dash();
        dot();
        break;
    case 'k':
        dash();
        dot();
        dash();
        break;
        case 'm': dash();dash();break;
        case 'h': dot();dot();dot();dot();break;
    case ' ':
        word_space();
        break;
    }
}

int main()
{
    char message[] = "secret message here";
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true)
    {
        for (int i = 0; message[i] != '\0'; i++)
        { // Convert and flash the indicator for the current char
            char_to_morse(message[i]);
            // Wait for unit * 3 time after each char
            letter_space();
        }
        // Wait for unit * 7 time after each round
        word_space();
    }
}
