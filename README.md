14x6 PWM Pixel Wall. 


Using the driver based on Demystifying the TLC5940

Instructions:

  1. Verify that DEVICE, CLOCK, PROGRAMMER, and FUSES are set
     correctly in the Makefile based on your hardware. The provided
     Makefile is configured for an ATmega328P running at 18.432 MHz,
     using an AVR ISP mkII programmer, with FUSES set to remove the
     clock divider, to use the external crystal, and to enable clock
     output.

  2. To build, type `make`

  3. To set the fuse bits, type `make fuse`

  4. To program the AVR, type `make flash`
