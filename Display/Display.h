//////////////////////////////////////////////////////////////////////////////////////////
//              Libreria display para el controlador de la termocupla                   //
//                                  Ian Diaz                                            //
//                                 Enero 2020                                           //
//////////////////////////////////////////////////////////////////////////////////////////

/* Hace falta conectar y especificar los pines del display dichos a continuacion
    RS  E   D4  D5  D6  D7
    No olvidar de conectar y ajustar el brillo de la pantalla con los pines
    A   K
*/


#ifndef DISPLAY_H
#define DISPLAY_H
#include "Arduino.h"
#include <LiquidCrystal.h>

typedef enum{ACTUAL, PROMEDIO} modo_t;

class Display{
public:
    Display(int rs, int enable, int d4, int d5, int d6, int d7); //Se necesitan especificar donde estan conectados esos pines del display.
    void updateData(unsigned int ciclos, char temperaturaActual,char temperaturaProm);//Funcion encargada de actualizar los datos, no
                                                                                                //los imprime en el LCD
    bool printData();   //Funcion utilizada para imprimir en pantalla, devuelve false en caso de que haya habido un error
    bool changeDisplayMode(); //Funcion utilizada para cambiar el modo de dislay de Actual, a promediado. devuelve false en caso de que haya error.
    
private:
    LiquidCrystal * lcd = NULL;
    char temperaturaActual;
    char temperaturaProm;
    unsigned int ciclos;
    modo_t displayMode;
};

#endif
