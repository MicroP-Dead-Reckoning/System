/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module

#include "osObjects.h" 

#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_conf.h"
#include "stm32f429i_discovery.h"
#include <stdio.h>
#include <string.h>
#include "cc2500.h"

#define FUCK_EVERYTHING 1
const uint8_t PARTNUM = 128, VERSION = 3;

uint8_t recv_buffer[20];
uint8_t num;
int TEST_VALUE = 0;


void EXTI4_IRQHandler() {
	int i;
	if (EXTI_GetITStatus(CC2500_SPI_INT1_EXTI_LINE) != RESET){
		CC2500_Read_SR(&num, 0x3B);
		CC2500_Read_RX(recv_buffer, num);
		for(i = 0; i < num; i++){
			printf("%d, ", recv_buffer[i]);
		}
		printf("\n");
		EXTI_ClearITPendingBit(CC2500_SPI_INT1_EXTI_LINE);
	}
}


void test_control_read(void) {
	uint8_t x;
	CC2500_Read_SR(&x, CC2500_PARTNAME);
	printf("%d\t", x);
	CC2500_Read_SR(&x, CC2500_VERSION);
	printf("%d\n", x);
}


void test_wireless(void){
	while(1);
}	

void transmit_data(void const *argument){
	test_control_read();
	CC2500_INT_INIT();
	uint8_t res2[3];	
	CC2500_Read(res2, CC2500_FREQ_REG, 3);
	printf("result = %x, %x, %x\n", res2[0], res2[1], res2[2]);
	while(1){
		uint8_t x = FUCK_EVERYTHING;	// doesn't work without some assignment
	}
}

osThreadDef(transmit_data, osPriorityNormal, 1, 0);
//osThreadDef(example_1b, osPriorityNormal, 1, 0);
//osThreadDef(example_1c, osPriorityNormal, 1, 0);
//osThreadDef(my_example, osPriorityNormal, 1, 0);
//// ID for theads
osThreadId transmit_data_thread;
//osThreadId example_1b_thread;
//osThreadId example_1c_thread;
//osThreadId my_example_thread;

/*
 * main: initialize and start the system
 */
int main (void) {
  osKernelInitialize ();                    // initialize CMSIS-RTOS
	
	osDelay(250);
	CC2500_SPI_INIT();
	osDelay(250);
	
	
	transmit_data_thread = osThreadCreate(osThread(transmit_data), NULL);
	//example_1b_thread = osThreadCreate(osThread(example_1b), NULL);
	//example_1c_thread = osThreadCreate(osThread(example_1c), NULL);
	//my_example_thread = osThreadCreate(osThread(my_example), NULL);
	
	osKernelStart ();                         // start thread execution 
}


