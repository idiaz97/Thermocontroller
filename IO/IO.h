#ifndef IO_H
#define IO_H
#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class IO{
public:
    IO(int DQpin, int warmPin, int ACpin);
    char getTemperature();
    bool isCircuitClosed();
    void toWarm(bool temp);
private:
    OneWire * oneWireObj;
    DallasTemperature * sensorTemp;
    int warmPin;
    int ACpin
};




#endif