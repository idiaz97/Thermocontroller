#ifndef VECTOR_H
#define VECTOR_H
#define ARRAY_SIZE  50
#define EMPTY -1

class Vector{
public:
    Vector(); 
    void push_back(int temp);
    void clear();
    int size();
    char getElement(int i);
    char getMean();

protected:
    char array[ARRAY_SIZE];
    int iterator;
    void moveOnePlaceLeft();
};

#endif
