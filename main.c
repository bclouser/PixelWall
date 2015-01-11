#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "tlc5940.h"

int main(void) {
	TLC5940_Init();
	
#if (TLC5940_MANUAL_DC_FUNCS)
	TLC5940_SetAllDC(63);
	TLC5940_ClockInDC();
#endif

	// Default all channels to off
	TLC5940_SetAllGS(0);
	
	// Enable Global Interrupts
	sei();

	int fadeCount = 0;
	int i = 0;

	const int channel_0 = rand();
	const int channel_1 = rand();
	const int channel_2 = rand();
	const int channel_3 = rand();
	const int channel_4 = rand();
	const int channel_5 = rand();
	const int channel_6 = rand();
	const int channel_7 = rand();
	const int channel_8 = rand();
	const int channel_9 = rand();
	const int channel_10 = rand();
	const int channel_11 = rand();
	const int channel_12 = rand();
	const int channel_13 = rand();
	const int channel_14 = rand();
	const int channel_15 = rand();

	for (;;) {
		while(gsUpdateFlag);	// wait until we can modify gsData
		
		TLC5940_SetGS(0, channel_0  + fadeCount);
		TLC5940_SetGS(1, channel_1  + fadeCount);
		TLC5940_SetGS(2, channel_2  + fadeCount);
		TLC5940_SetGS(3, channel_3  + fadeCount);
		TLC5940_SetGS(4, channel_4  + fadeCount);
		TLC5940_SetGS(5, channel_5  + fadeCount);
		TLC5940_SetGS(6, channel_6  + fadeCount);
		TLC5940_SetGS(7, channel_7  + fadeCount);
		TLC5940_SetGS(8, channel_8  + fadeCount);
		TLC5940_SetGS(9, channel_9  + fadeCount);
		TLC5940_SetGS(10, channel_10 + fadeCount);
		TLC5940_SetGS(11, channel_11 + fadeCount);
		TLC5940_SetGS(12, channel_12 + fadeCount);
		TLC5940_SetGS(13, channel_13 + fadeCount);
		TLC5940_SetGS(14, channel_14 + fadeCount);
		TLC5940_SetGS(15, channel_15 + fadeCount);
		TLC5940_SetGS(16, channel_0  + fadeCount);
		TLC5940_SetGS(17, channel_1  + fadeCount);
		TLC5940_SetGS(18, channel_2  + fadeCount);
		TLC5940_SetGS(19, channel_3  + fadeCount);
		TLC5940_SetGS(20, channel_4  + fadeCount);
		TLC5940_SetGS(21, channel_5  + fadeCount);
		TLC5940_SetGS(22, channel_6  + fadeCount);
		TLC5940_SetGS(23, channel_7  + fadeCount);
		TLC5940_SetGS(24, channel_8  + fadeCount);
		TLC5940_SetGS(25, channel_9  + fadeCount);
		TLC5940_SetGS(26, channel_10 + fadeCount);
		TLC5940_SetGS(27, channel_11 + fadeCount);
		TLC5940_SetGS(28, channel_12 + fadeCount);
		TLC5940_SetGS(29, channel_13 + fadeCount);
		TLC5940_SetGS(30, channel_14 + fadeCount);
		TLC5940_SetGS(31, channel_15 + fadeCount);
		TLC5940_SetGS(32, channel_0  + fadeCount);
		TLC5940_SetGS(33, channel_1  + fadeCount);
		TLC5940_SetGS(34, channel_2  + fadeCount);
		TLC5940_SetGS(35, channel_3  + fadeCount);
		TLC5940_SetGS(36, channel_4  + fadeCount);
		TLC5940_SetGS(37, channel_5  + fadeCount);
		TLC5940_SetGS(38, channel_6  + fadeCount);
		TLC5940_SetGS(39, channel_7  + fadeCount);
		TLC5940_SetGS(40, channel_8  + fadeCount);
		TLC5940_SetGS(41, channel_9  + fadeCount);
		TLC5940_SetGS(42, channel_10 + fadeCount);
		TLC5940_SetGS(43, channel_11 + fadeCount);
		TLC5940_SetGS(44, channel_12 + fadeCount);
		TLC5940_SetGS(45, channel_13 + fadeCount);
		TLC5940_SetGS(46, channel_14 + fadeCount);
		TLC5940_SetGS(47, channel_15 + fadeCount);
		TLC5940_SetGS(48, channel_0  + fadeCount);
		TLC5940_SetGS(49, channel_1  + fadeCount);
		TLC5940_SetGS(50, channel_2  + fadeCount);
		TLC5940_SetGS(51, channel_3  + fadeCount);
		TLC5940_SetGS(52, channel_4  + fadeCount);
		TLC5940_SetGS(53, channel_5  + fadeCount);
		TLC5940_SetGS(54, channel_6  + fadeCount);
		TLC5940_SetGS(55, channel_7  + fadeCount);
		TLC5940_SetGS(56, channel_8  + fadeCount);
		TLC5940_SetGS(57, channel_9  + fadeCount);
		TLC5940_SetGS(58, channel_10 + fadeCount);
		TLC5940_SetGS(59, channel_11 + fadeCount);
		TLC5940_SetGS(60, channel_12 + fadeCount);
		TLC5940_SetGS(61, channel_13 + fadeCount);
		TLC5940_SetGS(62, channel_14 + fadeCount);
		TLC5940_SetGS(63, channel_15 + fadeCount);
		TLC5940_SetGS(64, channel_10 + fadeCount);
		TLC5940_SetGS(65, channel_11 + fadeCount);
		TLC5940_SetGS(66, channel_12 + fadeCount);
		TLC5940_SetGS(67, channel_13 + fadeCount);
		TLC5940_SetGS(68, channel_14 + fadeCount);
		TLC5940_SetGS(69, channel_15 + fadeCount);
		TLC5940_SetGS(70, channel_0  + fadeCount);
		TLC5940_SetGS(71, channel_1  + fadeCount);
		TLC5940_SetGS(72, channel_2  + fadeCount);
		TLC5940_SetGS(73, channel_3  + fadeCount);
		TLC5940_SetGS(74, channel_4  + fadeCount);
		TLC5940_SetGS(75, channel_5  + fadeCount);
		TLC5940_SetGS(76, channel_6  + fadeCount);
		TLC5940_SetGS(77, channel_7  + fadeCount);
		TLC5940_SetGS(78, channel_8  + fadeCount);
		TLC5940_SetGS(79, channel_9  + fadeCount);
		TLC5940_SetGS(80, channel_10 + fadeCount);
		TLC5940_SetGS(81, channel_11 + fadeCount);
		TLC5940_SetGS(82, channel_12 + fadeCount);
		TLC5940_SetGS(83, channel_13 + fadeCount);
		TLC5940_SetGS(84, channel_14 + fadeCount);
		TLC5940_SetGS(85, channel_15 + fadeCount);
		TLC5940_SetGS(86, channel_0  + fadeCount);
		TLC5940_SetGS(87, channel_1  + fadeCount);
		TLC5940_SetGS(88, channel_2  + fadeCount);
		TLC5940_SetGS(89, channel_3  + fadeCount);
		TLC5940_SetGS(90, channel_4  + fadeCount);
		TLC5940_SetGS(91, channel_5  + fadeCount);
		TLC5940_SetGS(92, channel_6  + fadeCount);
		TLC5940_SetGS(93, channel_7  + fadeCount);
		TLC5940_SetGS(94, channel_8  + fadeCount);

		TLC5940_SetGSUpdateFlag();
		fadeCount += 2;
		
		if(fadeCount >= 0xFFF)
		{
			fadeCount = 0;
		}
		
		
		/*
		TLC5940_SetAllGS(0);
		TLC5940_SetGS(i, 0xFFF);

		if(i >= 95 )
		{
			i = 0;
		}
		else
		{
			i++;
		}
		TLC5940_SetGSUpdateFlag();
		_delay_ms(500);
		*/
		_delay_us(400);
	}
	
	return 0;
}
