#include "recv_data.h"

#define TOTAL_STEPS 100


int total = 0;


void wireless_recv(void){

	uint8_t res2[3];
	
	CC2500_Read(res2, CC2500_FREQ_REG, 3);
	printf("result = %x, %x, %x\n", res2[0], res2[1], res2[2]);
	
}	

uint8_t recieve[2*TOTAL_STEPS];
uint8_t num;
void EXTI4_IRQHandler() {
	int i;
	if (EXTI_GetITStatus(CC2500_SPI_INT1_EXTI_LINE) != RESET){
		CC2500_Read_SR(&num, 0x3B);
		CC2500_Read_RX(recieve, num);
		for(i = 0; i < num; i++){
			printf("%d, ", recieve[i]);
		}
		printf("\n");
		EXTI_ClearITPendingBit(CC2500_SPI_INT1_EXTI_LINE);
	}
}



void recv_data(void const *argument){
		//test_control_read();
	int i = 0;
		while(1){
//			osSignalWait(SIGNAL_DATA_READY, osWaitForever);
//			CC2500_Read_RX(&recv_dir[i], 1);
//			CC2500_Read_RX(&recv_dist[i], 1);
//			if(recv_dir[i] == 69){
//				total = i;
//				break;
//			}
//			i = (i + 1) % TOTAL_STEPS;
//		}
//		for(i = 0; i < total; i++){
//			printf("%d: dir: %d, dist: %d\n", i, recv_dir[i], recv_dist[i]);
		}
}
