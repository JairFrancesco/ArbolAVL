#ifndef NODO
#define NODO

#include <iostream>
using namespace std;

class Nodo{
public:
    int dato, FB; // FB es la altura del subarbol izquierdo menos la altura del subarbol derecho
    Nodo* izq, *der;
    bool borrado;
    Nodo(){
        izq = NULL;
        der = NULL;
    }
};

#endif // NODO

