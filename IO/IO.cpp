#include "./IO.h"
#include "Arduino.h"
#include "HardwareSerial.h"

IO::IO(int DQpin, int warmP, int ACp){
    static OneWire oneWireObjeto(DQpin);
    static DallasTemperature sensorDS18B20(&oneWireObjeto);

    int numeroSensoresConectados = sensorDS18B20.getDeviceCount();
    if(numeroSensoresConectados==1){
        DeviceAddress sensorTemperatura;
        sensorDS18B20.getAddress(sensorTemperatura, 1);
        for (uint8_t i = 0; i < 8; i++)
        {
            // Si solo tiene un dígito rellenamos con un cero a la izquierda
            if (sensorTemperatura[i] < 16) Serial.print("0");

            // Mostramos los datos que van en HEXADECIMAL
            Serial.print(sensorTemperatura[i], HEX);
        }
    }

    oneWireObj = &oneWireObjeto;
    sensorTemp = &sensorDS18B20;
    sensorTemp->begin();
    pinMode(warmP, OUTPUT);
    pinMode(ACp,INPUT);
    warmPin = warmP;
    ACpin = ACp;
    return;
}

float IO::getTemperature(){
    sensorTemp->requestTemperatures();
    float temp = sensorTemp->getTempCByIndex(0);
    return temp;
}

void IO::toWarm(bool temp){
    if(temp)
        digitalWrite(warmPin, HIGH);
    else
        digitalWrite(warmPin,LOW);
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
