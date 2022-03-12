#include "MyStm32f407xx.h"

void lock(void);
void unlock(void);
void alarm_act_deact(void);
void light_approach(void);
void delay(void);
void encryption(void);
uint32_t c;


int main(void)
{    
    GPIO_Handle_t GpioLedGreen,GpioLedOrange,GpioLedRed,GpioLedBlue,GpioBtn;
    GpioLedGreen.pGPIOx = GPIOD;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedGreen);

    GpioBtn.pGPIOx = GPIOA;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_NO_PUPD;
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GpioBtn);

    GpioLedOrange.pGPIOx = GPIOD;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedOrange);

    GpioLedRed.pGPIOx = GPIOD;
    GpioLedRed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    GpioLedRed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedRed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLedRed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedRed);

    GpioLedBlue.pGPIOx = GPIOD;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedBlue);

    int cnt =0;

	while(1)
	{    


		if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)== ENABLE)
		 {
		          delay();
		         cnt = cnt+ 1;
		        }
		   if (cnt == 3)
		         {
		             lock();
		         }
		    else if (cnt == 9)
		         {
		                unlock();
		          }
		        else if (cnt==18)
		          {
		               alarm_act_deact();
		            }
		            else if (cnt==27)
		            {
		            	 light_approach();
		            }


	}
	return 0;
}


void delay(void)
{
	for(uint32_t i=0;i<5000000;i++);
}


void encryption(void)
{
	uint32_t a=2,b=4;
	c= a+b;
}



void lock(void)
{

		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_SET);


}
void unlock(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_RESET);


}void alarm_act_deact(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_SET);
	delay();

}
void light_approach(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_SET);
	delay();

}