#ifndef LOGIC_H
#define LOGIC_H
#define TEMPERATURA_MAX 55
#define TEMPERATURA_MIN 40
#include <vector.h>
#include "../Display/Display.h"
// Boton de cambio de modo, boton de reset, boton de guardar, rele, display

typedef struct{
    unsigned int ciclos;
    int tempProm;
    bool isCorrupted;
}data_t;


class Logic{
public:
    void updateData(int temp, bool isTurnedOn);
    bool toWarm(bool isTurnedOn); //Devuelve true si el sistema tiene que calentar, y false si tiene que enfriar.
    int getTempAct();
    int getTempProm();
    void resetDangerFlag();
    void setDangerFlag();
    data_t getData2Save();
    void resetAllData();
    
private:
    vector <int> temperaturas;
    unsigned int ciclos;
    bool danger = false;
    bool waitUntilNextCicle = false;
};

#endif