#include "display.h"


uint16_t x_pos = 100;
uint16_t y_pos = 100;

//STEP = 10 pixels

int UNIT_DIST[8][2] = {{0,10},{7,7},{10,0},{7,-7},{0,-10},{-7,-7},{-10,0},{-7,7}};

#define TO_ANGLE(head, angle) \
        if (head <=7) { \
				    *angle = head*45; \
				}else{ \
					*angle = 1000;\
				}


/*!
	Function converts a distance and direction to an (X,Y) coordinate.
	returns 0 on success, -1 else
*/
int convert_xy(uint8_t direction, uint8_t distance, int *X, int *Y){
	
	if(direction > 7)
		return -1;
	
	*X = distance*UNIT_DIST[direction][0];
	*Y = distance*UNIT_DIST[direction][1];
	
	
	return 0;
}

void draw_update(uint8_t direction, uint8_t distance){
	int x_temp, y_temp;
	uint16_t X, Y;
	convert_xy(direction,distance, &x_temp, &y_temp);
	printf("x_temp: %d\t y_temp: %d\n", x_temp, y_temp);
	X = (uint16_t)((int)x_pos + x_temp);
	Y = (uint16_t)((int)y_pos + y_temp);
	printf("X: %d\t Y: %d\n", X, Y);
	LCD_DrawUniLine(x_pos, y_pos, X, Y);
	x_pos = X;
	y_pos = Y;
}
