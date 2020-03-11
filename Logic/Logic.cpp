#include "./Logic.h"

void Logic::updateData(int temp, bool isTurnedOn){
    if(isTurnedOn == true && waitUntilIsColdAgain == false){
        if(danger != true)
            ciclos++;
        waitUntilIsColdAgain = true;
        temperaturas.push_back(temp);
        /*if (temp >= TEMPERATURA_MIN)
            danger = true;*/
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

int Logic::getTempAct(){
    return temperaturas.getElement(temperaturas.size()-1);
}

int Logic::getTempProm(){
    int answer = 0;
    for(int i = 0; i < temperaturas.size(); i++){
        answer += temperaturas.getElement(i);
    }
    answer = answer/temperaturas.size();
    return answer;
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
    answer.tempProm = num;
    return answer;
}

void Logic::resetAllData(){
    temperaturas.clear();
    ciclos = 0;
    danger = false;
    waitUntilIsColdAgain = false;
    return;
}
