#ifndef DISPLAY_H
#define DISPLAY_H
#include "Arduino.h"
#include <LiquidCrystal.h>

typedef enum{ACTUAL, PROMEDIO} modo_t;

class Display{
public:
    Display(int rs, int enable, int d4, int d5, int d6, int d7);
    void updateData(unsigned int ciclos = 0, int temperaturaActual = 0,int temperaturaProm = 0);
    bool printData();
    bool changeDisplayMode();
private:
    LiquidCrystal * lcd = NULL;
    int temperaturaActual;
    int temperaturaProm;
    unsigned int ciclos;
    modo_t displayMode;
};

#endif
