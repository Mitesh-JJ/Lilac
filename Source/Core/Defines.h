#pragma once

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#define F_CPU 16000000UL
#define BAUD_RATE 9600UL

#define GET_REF(addr) *(volatile uint8_t*)addr
#define STATE_HIGH 1
#define STATE_LOW 0
