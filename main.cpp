/*
This is a simple example of how to use the ADC library.
This example will read the value of the ADC channel 0 and print it to the serial monitor.
Check the serial monitor to see the results. Set the baud rate to 9600. Serial library does not support other  baud rates for now.
Don't forget to connect the ADC channel 0 to a voltage source.
Default reference voltage is AVCC. You can change it to internal 1.1V or external reference voltage.
Default prescaler is 128. You can change it to 2, 4, 8, 16, 32, 64, 128.
Default trigger source is free running mode. You can change it to analog comparator, external interrupt request 0, timer0 compare match A, timer0 overflow, timer compare match B, timer1 overflow, timer1 compare match B.

Author: Ramesh Saud aKa oggy

*/
#include<avr/io.h>
#include<util/delay.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include "./lib/adc/adc.h"
#include "./lib/serial/serial.h"

MYADC adc;
Serial serial;

int main(){   
    while(1){
        uint16_t value = adc.read(0);
        serial.print((char*)"ADC Channel: ");
        serial.print(adc.getCurrentChannel());
        serial.print((char*)", Value: ");
        serial.print(value);
        serial.println((char*)"");
        _delay_ms(500);
    }
    return 0;
}