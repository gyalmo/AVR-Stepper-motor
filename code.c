#define F_CPU
#define F_CPU 800000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "xstepper.h”
int main(void)
{
 DDRC| = 0xFF;                                     // motor
 DDRB &= ~BIT0;                                       // IR sensor
 PORTB|= 0xFF;
 while(1)
{
   if ((PINB&BIT0)==BIT0)
    {
     sprintf("object detected");
     sprint(“open door now”);
     PORTC=0x01;                                      // rotate motor to 80 degree to open door
     _delay_us(1450);
     PORTC = 0X00;
     _delay_us(2000);
    }
   else
   {
    sprintf("no object detected");
    sprint(“ no need to open door ”);
    PORTC = 0X00;                                     // remain closed
    _delay_us(1100);
   }
 }
return 0;
}
