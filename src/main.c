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

void draw_pos(void const *argument){
	while(1){
		//LCD_DrawUniLine(100, 100, 230, 230);
		osDelay(250);
	}
}

osThreadDef(recv_data, osPriorityNormal, 1, 0);
osThreadDef(draw_pos, osPriorityNormal, 1, 0);
//osThreadDef(my_example, osPriorityNormal, 1, 0);
//// ID for theads
osThreadId recv_data_thread;
osThreadId draw_pos_thread;
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
	
	LCD_Clear(LCD_COLOR_WHITE);
	memcpy ( (void *)(LCD_FRAME_BUFFER + BUFFER_OFFSET), (void *) &Image, sizeof(Image));
		
	osDelay(250);
	CC2500_SPI_INIT();
	osDelay(250);
	

	
	
	
	
	recv_data_thread = osThreadCreate(osThread(recv_data), NULL);
	draw_pos_thread = osThreadCreate(osThread(draw_pos), NULL);
	//my_example_thread = osThreadCreate(osThread(my_example), NULL);
	
	osKernelStart ();                         // start thread execution 
}


