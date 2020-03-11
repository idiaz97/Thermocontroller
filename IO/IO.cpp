#include "./IO.h"

IO::IO(int DQpin){
    static OneWire oneWireObjeto(DQpin);
    static DallasTemperature sensorDS18B20(&oneWireObjeto);
    oneWireObj = &oneWireObjeto;
    sensorTemp = &sensorDS18B20;
    sensorTemp->begin();
    return;
}

char IO::getTemperature(){
    sensorTemp->requestTemperatures();
    char temp = sensorDS18B20->getTempCByIndex(0);
    return temp;
}