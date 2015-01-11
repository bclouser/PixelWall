#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "tlc5940.h"

#define RAND_MAX 0xFF0

const int8_t numSquares = 96;
const int8_t fadeFactor = 2;
const int16_t maxBrightness = 0xFFF;

class LedSquare
{
public:
	LedSquare(){}
	void init(int16_t start)
	{
		m_currentBrightness = start;
		m_brightnessAscending = true;
	}

	~LedSquare(){}
	int16_t m_currentBrightness;
	bool m_brightnessAscending;
	
};


int main(void) {
	TLC5940_Init();

	srand(42); // cuz why not

	//Create container to hold all our LEDSquares
	LedSquare* allSquares[numSquares];

	// Create our LedSquare objects by giving them a random starting brightness
	for (int i = 0; i < numSquares; i++)
	{
		// No "new" operator... gross!
		allSquares[i] = (LedSquare*)malloc(sizeof(allSquares[i]));
		
		// Initialize object
		allSquares[i]->init( (int16_t)rand() );
	}

	// Default all channels off
	TLC5940_SetAllGS(0);
	
	// Enable Global Interrupts
	sei();

	while (1<2) // infinite loop 
	{
		while(gsUpdateFlag);	// wait until we can modify gsData
		
		for (uint16_t i = 0; i < numSquares; i++)
		{
			if( allSquares[i]->m_brightnessAscending )
			{
				
				TLC5940_SetGS(i, allSquares[i]->m_currentBrightness);

				// Ascending, so increment
				allSquares[i]->m_currentBrightness += fadeFactor;

				// Check if we have reached max brightness level
				if( allSquares[i]->m_currentBrightness >= (maxBrightness - fadeFactor) )
				{
					// Flip switch so we will start descending
					allSquares[i]->m_brightnessAscending = false;
					// In case we have gone over.
					//allSquares[i]->m_currentBrightness = maxBrightness-1;
				}
			}
			else 
			{
				
				TLC5940_SetGS(i, allSquares[i]->m_currentBrightness);
				
				// Descending, so decrement
				allSquares[i]->m_currentBrightness -= fadeFactor;
				
				// Check if we have reached the bottom
				if( allSquares[i]->m_currentBrightness <= 0 )
				{
					// Flip switch so we will start ascending
					allSquares[i]->m_brightnessAscending = true;
					// In case we had gone negative
					allSquares[i]->m_currentBrightness = 0x00;
				}
			}
		}

		TLC5940_SetGSUpdateFlag();
		
		
		_delay_us(1000);
	}
	
	return 0;
}
