# AVR ADC Project

This project demonstrates how to use the Analog-to-Digital Converter (ADC) on an ATmega328P microcontroller. The example reads the value of ADC channel 0 and prints it to the serial monitor. The default reference voltage is AVCC, but it can be changed to internal 1.1V or an external reference voltage. The default prescaler is 128, but it can be adjusted to 2, 4, 8, 16, 32, 64, or 128. The default trigger source is free running mode, but it can be changed to analog comparator, external interrupt request 0, timer0 compare match A, timer0 overflow, timer compare match B, or timer1 overflow.

## Features

- Read ADC values from specified channels
- Print ADC values to the serial monitor
- Configurable reference voltage, prescaler, and trigger source
- Supports multiple ADC channels, one at a time

## Requirements

- ATmega328P microcontroller
- AVR-GCC toolchain
- AVRDUDE for programming the microcontroller
- Serial monitor (e.g., Arduino Serial Monitor, PUTTY)

## Usage

1. Connect the ADC channel 0 to a voltage source.
2. Set the baud rate of the serial monitor to 9600.
3. Compile and upload the code to the ATmega328P microcontroller.
4. Open the serial monitor to see the ADC values.

## Code Structure

### `main.cpp`

The main file initializes the ADC and serial communication, reads the ADC value from channel 0, and prints it to the serial monitor.

### `lib/adc/adc.h` and `lib/adc/adc.cpp`

These files contain the `MyADC` class, which provides methods to initialize the ADC, read values from ADC channels, and configure the ADC settings.

#### Public Methods in `MyADC` class:

- `MYADC()`: Constructor that initializes the ADC with default settings.
- `uint16_t read(uint8_t channel)`: Reads the ADC value from the specified channel.
- `void setReference(uint8_t ref)`: Sets the reference voltage for the ADC.
- `void setPrescaler(uint8_t prescaler)`: Sets the prescaler for the ADC.
- `void setAutoTrigger(bool autoTrigger)`: Enables or disables auto-triggering for the ADC.
- `void triggerSource(uint8_t source)`: Sets the trigger source for the ADC.
- `void enableInterrupt()`: Enables the ADC interrupt.
- `void disableInterrupt()`: Disables the ADC interrupt.
- `uint8_t getCurrentChannel()`: Returns the current adc channel in use.

### `lib/serial/serial.h` and `lib/serial/serial.cpp`

These files contain the `Serial` class, which provides methods to initialize serial communication, read and write data, and print values to the serial monitor.

#### Public Methods in `Serial` class:

- `Serial(const uint32_t baud = 9600)`: Constructor that initializes the serial communication with the specified baud rate (default is 9600).
- `void write(uint8_t data)`: Writes a single byte of data to the serial port.
- `bool available()`: Checks if data is available to read from the serial port.
- `uint8_t read()`: Reads a single byte of data from the serial port.
- `void print(const char* str)`: Prints a null-terminated string to the serial port.
- `void print(uint8_t num)`: Prints a uint8_t to the serial port.
- `void print(uint16_t num)`: Prints a uint16_t to the serial port.
- `void print(uint32_t num)`: Prints a uint32_t to the serial port.
- `void println(const char* str)`: Prints a null-terminated string followed by a newline and carriage return to the serial port.
- `void readString(char* buffer, uint8_t maxLength)`: Reads a string from the serial port into the provided buffer.
- `void readStringUntil(char terminator, char* buffer, uint8_t maxLength)`: Reads a string from the serial port into the provided buffer until the terminator character is encountered.

## Example

```cpp
#include <avr/io.h>
#include <util/delay.h>
#include "./lib/adc/adc.h"
#include "./lib/serial/serial.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

MYADC adc;
Serial serial;

int main() {
    while (1) {
        uint16_t value = adc.read(0);
        serial.print("ADC Value: ");
        serial.println(value);
        _delay_ms(1000);
    }
    return 0;
}