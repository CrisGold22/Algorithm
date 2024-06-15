#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

struct Nodo
{
    int elemento;
    char letra;
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

void encolar(Cola &cola, int elemento, char letra){

    if(esColaVacia(cola)){
        Nodo *nuevoNodo = new struct Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->letra = letra;
        nuevoNodo->siguiente = nullptr;

        cola.cabeza = nuevoNodo;
        cola.cola = nuevoNodo;
    }
    else{
        
        Nodo *nuevoNodo = new struct Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = nullptr;
        nuevoNodo->letra = letra;

        cola.cola->siguiente = nuevoNodo;
        cola.cola = nuevoNodo;
    }

}

void imprimir(Cola cola){
    Nodo *recorrido = cola.cabeza;
    Nodo *anterior = nullptr;

    while(recorrido != nullptr){
        cout<<recorrido->letra<<recorrido->elemento<<" ";
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    cout<<endl;
}

void cargarDatos(Cola &cola, const char *nombreFile){
    ifstream archivo(nombreFile, ios::in);
    if(not archivo.is_open()){
        cout<<"ERROR "<<nombreFile<<endl;
        exit(1);
    }

    char letra, car;
    int numero;

    while(true){
        archivo>>letra;
        if(archivo.eof()) break;
        archivo>>car>>numero;
        encolar(cola, numero, letra);
    }

}


int main(){

    Cola cola;
    construir(cola);

    cargarDatos(cola, "datos1.txt");
    imprimir(cola);
    //functionQueue(cola);

    return 0;
}