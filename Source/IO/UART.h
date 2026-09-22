#pragma once

#include "Core/Defines.h"

#include <stdint.h>
#include <avr/io.h>

void uart_init()
{
    uint16_t ubrr = ((F_CPU / (16UL * BAUD_RATE)) - 1);
    UBRR0H = (uint8_t)(ubrr >> 8);
    UBRR0L = (uint8_t)ubrr;
    UCSR0B = (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_write(uint8_t data)
{
    while (!(UCSR0A & (1 << UDRE0))) {}
    UDR0 = data;
}

void uart_print(const char* str)
{
    while (*str)
        uart_write(*str++);
}
