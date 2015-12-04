#ifndef _INCLUDE_WIRELESS_H_
#define _INCLUDE_WIRELESS_H_

#include "osObjects.h" 

#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_conf.h"
#include "stm32f429i_discovery.h"
#include <stdio.h>
#include <string.h>
#include "cc2500.h"
				
void recv_data(void const *argument);				
//void test_control_read(void);
//void test_read_write(void);
//void test_wireless(void);

#endif
