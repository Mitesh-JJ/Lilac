#pragma once

#include "Core/Defines.h"
#include "Core/Assert.h"

#include <stdlib.h>
#include <avr/io.h>

static inline void analog_init()
{
    ADMUX  |= 1 << REFS0;
    ADMUX  |= 1 << ADLAR;

    // [NOTE] Frequency: 125kHz
    ADCSRA |= (1 << ADPS2);
    ADCSRA |= (1 << ADPS1);
    ADCSRA |= (1 << ADPS0);

    ADCSRA |= 1 << ADEN;
}

static inline void analog_disable()
{
    ADCSRA = 0;
    ADMUX  = 0;
}

static inline uint8_t analog_read(const uint8_t pin)
{
    assert(pin < 6);

    ADMUX &= 0xF0;
    ADMUX |= pin;

    ADCSRA |= 1 << ADSC;
    while (ADCSRA & (1 << ADSC)) {}
    return ADCH;
}
