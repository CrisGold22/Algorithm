#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Nodo {
    int elemento; /*Dato que cambia por double, char, struct */
    struct Nodo * siguiente; /*puntero a una variable de tipo struct Nodo*/
};

struct Lista {
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    int longitud; /*guarda la longitud de la lista*/
};

void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista  & tad) {
    return tad.longitud;
}

struct Nodo * crearNodo(int elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

void insertarAlInicio(struct Lista & tad, int elemento) {

    /*Se va cambiar por la función crear nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = tad.cabeza;

    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

struct Nodo * obtenerUltimoNodo(const struct Lista & tad) {
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

/*inserta un nodo siempre al final de la lista*/
void insertarAlFinal(struct Lista & tad, int elemento) {

    struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr) /*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    tad.longitud++;
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
            cout << recorrido->elemento;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

void cambiar(Nodo *&recorrido1, Nodo *&recorrido2){
    int aux = recorrido1->elemento;
    recorrido1->elemento = recorrido2->elemento;
    recorrido2->elemento = aux;
}

//mediante bubble sort
void ordenarLista(Lista &lista){

    bool swapped = true;
    Nodo *recorrido, *anterior = nullptr;

    while(swapped){
        recorrido = lista.cabeza;
        swapped = false;
        while(recorrido->siguiente != anterior){
            if(recorrido->elemento > recorrido->siguiente->elemento){
                cambiar(recorrido, recorrido->siguiente);
                swapped = true;
            }
            recorrido = recorrido->siguiente;
        }
        anterior = recorrido;
    }
}

void invertir(Lista &lista){

    Nodo *anterior = nullptr, *siguiente = nullptr, *actual = lista.cabeza;

    while(actual != nullptr){
        siguiente = actual->siguiente;
        actual->siguiente = anterior;

        anterior = actual;
        actual = siguiente;
    }

    lista.cabeza = anterior;
}

void insertarOrdenado(Lista &lista, int elemento){

    Nodo *nodo = crearNodo(elemento, nullptr);

    if(esListaVacia(lista)){
        lista.cabeza = nodo;
        lista.longitud++;
    }
    else{
        Nodo *recorrido = lista.cabeza;
        Nodo *anterior = nullptr;

        while(true){
            if(recorrido == nullptr){
                anterior->siguiente = nodo;
                lista.longitud++;
                break;
            }
            else{
                if(recorrido->elemento < nodo->elemento){
                    anterior = recorrido;
                    recorrido = recorrido->siguiente;
                }
                else{
                    if(anterior == nullptr){
                        nodo->siguiente = recorrido;
                        lista.cabeza = nodo;
                        lista.longitud++;
                        break;
                    }
                    else{
                        anterior->siguiente = nodo;
                        nodo->siguiente = recorrido;
                        lista.longitud++;
                        break;
                    }
                }
            }
        }

    }

}

int main(){

    Lista lista;

    construir(lista);

    // insertarAlFinal(lista, 2);
    // insertarAlFinal(lista, 4);
    // insertarAlFinal(lista, 3);
    // insertarAlFinal(lista, 1);
    // insertarAlFinal(lista, 5);
    // insertarAlFinal(lista, 7);
    // insertarAlFinal(lista, 6);

    insertarOrdenado(lista, 2);
    insertarOrdenado(lista, 4);
    insertarOrdenado(lista, 3);
    insertarOrdenado(lista, 1);
    insertarOrdenado(lista, 5);
    insertarOrdenado(lista, 7);
    insertarOrdenado(lista, 6);

    // imprime(lista);
    // ordenarLista(lista);
    // imprime(lista);
    // invertir(lista);
    imprime(lista);

    return 0;
}