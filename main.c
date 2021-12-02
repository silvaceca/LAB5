//question 3
#include "msp430G2553.h"
void main(void)
{
 WDTCTL = WDTPW + WDTHOLD;  // Stop WDT
 P1DIR |= BIT6;             // P1.6 to output
 TA0CTL = TASSEL_2 + MC_1 + ID_3 + TACLR; //+TACLR; SMLCK, up mode, frequency division of 8
 TA0CCR0 = 31250; // Set maximum count value (PWM Period)
 TA0CCR1 = 6250; // initialize counter compare value 31250/6250 = 20%
 TA0CCTL0 |= CCIE; //timer 1
 TA0CCTL1 |= CCIE; //timer 2
 TA0CCTL0 &=~CCIFG; //timer 1 limit reset
 TA0CCTL1 &=~CCIFG; //timer 2 limit reset
 _enable_interrupts(); // Enter LPM0 SMCLK,ACLK active with 56 micro amp current
}
#pragma vector = TIMER0_A0_VECTOR       //define the interrupt service vector
__interrupt void TA0_ISR (void)    // interrupt service routine
    {
    P1OUT |=BIT6; //turn on at timer 1
    TA0CCTL0 &=~CCIFG; //timer 1
    }
#pragma vector = TIMER0_A1_VECTOR       //define the interrupt service vector
__interrupt void TA1_ISR (void)    // interrupt service routine
    {
    P1OUT &=~BIT6; //turn off at timer 2
    TA0CCTL1 &=~CCIFG; //timer 2
    }
