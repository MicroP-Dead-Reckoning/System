/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module

#include "all_wireless_tests.h"
#include "Image.h"

#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_l3gd20.h"


static void delay(__IO uint32_t nCount)
{
  __IO uint32_t index = 0; 
  for(index = 100000*nCount; index != 0; index--)
  {
  }
}

void recv_data(void const *argument){
		test_control_read();
		while(1){
			test_wireless();
			osDelay(100);
		}
}

osThreadDef(recv_data, osPriorityNormal, 1, 0);
//osThreadDef(example_1b, osPriorityNormal, 1, 0);
//osThreadDef(example_1c, osPriorityNormal, 1, 0);
//osThreadDef(my_example, osPriorityNormal, 1, 0);
//// ID for theads
osThreadId recv_data_thread;
//osThreadId example_1b_thread;
//osThreadId example_1c_thread;
//osThreadId my_example_thread;

/*
 * main: initialize and start the system
 */
int main (void) {
  osKernelInitialize ();                    // initialize CMSIS-RTOS
	
	LCD_Init();
  
  /* LCD Layer initiatization */
  LCD_LayerInit();
    
  /* Enable the LTDC controler */
  LTDC_Cmd(ENABLE);
  
  /* Set LCD foreground layer as the current layer */
  LCD_SetLayer(LCD_FOREGROUND_LAYER);
	
	memcpy ( (void *)(LCD_FRAME_BUFFER + BUFFER_OFFSET), (void *) &Image, sizeof(Image));
	
	osDelay(250);
	CC2500_SPI_INIT();
	osDelay(250);
	
	
	recv_data_thread = osThreadCreate(osThread(recv_data), NULL);
	//example_1b_thread = osThreadCreate(osThread(example_1b), NULL);
	//example_1c_thread = osThreadCreate(osThread(example_1c), NULL);
	//my_example_thread = osThreadCreate(osThread(my_example), NULL);
	
	osKernelStart ();                         // start thread execution 
}


