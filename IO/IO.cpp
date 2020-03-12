#include "./IO.h"
#include "Arduino.h"

IO::IO(int DQpin, int warmP, int ACp){
    static OneWire oneWireObjeto(DQpin);
    static DallasTemperature sensorDS18B20(&oneWireObjeto);
    oneWireObj = &oneWireObjeto;
    sensorTemp = &sensorDS18B20;
    sensorTemp->begin();
    pinMode(warmP, OUTPUT);
    pinMode(ACp,INPUT);
    warmPin = warmP;
    ACpin = ACp;
    return;
}

char IO::getTemperature(){
    sensorTemp->requestTemperatures();
    char temp = sensorDS18B20->getTempCByIndex(0);
    return temp;
}

void IO::toWarm(bool temp){
    if(temp)
        digitalWrite(warmPin, HIGH);
    else
        digitalWrite(warPin,LOW);
    return;
}

bool IO::isCircuitClosed(){
    bool closed;
    if(digitalRead(ACpin) == HIGH)
        closed = false;
    else   
        closed = true;
    return closed;
}