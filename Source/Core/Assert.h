#pragma once

#include "Core/Defines.h"

#include <stdbool.h>
#include <stdlib.h>
#include <avr/io.h>

static inline void assert(bool condition)
{
#ifndef NDEBUG
    if (!condition)
    {
        // [NOTE] Deactivates onboard LED
        DDRB  |=  (1 << DDB5);
        PORTB &= ~(1 << PB5);
        exit(1);
    }
#endif
}
