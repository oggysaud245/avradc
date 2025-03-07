#include "adc.h"

MYADC::MYADC(){
    init();
}
void MYADC::init()
{
    // Set the reference voltage to default AVCC
    setReference();
    // Set the prescaler to default 128
    setPrescaler();
    // Enable the ADC
    ADCSRA |= (1 << ADEN);
    // Set the auto trigger to default false
    setAutoTrigger();
}
uint16_t MYADC::read(uint8_t channel) {
    if(channel > 6) return 0; // If the channel is invalid, return 0
    channel =   channel & 0x07; // Make sure the channel is within 0-6
    // Disable the digital input buffer on the ADC pin
    DIDR0 |= (1 << channel);
    // Set the channel
    ADMUX = (ADMUX & 0xF8) | (channel); // Clear the older channel and set the new one
    // Start the conversion
    ADCSRA |= (1 << ADSC);
    // Wait for the conversion to complete
    while (ADCSRA & (1 << ADSC));
    stop(channel);
    // Return the result
    return ADCW; // ADCW is the combined result of ADCL and ADCH, defined in avr/io.h macro
}
void MYADC::stop(uint8_t channel) {
    // Re-enable the digital input buffer on the ADC pin
    DIDR0 &= ~(1 << channel);
}
void MYADC:: stopADC(){
    // Disable the ADC
    ADCSRA &= ~(1 << ADEN);
    // Re-enable the digital input buffer on all ADC pins
    DIDR0 = 0x00;
}
void MYADC::setReference(uint8_t ref){
    if(ref == AVCC){

        ADMUX |= SET_AVCC_AS_REF;

    }else if(ref == INTERNAL_1_1V){

        ADMUX |= SET_INTERAL_1_1V_AS_REF;

    }else if(ref == EXTERNAL){

        ADMUX |= SET_EXTERNAL_REF;

    }
}
void MYADC::setPrescaler(uint8_t prescaler){
    if(prescaler == PRESCALER_2){

        ADCSRA |= SET_ADC_PRESCALER_2;

    }else if(prescaler == PRESCALER_4){

        ADCSRA |= SET_ADC_PRESCALER_4;

    }else if(prescaler == PRESCALER_8){

        ADCSRA |= SET_ADC_PRESCALER_8;

    }else if(prescaler == PRESCALER_16){

        ADCSRA |= SET_ADC_PRESCALER_16;

    }else if(prescaler == PRESCALER_32){

        ADCSRA |= SET_ADC_PRESCALER_32;

    }else if(prescaler == PRESCALER_64){

        ADCSRA |= SET_ADC_PRESCALER_64;

    }else if(prescaler == PRESCALER_128){

        ADCSRA |= SET_ADC_PRESCALER_128;  

    }
}
void MYADC::setAutoTrigger(bool autoTrigger){
    if(autoTrigger){

        ADCSRA |= (1 << ADATE);

    }else{

        ADCSRA &= ~(1 << ADATE);

    }
    triggerSource(FREE_RUNNING);
}
void MYADC::triggerSource(uint8_t source){
    if(source == FREE_RUNNING){

        ADCSRB |= SET_FREE_RUNNING_MODE;

    }else if(source == ANALOG_COMPARATOR){

        ADCSRB |= SET_ANALOG_COMPARATOR_MODE;

    }else if(source == EXTERNAL_INTERRUPT_REQUEST_0){

        ADCSRB |= SET_EXTERNAL_INTERRUPT_REQUEST_0_MODE;

    }else if(source == TIMER0_COMPARE_MATCH_A){

        ADCSRB |= SET_TIMER0_COMPARE_MATCH_A_MODE;

    }else if(source == TIMER0_OVERFLOW){

        ADCSRB |= SET_TIMER0_OVERFLOW_MODE;

    }else if(source == TIMER_COMPARE_MATCH_B){

        ADCSRB |= SET_TIMER_COMPARE_MATCH_B_MODE;

    }else if(source == TIMER1_OVERFLOW){

        ADCSRB |= SET_TIMER1_OVERFLOW_MODE;

    }
}
void MYADC::enableInterrupt(){
    ADCSRA |= (1 << ADIE);
}
void MYADC::disableInterrupt(){
    ADCSRA &= ~(1 << ADIE);
}
uint8_t MYADC::getCurrentChannel(){
    return currentChannel;
}