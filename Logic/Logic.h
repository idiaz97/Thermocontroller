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
typedef enum{C_OPENS, C_CLOSES, TEMP_MAX, TEMP_MIN, RESET}event_t


class Logic{
public:
    Logic(IO * temp, Dsiplay * disp);
    //void getNextState();
    void updateSystem();
    //void updateData(int temp, bool isTurnedOn);
    //bool toWarm(bool isTurnedOn); //Devuelve true si el sistema tiene que calentar, y false si tiene que enfriar.
    //char getTempAct();
    //char getTempProm();
    //void resetDangerFlag();
    //void setDangerFlag();
    data_t getData2Save();
    void resetAllData();
    
private:
    Vector temperaturas;
    unsigned int ciclos;
    //bool danger = false;
    //bool waitUntilIsColdAgain = false;
    state_t currentState;
    IO * io;
    Display * display;
};

#endif
