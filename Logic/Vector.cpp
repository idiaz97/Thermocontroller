#include "./Vector.h"

Vector::Vector(){
    for(int i = 0; i<ARRAY_SIZE;i++){
        array[i] = EMPTY;
    }
    iterator = 0;
    return;
}

void Vector::push_back(int temp){
    if (iterator < ARRAY_SIZE -1){
        array[iterator]=temp;
        iterator++;
    }
    else{
        array[iterator]=temp;  //iterator en 49
        iterator++;             //iterator en 50
        moveOnePlaceLeft();     //iterator en 49
    }
    return;
}

void Vector::moveOnePlaceLeft(void){
    for(int i = ARRAY_SIZE-1; i > 0;i--){
        array[i-1] = array[i];
    }
    iterator--;
    return;
}

void Vector::clear(void){
    for(int i = 0;i < ARRAY_SIZE;i++){
        array[i]=EMPTY;
    }
    return;
}

int Vector::size(){
    return iterator;
}

int Vector::getElement(int i){
    int answer = 0
    if(i<iterator)
        answer = array[i];
    return answer;
}


char Vector::getMean(){
    int temporary = 0;
    for (int i = 0 ; i < iterator; i++){
        temporary += array[i];
    }
    if(iteraror != 0)
        temporary = temporary/iterator;
    else
        temporary = 0;
    return (char) temporary;
}