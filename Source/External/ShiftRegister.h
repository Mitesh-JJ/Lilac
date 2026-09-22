#pragma once

#include "Core/Defines.h"
#include "IO/Port.h"

static inline void shiftreg_read(PortHandle sclk_port, uint8_t sclk_pin,
                                 PortHandle out_port, uint8_t out_pin,
                                 uint8_t state)
{
    port_write(sclk_port, sclk_pin, STATE_LOW);
    port_write(out_port, out_pin, state);
    port_write(sclk_port, sclk_pin, STATE_HIGH);
}

static inline void shiftreg_write(PortHandle lclk_port, uint8_t lclk_pin)
{
    port_write(lclk_port, lclk_pin, STATE_HIGH);
    port_write(lclk_port, lclk_pin, STATE_LOW);
}
