#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>




const int8_t numSquares = 96;
const int16_t maxBrightness = 0xFFF;

// Forward declaration
void fadeTilesRunLoop(const int8_t& numSquares, const int16_t& maxBrightness);
void countSquaresRunLoop(const int8_t& numSquares, const int16_t& maxBrightness);

int main(void) {
	
	// Watch out. Infinite Loops
	fadeTilesRunLoop(numSquares, maxBrightness);

	//countSquaresRunLoop(numSquares, maxBrightness);
	
	return 0;
}
