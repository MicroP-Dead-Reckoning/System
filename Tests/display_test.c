#include "display.h"



void display_test(){
	uint16_t buffer[4] = {0, 6, 1, 1};
	for (int i = 0; i < 4; i=i+2){
		draw_update(buffer[i], buffer[i+1]);
	}
}
