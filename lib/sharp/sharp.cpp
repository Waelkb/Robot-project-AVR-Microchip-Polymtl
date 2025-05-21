/*Sortie de tension : La sortie (V<sub>O</sub>) varie en fonction de la distance entre le capteur et l'objet,
allant typiquement de 0,25V (à 80 cm) à environ 2,15V (à 10 cm).*/

#include "sharp.h"
#include <util/delay.h>


Sharp::Sharp(Pin pin) : pin_(pin), can_() {
    initialisation();
}

void Sharp::initialisation() {
    DDRA &= ~(1 << pin_);
}

uint8_t Sharp::getAnalogValue() {
    return (can_.lecture(pin_) >> BITSHIFT);//pin_0 de A
}

bool Sharp::isWithin10cm() {
    uint8_t analogValue = getAnalogValue();
    return analogValue >= ANALOG_VALUE_10CM;
}

bool Sharp::isWithin80cm() {
    uint8_t analogValue = getAnalogValue();
    return analogValue >= ANALOG_VALUE_80CM;
}

bool Sharp::isWithin80cm(uint16_t delayMs) {
    for (uint16_t i = 0; i < delayMs; i++) {
        if (isWithin80cm()) {
            return true;
        }
        _delay_ms(CHECK_DELAY_MS);
    }
    return false;
}

