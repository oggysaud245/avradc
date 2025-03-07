#ifndef SERIAL_H
#define SERIAL_H

#include <avr/io.h>
#include <stdlib.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
class Serial {
public:
    Serial(const uint32_t baud = 9600);
    void write(uint8_t data);
    bool available();
    uint8_t read();
    void print(char* str);
    void print(uint8_t num);
    void print(uint16_t num);
    void print(uint32_t num);
    void println(char* str);    
    void readString(char* buffer, uint8_t maxLength);
    void readStringUntil(char terminator, char* buffer, uint8_t maxLength);

private:
    void begin(const uint16_t baud);
    uint16_t ubrr;
};

#endif // SERIAL_H