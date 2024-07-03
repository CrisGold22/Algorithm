#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;

struct Nodo {
    int elemento; /*Dato que cambia por double, char, struct */
    char *codigo;
    struct Nodo * siguiente; /*puntero a una variable de tipo struct Nodo*/
};

struct Lista {
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    struct Nodo * prioridad1 = nullptr;
    struct Nodo * prioridad2 = nullptr;
    struct Nodo * prioridad3 = nullptr;
    
    struct Nodo * cola;
    int longitud; /*guarda la longitud de la lista*/
};

struct Cola{
    struct Lista lista;
};

void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
}

void construir(struct Cola & cola){
    construir(cola.lista);
}

const bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}

/*Verifica si la cola está vacía*/
bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */

struct Nodo * crearNodo(int elemento, struct Nodo * siguiente, char *codigo){
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    nuevoNodo->codigo = codigo;
    return nuevoNodo;
}

char *leerCadena(ifstream &archivo, char car){
    char *cadena, buffer[200];
    archivo.getline(buffer, 200, car);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento <<" " << recorrido->codigo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

void imprime(const struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede mostrar"<<endl;
    }
    else
        imprime(cola.lista);
}

void priorityInsert(Cola &cola, int date, char *letter){
    Nodo *newNodo = crearNodo(date, nullptr, letter);
    if(esColaVacia(cola)){
        
        if(date > 20140000){
            cola.lista.cabeza = newNodo;
            cola.lista.prioridad1 = newNodo;
            cola.lista.cola = newNodo;
        }
        else if(date >= 19440000 and date <= 20140000){
            cola.lista.cabeza = newNodo;
            cola.lista.prioridad3 = newNodo;
            cola.lista.cola = newNodo;
        }
        else{
            cola.lista.cabeza = newNodo;
            cola.lista.prioridad2 = newNodo;
            cola.lista.cola = newNodo;
        }
    }
    else{
        if(date < 19440000){
            if(cola.lista.prioridad1 == nullptr){
                newNodo->siguiente = cola.lista.cabeza;
                cola.lista.prioridad1 = newNodo;
                cola.lista.cabeza = newNodo;
            }
            else{
                newNodo->siguiente = cola.lista.prioridad1->siguiente;
                cola.lista.prioridad1->siguiente = newNodo;
                cola.lista.prioridad1 = newNodo;
                if(cola.lista.prioridad2 == nullptr and cola.lista.prioridad3 == nullptr) cola.lista.cola = newNodo;
            }
        }
        else if(date > 20140000){
            if(cola.lista.prioridad2 == nullptr){
                if(cola.lista.prioridad1 == nullptr){
                    newNodo->siguiente = cola.lista.cabeza;
                    cola.lista.cabeza = newNodo;
                    cola.lista.prioridad2 = newNodo;
                }
                else{
                    newNodo->siguiente = cola.lista.prioridad1->siguiente;
                    cola.lista.prioridad1->siguiente = newNodo;
                    cola.lista.prioridad2 = newNodo;
                    if(cola.lista.prioridad3 == nullptr) cola.lista.cola = newNodo;
                }
            }
            else{
                newNodo->siguiente = cola.lista.prioridad2->siguiente;
                cola.lista.prioridad2->siguiente = newNodo;
                cola.lista.prioridad2 = newNodo;
                if(cola.lista.prioridad3 == nullptr) cola.lista.cola = newNodo;
            }
        }
        else{
            cola.lista.cola->siguiente = newNodo;
            cola.lista.prioridad3 = newNodo;
            cola.lista.cola = newNodo;
        }
    }
    
}

int main(){

    Cola cola;
    construir(cola);

    ifstream datos("pc2_2024_1_datos.txt", ios::in);
    if(not datos.is_open()){
        cout<<"ERROR datos.txt"<<endl;
        exit(1);
    }

    int dd, mm, aa;
    char letter[7];

    while(true){
        datos>>dd;
        if(datos.eof()) break;
        datos>>mm>>aa>>letter;
        int date = aa*10000 + mm*100 + dd;
        priorityInsert(cola, date, letter);
    }

    imprime(cola);

    return 0;
}