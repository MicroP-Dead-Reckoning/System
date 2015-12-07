#include "display.h"



void display_test(){
	uint16_t buffer[8] = {0, 7, 7, 3, 6, 1, 5, 2};
	for (int i = 0; i < 8; i=i+2){
		draw_update(buffer[i], buffer[i+1]);
	}
}
