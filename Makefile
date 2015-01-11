# Name: Makefile
# Author: <insert your name here>
# Copyright: <insert your copyright message here>
# License: <insert your license reference here>

# This is a prototype Makefile. Modify it according to your needs.
# You should at least check the settings for
# DEVICE ....... The AVR device you compile for
# CLOCK ........ Target AVR clock rate in Hertz
# OBJECTS ...... The object files created from your source files. This list is
#                usually the same as the list of source files with suffix ".o".
# PROGRAMMER ... Options to avrdude which define the hardware you use for
#                uploading to the AVR and the interface where this hardware
#                is connected.
# FUSES ........ Parameters for avrdude to flash the fuses appropriately.

DEVICE     = atmega328p
#CLOCK      = 18432000
CLOCK      = 16000000
#CLOCK      = 8000000
#CLOCK      = 1000000
PROGRAMMER = -c avrispmkII -P usb
OBJECTS    = main.o tlc5940.o

# Default setting for ATmega328P in Arduino Duemilanove
#FUSES      = -U hfuse:w:0xda:m -U lfuse:w:0xff:m

# Default setting for ATmega328P
#FUSES      = -U hfuse:w:0xd9:m -U lfuse:w:0x62:m

# Remove clock divider for ATmega328P
#FUSES      = -U hfuse:w:0xd9:m -U lfuse:w:0xe2:m

# Remove clock divider, set external crystal for ATmega328P
#FUSES      = -U hfuse:w:0xd9:m -U lfuse:w:0xe6:m

# Remove clock divider, set external crystal, enable clock output
FUSES      = -U hfuse:w:0xd9:m -U lfuse:w:0xa6:m

# ---------- Begin TLC5940 Configuration Section ----------
# Define the number of TLC5940 chips that are linked in series
TLC5940_N = 6

# Flag to choose whether to include routines for manually setting the dot
# correction
#  0 = Do not include dot correction routines (generates smaller code)
#  1 = Include dot correction routines (will still read from EEPROM by default)
TLC5940_MANUAL_DC_FUNCS = 1

# DDR, PORT, and PIN connected to DCPRG
DCPRG_DDR = DDRD
DCPRG_PORT = PORTD
DCPRG_PIN = PD4

# DDR, PORT, and PIN connected to VPRG
VPRG_DDR = DDRD
VPRG_PORT = PORTD
VPRG_PIN = PD7

# DDR, PORT, and PIN connected to XLAT
XLAT_DDR = DDRB
XLAT_PORT = PORTB
XLAT_PIN = PB1

# This line integrates all options into a single flag called:
#     $(TLC5940_DEFINES)
# which should be appended to the definition of COMPILE below
TLC5940_DEFINES = -DTLC5940_N=$(TLC5940_N) \
                  -DTLC5940_MANUAL_DC_FUNCS=$(TLC5940_MANUAL_DC_FUNCS) \
                  -DDCPRG_DDR=$(DCPRG_DDR) \
                  -DDCPRG_PORT=$(DCPRG_PORT) \
                  -DDCPRG_PIN=$(DCPRG_PIN) \
                  -DVPRG_DDR=$(VPRG_DDR) \
                  -DVPRG_PORT=$(VPRG_PORT) \
                  -DVPRG_PIN=$(VPRG_PIN) \
                  -DXLAT_DDR=$(XLAT_DDR) \
                  -DXLAT_PORT=$(XLAT_PORT) \
                  -DXLAT_PIN=$(XLAT_PIN)
# ---------- End TLC5940 Configuration Section ----------

# Tune the lines below only if you know what you are doing:
AVRDUDE    = avrdude $(PROGRAMMER) -p $(DEVICE)
COMPILE    = avr-gcc -std=gnu99 -g -Wall -Winline -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) $(TLC5940_DEFINES)
#COMPILE    = avr-gcc -std=gnu99 -g -Wall -Winline -O3 -funroll-loops -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) $(TLC5940_DEFINES)
#COMPILE    = avr-gcc -std=gnu99 -g -Wall -Winline -mint8 -O3 -funroll-loops -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) $(TLC5940_DEFINES)

LINK_FLAGS = -lc -lm

# symbolic targets:
all:	main.hex

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@
# "-x assembler-with-cpp" should not be necessary since this is the default
# file type for the .S (with capital S) extension. However, upper case
# characters are not always preserved on Windows. To ensure WinAVR
# compatibility define the file type manually.

.c.s:
	$(COMPILE) -S $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:main.hex:i

pflash:	all
	$(AVRDUDE) -n -U flash:w:main.hex:i

fuse:
	$(AVRDUDE) $(FUSES)

# Xcode uses the Makefile targets "", "clean" and "install"
install: flash fuse

# if you use a bootloader, change the command below appropriately:
load: all
	bootloadHID main.hex

clean:
	rm -f main.hex main.elf $(OBJECTS)

# file targets:
main.elf: $(OBJECTS)
	$(COMPILE) -o main.elf $(OBJECTS) $(LINK_FLAGS)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
# If you have an EEPROM section, you must also create a hex file for the
# EEPROM and add it to the "flash" target.

# Targets for code debugging and analysis:
disasm:	main.elf
	avr-objdump -S -d main.elf

cpp:
	$(COMPILE) -E main.c

%.lst: %.c
	{ echo '.psize 0' ; $(COMPILE) -S -g -o - $< ; } | avr-as -alhd -mmcu=$(DEVICE) -o /dev/null - > $@
