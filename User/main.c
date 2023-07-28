#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"
int main(void)
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	PWM_SetDuty(50); //duty=CCR/(ARR+1),ARR=100-1
	PWM_SetPrescaler(14400-1);  //Frequency=72MHz/(PSC+1)/(ARR+1)=100Hz,ARR=100-1
	OLED_ShowString(1, 1, "Freq:");
	OLED_ShowString(1, 13, "Hz");
	OLED_ShowString(2, 1, "Duty:");
	OLED_ShowString(2, 9, "%");
	while (1)
	{
		OLED_ShowNum(1, 6, Get_Frequency(), 7);
		OLED_ShowNum(2, 6, Get_Duty(), 3);
	}
}
