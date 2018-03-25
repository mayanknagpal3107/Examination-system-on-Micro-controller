
/* project2:  To make project online examination system with dynamic question.
               total 5 question is randomly generated into 7 question..*/ 

#include <avr/io.h>
#include <stdlib.h>     //for rand function
#include <compat/deprecated.h>
#include <util/delay.h>
#include "uart.h"
#include "uart.c"
#include <avr/interrupt.h>
#define GetRandomnumber() ((rand() % 7) + 1)     //macro for generate random number between 1 to 7



void main()
{

	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	sei();
start:	

	_delay_ms(1000);
	uart_puts("welcome to ");
	uart_puts("Edubotix mock test \n\r");
	
	uart_puts("enter your name \n\r");
	uart_puts("for next press1 \n\r");

	unsigned int c;
	unsigned char buff[15]={0};
	unsigned char buff1[15]={0};
	unsigned char buff2[15]={0};
	unsigned char buff3[2]={0};
	unsigned char buff4[2]={0};
	int i=0,j=0,m=0;
	int marks=0;
	DDRC=0xff;

    int RandomNumber;
	srand(50);
	int num=0;





	while(1)   //enter name
	{
	
		 c=uart_getc();
		 
		 if(!(c&UART_NO_DATA))
		 {
			 if(c=='1')
			 {
				_delay_ms(10);
				//sbi(PORTC,2);
				
				uart_puts("\n\r");
				uart_puts("enter your Roll Number\n\r");
				uart_puts("for next press N \n\r");
				i=0;
		       _delay_ms(100);
			   
			  goto next;
			 }
			
			 
			 buff1[i]=c;
			 uart_putc(c);
			 i++;
		  
		 }

	}
	
	

	
	while(1)   //enter roll number
	{
next: 
		
		c=uart_getc();
		 
		 if(!(c&UART_NO_DATA))
		 {
			 if(c=='N')
			 goto jj;
			 
			// if(i>3)
			// goto ee;
			 
			 buff2[i]=c;
			 uart_putc(c);
			 i++;
		  
		 }
	}



	while(1)   //start of search while
	{
jj:	
	c=uart_getc();
		 
	    if(!(c&UART_NO_DATA))
	    {
				
			if(c=='N')
			{
		 aa:
			   RandomNumber = GetRandomnumber();	 //get random number

				for(m=0;m<j;m++)       //if number is repeat goto aa lable to find another number
				{			
					if(buff[m]==RandomNumber)
					{				
						goto aa;					
					}				
					
				}	
						
										
				buff[j]=RandomNumber;
				j++;
				//itoa(RandomNumber,buff3,10);
				_delay_ms(10);

				//uart_puts(buff3);
				_delay_ms(20);
				if(j==5)
				{
				j=0;
				}

				
					
					if(num==5)   //if total 5 question is comes num value will be 5 and display result
					{
							uart_puts("\n\r");					
							uart_puts("\n\r");					
							uart_puts("............EXAM RESULT............ \n\r");					
							//uart_puts("RESULT \n\r");					
					//goto ss;


							uart_puts("YOUR NAME:  ");
							uart_puts(buff1);
							uart_puts("\n\r");
							
							
							uart_puts("YOUR ROLL NO:  ");
							uart_puts(buff2);
							uart_puts("\n\r");
							
							
							uart_puts("YOUR MARKS:  ");
							itoa(marks,buff4,10);
							uart_puts(buff4);
							uart_puts("\n\r");

							if(marks<3)
							{	
								uart_puts("RESULT:  FAIL \n\r");	
							}
							
							else		
							uart_puts("RESULT:  PASS \n\r");	
							
							while(1)
							{
							
								c=uart_getc();
								if(!(c&UART_NO_DATA))
								 {
									 if(c=='A')
									 goto start;
								 } 
									 
							}
			 
					}
					
					else         //randomly question is comes
					{
					
						if(RandomNumber==1)
						{
							num++;					
											
							uart_puts("\n\r");
							uart_puts("\n\r");
							uart_puts("Q:   HOW MANY PORTS IN ATMEGA16?? \n\r" );
							uart_puts("\n\r");
							uart_puts("A: 1    B:2    C:3    D:4 \n\r" );
							
							while(1)
							{
								c=uart_getc();
								sbi(PORTC,3);
								 if(!(c&UART_NO_DATA))
								 {
									 if(c=='A')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='B')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='C')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='D')
									 {
										marks++;
										uart_puts("right");
									_delay_ms(100);
									goto jj;
								 } 
							  
							 }
						}

											
						}				
						
						if(RandomNumber==2)
						{
							num++;
							uart_puts("\n\r");
							uart_puts("Q:   HOW MANY ADC PINS IN ATMEGA16 \n\r" );
							uart_puts("\n\r");
							uart_puts("A:5    B:8    C:10   D:6 \n\r" );
							_delay_ms(100);
			
							while(1)
							{
								c=uart_getc();
								 
								if(!(c&UART_NO_DATA))
								{
									 if(c=='A')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='D')
									 {
								     uart_puts("wrong");
								     goto jj;
								     }
									 
									 if(c=='C')
									 {
								     uart_puts("wrong");
								     goto jj;
								     }
									 
									 if(c=='B')
									 {
										marks++;
										uart_puts("right");
										_delay_ms(100);
										goto jj;
									 } 
								  
								}
							}				
						
						}				
						
						if(RandomNumber==3)
						{
							num++;
							
							uart_puts("\n\r");
							uart_puts("Q:  HOW MANY FLASH MEMORY IN ATMEGA16 \n\r" );
							uart_puts("\n\r");
							uart_puts("A:4Kb   B:16kb     C:8kb    D:6kb \n\r" );
							_delay_ms(100);
							
							while(1)
							{
								c=uart_getc();
								 
								if(!(c&UART_NO_DATA))
								{
									 if(c=='A')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='D')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='C')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='B')
									 {
										marks++;
										uart_puts("right");
										_delay_ms(100);
										goto jj;
									 } 
								  
								}
							}
						}				
						
						if(RandomNumber==4)
						{
							num++;						
							uart_puts("\n\r");
							uart_puts("Q: HOW MANY INTERRUPTS IN ATMEGA 16 MICROCONTROLLER \n\r" );
							uart_puts("\n\r");
							uart_puts("A:21    B:22   C:23  D:24 \n\r" );
							_delay_ms(100);
								
							while(1)
							{
								c=uart_getc();
							
								if(!(c&UART_NO_DATA))
								{
									 if(c=='C')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='D')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='B')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='A')
									 {
										marks++;
										uart_puts("right");
										_delay_ms(100);
										goto jj;
									 } 
								  
								}
							}
						}				
						
						if(RandomNumber==5)
						{
						        num++;								
								uart_puts("\n\r");
								uart_puts("Q: HOW MANY PWM CHANNEL IN ATMEGA 16 MICROCONTROLLER\n\r" );
								uart_puts("\n\r");
								uart_puts("A:1    B:2   C:3  D:4 \n\r" );
								_delay_ms(100);
								
							while(1)
							{
								c=uart_getc();
								 
								 if(!(c&UART_NO_DATA))
								 {
									 if(c=='A')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='B')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }

									 if(c=='C')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='D')
									 {
										marks++;
										uart_puts("right");
										_delay_ms(100);
										goto jj;
									 } 
								  
								 }
							}
						}
						
						if(RandomNumber==6)
						{
							num++;							
							uart_puts("\n\r");
							uart_puts("Q: HOW MANY 8 BIT TIMER IN ATMEGA 16 MICROCONTROLLER\n\r" );
							uart_puts("\n\r");
							uart_puts("A:1    B:2   C:3  D:4 \n\r" );
							_delay_ms(100);
									
								while(1)
								{
									c=uart_getc();
									 
									 if(!(c&UART_NO_DATA))
									 {
										 if(c=='A')
										 {
										 uart_puts("wrong");
										 goto jj;
										 }
										 
										 if(c=='D')
										 {
										 uart_puts("wrong");
										 goto jj;
										 }
										 
										 if(c=='C')
										 
										 {
										 uart_puts("wrong");
										 goto jj;
										 }
										 
										 if(c=='B')
										 {
											marks++;
											uart_puts("right");
										    _delay_ms(100);
											goto jj;
										 } 
									  
									 }
								}
	
						}
						
						
						
						if(RandomNumber==7)
						{
						    num++;					
							uart_puts("\n\r");
							uart_puts("Q:   HOW MANY TOTAL TIMERS IN ATMEGA16  MICROCONTROLLER\n\r" );
							uart_puts("\n\r");
							uart_puts("A:1    B:2   C:3  D:4 \n\r" );
							_delay_ms(100);
									
							while(1)
							{
								c=uart_getc();
								 
								 if(!(c&UART_NO_DATA))
								{
									 if(c=='A')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='D')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='B')
									 {
									 uart_puts("wrong");
									 goto jj;
									 }
									 
									 if(c=='C')
									 {
										marks++;
										uart_puts("right");
										_delay_ms(100);
										goto jj;
									 } 
								  
								}
							}		
						}
						
						
						
						
						
					}//end of else part
				
			}
		}			
	
	}  //end of search while
} // end of main	
	

			 


		
	