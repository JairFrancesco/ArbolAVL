#ifndef ARBOLAVL
#define ARBOLAVL
#include "Nodo.h"

class ArbolAVL{
public:
    Nodo* raiz = NULL;
    ArbolAVL(){
        raiz = NULL;\
    }

    void rotarLL(Nodo* &A){ //precond: el árbol necesita una rotacion LL
        Nodo* aux = A->izq->der;
        A->izq->der = A;
        A->izq->FB = 0;
        Nodo* aux2 = A->izq;
        A->izq = aux;
        A->FB = 0;
        A = aux2;
    }

    void rotarRR(Nodo* &A){ //precond: el árbol necesita una rotacion RR
        Nodo* aux = A->der->izq;
        A->der->izq = A;
        A->der->FB = 0;
        Nodo* aux2 = A->der;
        A->der = aux;
        A->FB = 0;
        A = aux2;
    }

    void rotarLRalter(Nodo* &A){ //precond: el árbol necesita una rotacion LR
        rotarRR(A->izq);
        rotarLL(A);
    }

    void rotarRLalter(Nodo* &A){ //precond: el árbol necesita una rotacion RL
        rotarLL(A->der);
        rotarRR(A);
    }

    void Insert(int n, bool aumento, Nodo* &A){
        if (A == NULL){//Si el nodo no existe
            A = new Nodo();
            A->dato = n;
            A->FB = 0;
            A->izq = NULL;
            A->der = NULL;
            aumento = true;
            A->borrado = false;
        }else{
            if (n < A->dato){
                cout<<"Try to insert in "<<A->dato<<" Izquierda"<<endl;
                Insert(n, aumento, A->izq);
                if (aumento){
                    switch (A->FB){
                        case -1:{
                            A->FB = 0;
                            aumento = false;
                            break;
                        }
                        case 0:{

                        }
                        case 1:{
                            if (A->izq->FB == 1){ // Si es 1 necesita una rotacion LL si es -1 necesita una rotacion LR
                                rotarLL(A);
                            }else{
                                rotarLRalter(A);
                            }
                            aumento = false;
                            break;
                        }
                    }
                }
            }else{
                cout<<"Try to insert in "<<A->dato<<" derecha"<<endl;
                Insert(n, aumento, A->der);
                if (aumento){
                    switch (A->FB){
                        case -1:{
                            if (A->der->FB == 1){ // Si es 1 necesita una rotacion RL si es -1 necesita una rotacion RR
                                rotarRLalter(A);
                            }else{
                                rotarRR(A);
                            }
                            aumento = false;
                            break;
                        }
                        case 0:{
                            A->FB = -1;
                            aumento = true;
                            break;
                        }
                        case 1:{
                            A->FB = 0;
                            aumento = false;
                            break;
                        }
                    }
                }
            }
        }
    }

    void Insertar(int n){
        bool aumento;
        cout<<"Try to insert in raiz"<<endl;
        Insert(n, aumento, raiz);
        cout<<"Insert finished"<<endl<<endl;
    }

    bool EsVacio(Nodo* A){
        return A == NULL;
    }

    bool Pertenece(Nodo* A, int n){
        if (A == NULL){
            return false;
        }else{
            if (A->dato == n){
                if (A->borrado){
                    return false;
                }else{
                    return true;
                }
            }else if (n < A->dato){
                return Pertenece(A->izq, n);
            }else{
                return Pertenece(A->der, n);
            }
        }
    }

    void Borrar(Nodo* A, int n){
        if (A->dato == n){
            A->borrado = true;
        }else if (n < A->dato){
            Borrar(A->izq, n);
        }else{
            Borrar(A->der, n);
        }
    }

    void printInOrden(Nodo* A){
        if(A->izq)
            printInOrden(A->izq);
        if(!A->borrado)
            cout<<A->dato<<endl;
        if(A->der)
            printInOrden(A->der);
    }
};

#endif // ARBOLAVL

