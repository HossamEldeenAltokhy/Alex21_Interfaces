#include "config.h"
#include "mADC.h"
#include <avr/io.h>

void init_ADC(int ch, int ref, int prescaler) {
    // Write Code Here
    /**
     * ADMUX :

        - Select Channel.
        - Select Voltage Reference.
        - Select Adjust mode. (neglect)

        ADCSRA: 
        - Enable ADC.
        - Enable Interrupt.(neglect)
        - Auto Trigger Mode.(neglect)
        - Prescaler.

     */
}

void ADC_StartConv() {
    ADCSRA |= (1 << ADSC); // Start Conversion
}

int ADC_read() {
    while (!(ADCSRA & (1 << ADIF)));
    int x = ADCL;
    x |= (ADCH << 8);
    return x;
}