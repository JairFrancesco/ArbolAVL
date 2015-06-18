#ifndef ARBOLAVL
#define ARBOLAVL
#include "Nodo.h"

class ArbolAVL{
public:
    Nodo* raiz = NULL;
    ArbolAVL(){
        raiz = NULL;\
    }

    void rotarDerecha(Nodo* &raiz){
        Nodo * temp = raiz;
        raiz = raiz->izq;
        raiz->izq = temp->izq->izq;
        temp->izq = raiz->der;
        raiz->der = temp;
    }

    void rotarIzquierda(Nodo* &raiz){
        Nodo * temp = raiz;
        raiz = raiz->der;
        raiz->der = temp->der->der;
        temp->der = raiz->izq;
        raiz->izq = temp;
    }

    void rotarDobleDerecha(Nodo* &raiz){
        rotarIzquierda(raiz->der);
        rotarDerecha(raiz);
    }

    void rotarDobleIzquierda(Nodo* &raiz){
        rotarDerecha(raiz->izq);
        rotarDerecha(raiz);
    }

    void Insert(Nodo* &raiz, int num){
        if(!raiz){
            raiz = new Nodo(num);
            raiz->altura = 0;
        }else{
            if(num < raiz->dato)
                Insert(raiz->izq, num);
            else
                Insert(raiz->der, num);
        }
    }

    void Insertar(int num){
        Insert(raiz, num);
    }

    void Eliminar(Nodo* &raiz, int num){

    }

    bool Pertenece(Nodo* raiz, int num){
        if(!raiz)
            return false;
        if(raiz->dato == num)
            return true;
        if(num < raiz->dato)
            return Pertenece(raiz->izq, num);
        return Pertenece(raiz->der,num);
    }

    void printInOrden(Nodo* A){
        if(A->izq)
            printInOrden(A->izq);
        cout<<A->dato<<endl;
        if(A->der)
            printInOrden(A->der);
    }
};

#endif // ARBOLAVL

