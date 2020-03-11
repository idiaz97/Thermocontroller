#include "./Logic.h"

/*void Logic::updateData(int temp, bool isTurnedOn){
    if(isTurnedOn == true && waitUntilIsColdAgain == false){
        if(danger != true)
            ciclos++;
        waitUntilIsColdAgain = true;
        temperaturas.push_back(temp);
        //if (temp >= TEMPERATURA_MIN)
        //    danger = true;
    }
    else if (isTurnedOn == false && waitUntilIsColdAgain == true){
        waitUntilIsColdAgain = false;
        if (temp >= TEMPERATURA_MAX)
            danger = true;
    }
    return;
}

bool Logic::toWarm(bool isTurnedOn){
    bool warm = false;
    if(!isTurnedOn && danger == false)
        warm=true;
    return warm;
}

char Logic::getTempAct(){
    return temperaturas.getElement(temperaturas.size()-1);
}

char Logic::getTempProm(){
    int answer = 0;
    for(int i = 0; i < temperaturas.size(); i++){
        answer += temperaturas.getElement(i);
    }
    answer = (answer/temperaturas.size());
    return ((char)answer);
}

void Logic::resetDangerFlag(){
    danger = false;
    return;
}

void Logic::setDangerFlag(){
    danger = true;
    return;
}

data_t Logic::getData2Save(){
    data_t answer;
    answer.ciclos = ciclos;
    answer.isCorrupted = danger;
    int num = 0;
    for(int i = 0; i < temperaturas.size(); i++){
        num += temperaturas.getElement(i);
    }
    num = num/temperaturas.size();
    answer.tempProm = (char)num;
    return answer;
}
*/
void Logic::resetAllData(){
    temperaturas.clear();
    ciclos = 0;
    currentState = START;
    return;
}


Logic::Logic(IO * temp, Dsiplay * disp){
    ciclos = 0;
    currentState = START;
    io = temp;
    display = disp;
}

void Logic::updateSystem(){
    event_t ev = getNextEvent();
    switch(ev){
        case C_OPENS:
            if(currentState == COOLING || currentState == START){
                currentState = WARMING;
                io->toWarm(true);
            }
            break;
        case C_CLOSES:
            if(currentState == WARMING){
                currentState = COOLING;
                io->toWarm(false);
                ciclos++;
                temperaturas.push_back(io->getTemperature());
            }
            break;
        case TEMP_MAX:
            currentState = DANGER;
            io->toWarm(false);
            //AVISAR EN EL DISPLAY
            break;
        case TEMP_MIN:
            if(currentState != START)
                currentState = DANGER;
            else
                currentState = WARMING;
            break;
        case RESET:
            currentState = START;
            resetAllData();
            break;
        case SAVE:
            saveData();
        default:
            break;
    }
    display->updateData(ciclos,io->getTemperature(),temperaturas.getMean());
}

event_t Logic::getNextEvent(){
    event_t ev;
    temp = io->getTemperature()
    if(temp >= TEMPERATURA_MAX)
        ev = TEMP_MAX;
    else if (temp <= TEMPERATURA_MIN)
        ev = TEMP_MIN;
    else{
        if(io->isCircuitClosed())
            ev = C_CLOSES;
        else    
            ev = C_OPENS;
        
        if(io->resetButtonPressed())
            ev = RESET;
        if(io->saveButtonPressed())
            ev = SAVE;
    }
    return ev;
}