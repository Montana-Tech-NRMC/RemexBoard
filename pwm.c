/*
 * pwm.c
 *
 *  Created on: Oct 26, 2020
 *      Author: Andrew McLinden , Marcus Frisbee
 *
 *
 */
#include "pwm.h"
void init_PWM_A() {
    P1DIR |= PWMPINA;            //set pin 1.6 to output direction
    P1SEL1 |= PWMPINA;            //select pin 1.6 as PWM output
    TB0CCTL1 = OUTMOD_7;
    init_clk_src();
}

void init_PWM_B() {
    P1DIR |= PWMPINB;            //set pin 1.7 to output direction
    P1SEL1 |= PWMPINB;            //select pin 1.7 as PWM output
    TB0CCTL2 = OUTMOD_7;
    init_clk_src();
}

void set_PWM_A(const int in) {
    if(in > MAX){
        TB0CCR1 = MAX;
    }else if(in < MIN){
        TB0CCR1 = MIN;
    }else{
        TB0CCR1 = in;               //period in microseconds that the power is ON.
    }

}

void set_PWM_B(const int in) {
    if(in > MAX){
        TB0CCR2 = MAX;
    }else if(in < MIN){
        TB0CCR2 = MIN;
    }else{
        TB0CCR2 = in;               //period in microseconds that the power is ON.
    }
}

void init_clk_src(){
    TB0CCR0 = 40000;            //Set period of timer B0 Capture/compare 0 register to 2000 us.
    TB0CTL = TBSSEL__SMCLK + MC_1;   //TASSEL_SMCLK selects SMCLK as the clock source and MC_1 tells it to count up to the value in TB0CCr0.
}