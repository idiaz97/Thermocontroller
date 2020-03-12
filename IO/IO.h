//////////////////////////////////////////////////////////////////////////////////////////
//              Libreria Input/Output para el controlador de la termocupla              //
//                                  Ian Diaz                                            //
//                                 Enero 2020                                           //
//////////////////////////////////////////////////////////////////////////////////////////

/* Hace falta conectar y especificar los pines de los sensores y el rele
        DQ -> PIN SENSOR TEMPERATURA
        warmPin -> PIN DEL RELE QUE CIERRA EL LAZO
        ACpin -> PIN DEL SENSOR MID400
*/

#ifndef IO_H
#define IO_H
#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class IO{
public:
    IO(int DQpin, int warmPin, int ACpin); //Constructor, que se le debe pasar el numero de los pines especificados
    char getTemperature();          //Devuelve la temperatura que mide el sensor en este instante de tiempo.
    bool isCircuitClosed();         //Devuelve true si el circuito esta cerrado, false en caso contrario
    void toWarm(bool temp);         //Enciende el calentadorsi recibe true, lo apaga si recibe false
private:
    OneWire * oneWireObj;
    DallasTemperature * sensorTemp;
    int warmPin;
    int ACpin
};




#endif