#ifndef LED_H
#define LED_H

#include "constants.h"
#include <avr/io.h>
#include <util/delay.h>

class Led {
  public:
    Led(Port port, Pin pin1, Pin pin2);

    void showGreen(uint16_t delayMs);
    void showRed(uint16_t delayMs);
    void showAmber(uint16_t delayMs);
    void showOff(uint16_t delayMs);

    void blinkGreen(uint16_t delayMs);
    void blinkRed(uint16_t delayMs);
    void blinkAmber(uint16_t delayMs);

private:
    Port port_;
    Pin pin1_;
    Pin pin2_;
    volatile uint8_t *ddr_; // Pointeur vers DDRx
    volatile uint8_t *por_; // Pointeur vers PORTx

    void configurePort(Port port); // Méthode de configuration du port
    void showGreen();
    void showRed();
    void showOff();


};

#endif