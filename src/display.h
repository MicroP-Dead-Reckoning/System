#include "osObjects.h" 

#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_conf.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_lcd.h"
#include <stdio.h>
#include <string.h>


void draw_update(uint8_t direction, uint8_t distance);
void display_test(void);
