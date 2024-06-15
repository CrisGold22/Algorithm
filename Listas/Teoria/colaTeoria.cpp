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
    Nodo *nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = 0;
    cola.cabeza = nuevoNodo;
    cola.cola = nuevoNodo;
}

bool esNodoVacio(Nodo *nodo){
    return nodo->elemento == 0;
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

int main(){
    
    Cola cola;
    construir(cola);

    encolar(cola, 2);           
    encolar(cola, 2);           
    encolar(cola, 2);           
    encolar(cola, 2);           

    imprimir(cola);

    return 0;
}
