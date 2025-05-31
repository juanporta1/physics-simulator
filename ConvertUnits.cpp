#include <ConvertUnits.h>



float convertUnits(float value) {
	return value / 255;
};
	
float convertUnits(float value, float& wS) {
	return ((value / wS) * 2.0f) - 1.0f;
};