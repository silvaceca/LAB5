Question 1 is a 256 ms delay timer. This is done by using a clock divier DIVS3 and WDT MDLY 32. The second question is a pwm signal with a 10% duty cycle. The time period was cacluated with the divdider, and the frequency and assigned in the TACCR0 value, and TACCR1 value was determined off the percentage of TACCR0 to achieve a duty cycle of 10%. Question 3 used hardware to demonstrate pwm. TACCR0 was cacluated for a different period. TWo clocks were used to tell the light to turn on and to tuen off making it a PWM output.
