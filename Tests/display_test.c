#include "display.h"



void display_test(){
	uint16_t buffer[6] = {0, 5, 1, 4, 4, 2};
	for (int i = 0; i < 6; i=i+2){
		draw_update(buffer[i], buffer[i+1]);
	}
}
