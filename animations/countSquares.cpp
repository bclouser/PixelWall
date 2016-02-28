#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../tlc5940.h"


static const int8_t fadeFactor = 2;


void countSquaresRunLoop(const uint8_t& numSquares, const int16_t& maxBrightness)
{
	uint16_t i = 0;
	TLC5940_Init();
	// Enable Global Interrupts
	sei();
	while (1<2) // infinite loop 
	{
		while(gsUpdateFlag);	// wait until we can modify gsData
		
		TLC5940_SetAllGS(0);
		if( i == 0)
		{
			// Light an extra one so we know it is the first square.
			TLC5940_SetGS(i+1, maxBrightness);
		}
		
		TLC5940_SetGS(i, maxBrightness);
		
		TLC5940_SetGSUpdateFlag();
		
		_delay_ms(1000);  //hang out for a while

		++i;
		if( i >= numSquares )
		{
			i = 0;
		}
	}
}