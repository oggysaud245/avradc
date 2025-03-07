#ifndef ADC_H
#define ADC_H
#endif
#include<avr/io.h>
#include<util/delay.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define AVCC 0
#define INTERNAL_1_1V 1
#define EXTERNAL 2

#define SET_AVCC_AS_REF (1 << REFS0)
#define SET_INTERAL_1_1V_AS_REF ((1 << REFS1) | (1 << REFS0))
#define SET_EXTERNAL_REF (~(1 << REFS0) | ~(1 << REFS1))

#define PRESCALER_2 2
#define PRESCALER_4 4
#define PRESCALER_8 8
#define PRESCALER_16 16
#define PRESCALER_32 32
#define PRESCALER_64 64
#define PRESCALER_128 128

#define SET_ADC_PRESCALER_2 (1 << ADPS0)
#define SET_ADC_PRESCALER_4 (1 << ADPS1)
#define SET_ADC_PRESCALER_8 ((1 << ADPS1) | (1 << ADPS0))
#define SET_ADC_PRESCALER_16 (1 << ADPS2)
#define SET_ADC_PRESCALER_32 ((1 << ADPS2) | (1 << ADPS0))
#define SET_ADC_PRESCALER_64 ((1 << ADPS2) | (1 << ADPS1))    
#define SET_ADC_PRESCALER_128 ((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0))

#define FREE_RUNNING 0
#define ANALOG_COMPARATOR 1
#define EXTERNAL_INTERRUPT_REQUEST_0 2
#define TIMER0_COMPARE_MATCH_A 3
#define TIMER0_OVERFLOW 4
#define TIMER_COMPARE_MATCH_B 5
#define TIMER1_OVERFLOW 6
#define TIMER1_COMPARE_MATCH_B 7
#define SET_FREE_RUNNING_MODE (1 << ADTS0)
#define SET_ANALOG_COMPARATOR_MODE (1 << ADTS1)
#define SET_EXTERNAL_INTERRUPT_REQUEST_0_MODE ((1 << ADTS1) | (1 << ADTS0))
#define SET_TIMER0_COMPARE_MATCH_A_MODE (1 << ADTS2)
#define SET_TIMER0_OVERFLOW_MODE ((1 << ADTS2) | (1 << ADTS0))
#define SET_TIMER_COMPARE_MATCH_B_MODE ((1 << ADTS2) | (1 << ADTS1))
#define SET_TIMER1_OVERFLOW_MODE ((1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0))

class MYADC {
    public:
        MYADC();
        uint16_t read(uint8_t channel);
        void setReference(uint8_t ref = AVCC);
        void setPrescaler(uint8_t prescaler = PRESCALER_128);
        void setAutoTrigger(bool autoTrigger = false); 
        void triggerSource(uint8_t source = FREE_RUNNING);
        void enableInterrupt();
        void disableInterrupt();
        void stopADC();
        uint8_t getCurrentChannel();
    private:
        uint8_t currentChannel;
        void init();
        void stop(uint8_t channel);
};
