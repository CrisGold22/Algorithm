#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>

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


void insertarPorPrioridad(Cola &cola, const char *nombreFile){
    
    ifstream archivo(nombreFile, ios::in);
    if(not archivo.is_open()){
        cout<<"ERROR "<<nombreFile<<endl;
        exit(1);
    }
    
    int dd, mm, aa, fecha;
    char *codigo;
    
    while(true){
        archivo>>dd;
        if(archivo.eof()) break;
        archivo>>mm>>aa>>ws;
        
        fecha = aa*10000 + mm*100 + dd;
        codigo = leerCadena(archivo, '\n');
           
        Nodo *nuevoNodo = crearNodo(fecha, nullptr, codigo);

        if(esColaVacia(cola)){
            if(fecha < 19440000){
                cola.lista.prioridad1 = nuevoNodo;
                cola.lista.cabeza = nuevoNodo;
                cola.lista.cola = nuevoNodo;
            }
            else if(fecha>= 19440000 and fecha <=20140000){
                cola.lista.prioridad3 = nuevoNodo;
                cola.lista.cabeza = nuevoNodo;
                cola.lista.cola = nuevoNodo;
            }
            else{
                cola.lista.prioridad2 = nuevoNodo;
                cola.lista.cabeza = nuevoNodo;
                cola.lista.cola = nuevoNodo;
            }
        }
        else{
            if(fecha < 19440000){ 
                if(cola.lista.prioridad1 == nullptr){
                    nuevoNodo->siguiente = cola.lista.cabeza;
                    cola.lista.prioridad1 = nuevoNodo;
                    cola.lista.cabeza = nuevoNodo;
                }
                else{
                    nuevoNodo->siguiente = cola.lista.prioridad1->siguiente;
                    cola.lista.prioridad1->siguiente = nuevoNodo;
                    cola.lista.prioridad1 = nuevoNodo;
                    if(cola.lista.prioridad2 == nullptr and cola.lista.prioridad3 == nullptr) cola.lista.cola = nuevoNodo;
                }
            }
            else if(fecha > 20140000){
                if(cola.lista.prioridad2 == nullptr){
                    
                    if(cola.lista.prioridad1 == nullptr){
                        nuevoNodo->siguiente = cola.lista.cabeza;
                        cola.lista.cabeza = nuevoNodo;
                        cola.lista.prioridad2 = nuevoNodo;
                    }
                    else{
                        nuevoNodo->siguiente = cola.lista.prioridad1->siguiente;
                        cola.lista.prioridad1->siguiente = nuevoNodo;
                        cola.lista.prioridad2 = nuevoNodo;
                        if(cola.lista.prioridad3 == nullptr) cola.lista.cola = nuevoNodo;
                    }
                    
                }
                else{
                    nuevoNodo->siguiente = cola.lista.prioridad2->siguiente;
                    cola.lista.prioridad2->siguiente = nuevoNodo;
                    cola.lista.prioridad2 = nuevoNodo;
                    if(cola.lista.prioridad3 == nullptr) cola.lista.cola = nuevoNodo;
                }
            }
            else{
                cola.lista.cola->siguiente = nuevoNodo;
                cola.lista.prioridad3 = nuevoNodo;
                cola.lista.cola = nuevoNodo;
            }
        }
        
    }
    
    
}

int main(int argc, char** argv) {

    Cola colaPrioridad;
    construir(colaPrioridad);
    
    insertarPorPrioridad(colaPrioridad, "datos.txt");
    
    imprime(colaPrioridad);
    
    
    return 0;
}