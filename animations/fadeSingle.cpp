#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../tlc5940.h"
#include "../LedSquare.h"


static const int8_t fadeFactor = 2;

const uint16_t squareInitTable[] = {
	0x000,0x00F,0xF00,0x010,0x0F0,0x0D0,0x0A0,0xB00,0x300,0x050,
	0x000,0x00F,0xF00,0x010,0x0F0,0x0D0,0x0A0,0xB00,0x300,0x050,
	0x000,0x00F,0xF00,0x010,0x0F0,0x0D0,0x0A0,0xB00,0x300,0x050,
	0x000,0x00F,0xF00,0x010,0x0F0,0x0D0,0x0A0,0xB00,0x300,0x050,
	0x000,0x00F,0xF00,0x010,0x0F0,0x0D0,0x0A0,0xB00,0x300,0x050,
	0x000,0x00F,0xF00,0x010,0x0F0,0x0D0,0x0A0,0xB00,0x300,0x050,
	0x000,0x00F,0xF00,0x010,0x0F0,0x0D0,0x0A0,0xB00,0x300,0x050,
	0x000,0x00F,0xF00,0x010,0x0F0,0x0D0,0x0A0,0xB00,0x300,0x050,
	0x000,0x00F,0xF00,0x010,0x0F0,0x0D0,0x0A0,0xB00,0x300,0x050,
	0x000,0x00F,0xF00,0x010,0x0F0,0x0D0,0x0A0,0xB00,0x300,0x050
};


void fadeSingleRunLoop(const uint8_t& numSquares, const int16_t& maxBrightness)
{
	TLC5940_Init();

	LedSquare allSquares[numSquares];
	// Create our LedSquare objects by giving them a random starting brightness
	for (int i = 0; i < numSquares; i++)
	{	
		// Initialize object
		allSquares[i].init( squareInitTable[i], true );
	}

	// Default all channels off
	TLC5940_SetAllGS(0);
	
	// Enable Global Interrupts
	sei();

	while (1<2) // infinite loop 
	{
		while(gsUpdateFlag);	// wait until we can modify grayscaleData
		
		for (uint16_t i = 0; i < numSquares; i++)
		{
			if( allSquares[i].m_brightnessAscending )
			{
				
				TLC5940_SetGS(i, allSquares[i].m_currentBrightness);

				// Ascending, so increment
				allSquares[i].m_currentBrightness += fadeFactor;

				// Check if we have reached max brightness level
				// Need to subtract fadeFactor because otherwise there is a glitch at the top of the cycle
				if( allSquares[i].m_currentBrightness >= (maxBrightness-fadeFactor) )
				{
					// Flip switch so we will start descending
					allSquares[i].m_brightnessAscending = false;
					// In case we have gone over. Why the hell doesn't this work
					allSquares[i].m_currentBrightness = maxBrightness;

					//TLC5940_SetGS(1, 0xFFF);
				}
			}
			else 
			{
				
				TLC5940_SetGS(i, allSquares[i].m_currentBrightness);
				
				// Descending, so decrement
				allSquares[i].m_currentBrightness -= fadeFactor;
				
				// Check if we have reached the bottom
				if( allSquares[i].m_currentBrightness <= 0 )
				{
					// Flip switch so we will start ascending
					allSquares[i].m_brightnessAscending = true;
					// In case we had gone negative
					allSquares[i].m_currentBrightness = 0x00;
					//TLC5940_SetGS(1, 0x000);
				}
			}
		}

		TLC5940_SetGSUpdateFlag();
		_delay_us(1000);
	}
}