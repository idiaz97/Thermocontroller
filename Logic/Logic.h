//////////////////////////////////////////////////////////////////////////////////////////
//              Libreria Logica para el controlador de la termocupla              //
//                                  Ian Diaz                                            //
//                                 Enero 2020                                           //
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef LOGIC_H
#define LOGIC_H
#define TEMPERATURA_MAX 55
#define TEMPERATURA_MIN 40
#include "./Vector.h"
//#include "../Display/Display.h"
// Boton de cambio de modo, boton de reset, boton de guardar, rele, display

typedef struct{
    unsigned int ciclos;
    char tempProm;
    bool isCorrupted;
}data_t;

typedef enum{WARMING, COOLING, DANGER, BROKEN}state_t;
typedef enum{C_OPENS, C_CLOSES, TEMP_MAX, TEMP_MIN, RESET, CHANGE_DISP, SAVE, NO_EVENT}event_t


class Logic{
public:
    Logic(IO * temp, Dsiplay * disp); //contrucotr
    //void getNextState();
    void updateSystem();
    //void updateData(int temp, bool isTurnedOn);
    //bool toWarm(bool isTurnedOn); //Devuelve true si el sistema tiene que calentar, y false si tiene que enfriar.
    //char getTempAct();
    //char getTempProm();
    //void resetDangerFlag();
    //void setDangerFlag();
    //data_t getData2Save();
    void resetAllData();
    
private:
    event_t getNextEvent();
    void saveData();
    Vector temperaturas;
    unsigned int ciclos;
    //bool danger = false;
    //bool waitUntilIsColdAgain = false;
    event_t prevEvent;
    state_t currentState;
    IO * io;
    Display * display;
};

#endif
