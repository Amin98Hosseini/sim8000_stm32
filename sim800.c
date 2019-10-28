#include "main.h"
#include <stdio.h>

//Variable
uint8_t x=26;
extern uint8_t text[250];

extern unsigned char number_1_1[18];
extern unsigned char number_2_1[18];
extern unsigned char number_3_1[18];
extern unsigned char number_4_1[18];
extern unsigned char number_5_1[18];
extern unsigned char number_6_1[18];
extern unsigned char number_7_1[18];
extern unsigned char number_8_1[18];

//Handler
UART_HandleTypeDef huart1;

//Function
void puts_str(char *str)
{
	while(*str!=0)
	{
	HAL_UART_Transmit(&huart1,(unsigned char *)str,1,10);
	str++;
	}
}

void sim800_Init()
{
//Power key
/*HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
HAL_Delay(100);
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
HAL_Delay(3000);
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);*/

HAL_Delay(8000);
puts_str("AT \r");
HAL_Delay(3000);
	
puts_str("AT+CMGF=1\r");
HAL_Delay(3000);

puts_str("AT+CSMP=49,167,0,241\r");
HAL_Delay(3000);

//puts_str("AT+CSMP=17,167,0,240\r");
//HAL_Delay(3000);

puts_str("AT+COPS=0,0\r");
HAL_Delay(3000);

puts_str("AT+CNMI=2,1,0,1,0\r");
HAL_Delay(3000);

HAL_Delay(1000);

puts_str("AT+CMGDA=DEL ALL\r");
HAL_Delay(4000);
}

void delete_sms()
{
	puts_str("AT+CMGDA=DEL ALL\r");
  HAL_Delay(4000);
}

void send_sms(uint8_t *number,uint8_t *sr)
{
	char buffer[50];
	HAL_Delay(500);
	sprintf(buffer,"AT+CMGS=\"%s\"%c",number,13);
	puts_str(buffer);
	HAL_Delay(500);
	puts_str((char*)sr);
	HAL_Delay(500);
	HAL_UART_Transmit(&huart1,&x,1,10);
	HAL_Delay(500);
}

void read_sms()
{
	HAL_Delay(250);
	puts_str("AT+CMGR=1,1\r");
	
			//if(huart1.RxXferCount==0)
		  HAL_UART_Receive(&huart1,text,249,300);
			for(int i=0;i<=249;i++)
				{
					/*if(text[i]=='9')
					{
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,GPIO_PIN_SET);
						HAL_Delay(25);
						delete_sms();
						break;
					}*/
					
					if(text[i]=='o' && text[i+1]=='p' && text[i+2]=='e' && text[i+3]=='n')
						{
							HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);
							HAL_Delay(200);
							HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);
							
							//Delet All SMS Recive
							puts_str("AT+CMGDA=DEL ALL\r");
							HAL_Delay(250);
							break;
						}
						
					if(text[i]=='A' && text[i+1]=='+')
					 {
						 for(int j=0;j>=15;j++)
							{
								number_1_1[j+3]=text[i+j];
							}
							
						//Delet All SMS Recive
							puts_str("AT+CMGDA=DEL ALL\r");
							HAL_Delay(250);
						break;
					 }
					 
					 if(text[i]=='B' && text[i+1]=='+')
					 {
						 for(int j=0;j>=15;j++)
							{
								number_2_1[j+3]=text[i+j];
							}
							
							//Delet All SMS Recive
							puts_str("AT+CMGDA=DEL ALL\r");
							HAL_Delay(250);
						break;
					 }
					 
					 if(text[i]=='C' && text[i+1]=='+')
					 {
						 for(int j=0;j>=15;j++)
							{
								number_3_1[j+3]=text[i+j];
							}
							
							//Delet All SMS Recive
							puts_str("AT+CMGDA=DEL ALL\r");
							HAL_Delay(250);
						break;
					 }
					 
					 if(text[i]=='D' && text[i+1]=='+')
					 {
						 for(int j=0;j>=15;j++)
							{
								number_4_1[j+3]=text[i+j];
							}
							
							//Delet All SMS Recive
							puts_str("AT+CMGDA=DEL ALL\r");
							HAL_Delay(250);
						break;
					 }
					 
					 if(text[i]=='E' && text[i+1]=='+')
					 {
						 for(int j=0;j>=15;j++)
							{
								number_5_1[j+3]=text[i+j];
							}
							
							//Delet All SMS Recive
							puts_str("AT+CMGDA=DEL ALL\r");
							HAL_Delay(250);
						break;
					 }
					 
					 if(text[i]=='F' && text[i+1]=='+')
					 {
						 for(int j=0;j>=15;j++)
							{
								number_6_1[j+3]=text[i+j];
							}
							
							//Delet All SMS Recive
							puts_str("AT+CMGDA=DEL ALL\r");
							HAL_Delay(250);
						break;
					 }
					 
					 if(text[i]=='G' && text[i+1]=='+')
					 {
						 for(int j=0;j>=15;j++)
							{
								number_7_1[j+3]=text[i+j];
							}
							
							//Delet All SMS Recive
							puts_str("AT+CMGDA=DEL ALL\r");
							HAL_Delay(250);
						break;
					 }
					 
					 if(text[i]=='H' && text[i+1]=='+')
					 {
						 for(int j=0;j>=15;j++)
							{
								number_8_1[j+3]=text[i+j];
							}
							
							//Delet All SMS Recive
							puts_str("AT+CMGDA=DEL ALL\r");
							HAL_Delay(250);
						break;
					 }
				}	
}



void end_call()
{
	char str[50];
	sprintf(str,"ATH;\r");
	puts_str(str);
	HAL_Delay(500);
}

void call_number1()
{
 char str[50];
 sprintf(str,"%s\r",number_1_1);
 puts_str(str);
 HAL_UART_Transmit(&huart1,&x,1,10);
 HAL_Delay(500);	
}

void call_number2()
{
 char str[50];
 sprintf(str,"%s\r",number_2_1);
 puts_str(str);
 HAL_UART_Transmit(&huart1,&x,1,10);
 HAL_Delay(500);	
}

void call_number3()
{
 char str[50];
 sprintf(str,"%s\r",number_3_1);
 puts_str(str);
 HAL_UART_Transmit(&huart1,&x,1,10);
 HAL_Delay(500);	
}

void call_number4()
{
 char str[50];
 sprintf(str,"%s\r",number_4_1);
 puts_str(str);
 HAL_UART_Transmit(&huart1,&x,1,10);
 HAL_Delay(500);	
}

void call_number5()
{
 char str[50];
 sprintf(str,"%s\r",number_5_1);
 puts_str(str);
 HAL_UART_Transmit(&huart1,&x,1,10);
 HAL_Delay(500);	
}

void call_number6()
{
 char str[50];
 sprintf(str,"%s\r",number_6_1);
 puts_str(str);
 HAL_UART_Transmit(&huart1,&x,1,10);
 HAL_Delay(500);	
}

void call_number7()
{
 char str[50];
 sprintf(str,"%s\r",number_7_1);
 puts_str(str);
 HAL_UART_Transmit(&huart1,&x,1,10);
 HAL_Delay(500);	
}

void call_number8()
{
 char str[50];
 sprintf(str,"%s\r",number_8_1);
 puts_str(str);
 HAL_UART_Transmit(&huart1,&x,1,10);
 HAL_Delay(500);	
}

