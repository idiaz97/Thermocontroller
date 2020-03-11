#include "./Display.h"
#include <string.h>


 Display::Display(int rs, int enable, int d4, int d5, int d6, int d7){
    static LiquidCrystal LCD(rs, enable, d4, d5, d6, d7); //La mantengo static porque en la clase se guarda el puntero, y si se llama al
                                                        //destructor de LCD, el puntero queda apuntando a NULL.
    LCD.begin(16,2);
    LCD.print("Inicializando");
    displayMode = ACTUAL;
    lcd = &LCD;
    return;
}

void Display::updateData(unsigned int cicl, char tempAct,char tempProm){
    ciclos = cicl;
    if (tempAct != 0)
        temperaturaActual = tempAct;
    if (tempProm != 0)
        temperaturaProm = tempProm;
    return;
}

bool Display::changeDisplayMode(){
    bool isOk;
    lcd->clear();
    lcd->print("Cambiando Modo...");
    if(displayMode == ACTUAL){
        displayMode = PROMEDIO;
        isOk = true;
    }
    else if (displayMode == PROMEDIO){
        displayMode = ACTUAL;
        isOk = true;
    }
    else
        isOk = false;
    return isOk;
}

bool Display::printData(){
    bool isOk = true;
    lcd->clear();
    String line1;
    if(displayMode == ACTUAL)
        line1 = "TempAct: " + String((int)temperaturaActual) + String(" C");
    else if (displayMode = PROMEDIO)
        line1 = "TempProm: " + String((int)temperaturaProm)+ String(" C");
    else
        isOk = false;

    String line2 = "Ciclos: ";
    line2 = line2 + String(ciclos);
    if(isOk == true){
        lcd->setCursor(0, 0);
        lcd->print(line1);
        lcd->setCursor(0, 1);
        lcd->print(line2);
    }
    return isOk;
}
