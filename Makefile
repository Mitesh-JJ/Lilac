CC     = avr-gcc
CXX    = avr-g++
CFLAGS = \
	-std=c17 -O1 \
	-Wall -Wextra -ggdb

# ============================== 

BOARD_ID   = atmega328p
BOARD_PORT = /dev/ttyUSB0
BOARD_BAUD = 115200
PROGRAMMER = arduino

# ============================== 

OUT_DIR = ./Build
SRC_DIR = ./Source

# ============================== 

source = $(SRC_DIR)/Main.c

lilac: build flash

build: $(source)
	$(CC) $(CFLAGS) -mmcu=$(BOARD_ID) \
	-o $(OUT_DIR)/lilac.elf \
	-I $(SRC_DIR) $(source) \

	avr-objcopy -j .text -j .data -O ihex \
	$(OUT_DIR)/lilac.elf $(OUT_DIR)/lilac.hex

	avr-size --format=avr --mcu=$(BOARD_ID) \
	$(OUT_DIR)/lilac.elf

flash:
	sudo avrdude -D -V -v -p $(BOARD_ID) -c $(PROGRAMMER) \
	-P $(BOARD_PORT) -b $(BOARD_BAUD) \
	-U flash:w:$(OUT_DIR)/lilac.hex:i

# ============================== 

clean:
	rm -rf $(OUT_DIR)/*
