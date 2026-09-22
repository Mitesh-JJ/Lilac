#pragma once

#include "Core/Defines.h"
#include "Core/Assert.h"

#include <avr/io.h>
#include <stdint.h>

#define PORTB_HANDLE (PortHandle){.in_register = 0x23, .out_register = 0x25, .ddr_register = 0x24}
#define PORTC_HANDLE (PortHandle){.in_register = 0x26, .out_register = 0x28, .ddr_register = 0x27}
#define PORTD_HANDLE (PortHandle){.in_register = 0x29, .out_register = 0x2B, .ddr_register = 0x2A}

typedef struct
{
    const uintptr_t in_register;
    const uintptr_t out_register;
    const uintptr_t ddr_register;
} PortHandle;

static inline uint8_t port_read(PortHandle handle, uint8_t pin)
{
    assert(pin < 8);
    return GET_REF(handle.in_register >> pin) & 0x01;
}

static inline void port_write(PortHandle handle, uint8_t pin, uint8_t state)
{
    assert(pin < 8);
    GET_REF(handle.out_register) &= ~(1 << pin);
    GET_REF(handle.out_register) |= (state << pin);
}

static inline void port_mark_output(PortHandle handle, uint8_t pin, bool flag)
{
    assert(pin < 8);
    GET_REF(handle.ddr_register) &= ~(1 << pin);
    GET_REF(handle.ddr_register) |= flag << pin;
}
