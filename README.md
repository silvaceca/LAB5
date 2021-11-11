// question 1
#include <msp430.h>
#define RedLED BIT6 // define the red led to 1.6, name it
#define GreenLED BIT0 // define the green led to bit 0, name it
#define ToggleLeds (P1OUT ^= RedLED|GreenLED) //toggle either redled or greenled as POUT
#define Button BIT3 //define button as bit3
void main(void)
{
BCSCTL2 |= DIVS_3;
WDTCTL = WDT_MDLY_32; //create a 256 ms interval
IE1 |= WDTIE;
P1DIR = RedLED|GreenLED; //set as an input
P1OUT = RedLED;
_enable_interrupts(); //enables interrupt
LPM1; //SMCLK,ACLK are active with no micro amp current
}
#pragma vector = WDT_VECTOR
__interrupt void WDT(void)
{
P1OUT = ToggleLeds; //switch p1out to the other led at an interval of 64ms
}
