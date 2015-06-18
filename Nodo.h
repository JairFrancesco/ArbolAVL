#ifndef NODO
#define NODO

#include <iostream>
using namespace std;

class Nodo{
public:
    int dato, altura;
    Nodo* izq, *der;
    Nodo(int dato){
        this->dato = dato;
        izq = NULL;
        der = NULL;
    }
};

#endif // NODO

