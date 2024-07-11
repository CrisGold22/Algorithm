#include <iostream>
#include <cmath>
using namespace std;

struct Nodo
{
    int elemento;
    Nodo *siguiente;
};

struct Cola
{
    Nodo *cabeza;
    Nodo *cola;
};

void construir(Cola &cola){
    cola.cabeza = nullptr;
    cola.cola = nullptr;
}

bool esNodoVacio(Nodo *nodo){
    return nodo == nullptr;
}

bool esColaVacia(Cola &cola){
    return esNodoVacio(cola.cabeza);
}

void encolar(Cola &cola, int elemento){

    if(esColaVacia(cola)){
        Nodo *nuevoNodo = new struct Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = nullptr;

        cola.cabeza = nuevoNodo;
        cola.cola = nuevoNodo;
    }
    else{
        
        Nodo *nuevoNodo = new struct Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = nullptr;

        cola.cola->siguiente = nuevoNodo;
        cola.cola = nuevoNodo;
    }

}

int retornaCabeza(Cola &cola){
    return cola.cabeza->elemento;
}

void eliminaCabeza(Cola &cola){
    Nodo *nodo = cola.cabeza;

    if(nodo != nullptr){
        cola.cabeza = cola.cabeza->siguiente;
        delete nodo;
    }
}

int desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        return -10;
    }
    int elemento = retornaCabeza(cola);
    eliminaCabeza(cola);
    return elemento;
}


void imprimir(Cola cola){
    Nodo *recorrido = cola.cabeza;
    Nodo *anterior = nullptr;

    while(recorrido != nullptr){
        cout<<recorrido->elemento<<" ";
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    cout<<endl;
}

void ordenar(Cola &cola, int cantidad){
    if(esColaVacia(cola)){
        return;
    }
    else{
        int mayor = desencolar(cola);
        int m = cantidad;
        while(m > 0 and not(esColaVacia(cola))){
            int aux = desencolar(cola);
            if(mayor > aux){
                encolar(cola, aux);
            }
            else{
                encolar(cola, mayor);
                mayor = aux;
            }
            m--;
        }
        ordenar(cola, cantidad - 1);
        encolar(cola, mayor);
    }
}

int main(){
    
    Cola cola;
    construir(cola);

    encolar(cola, 2);           
    encolar(cola, 4);           
    encolar(cola, 6);           
    encolar(cola, 5);           
    encolar(cola, 3);           
    encolar(cola, 1);           
    ordenar(cola, 6);

    imprimir(cola);

    return 0;
}
