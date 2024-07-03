#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack <int> pila;

    //INSERCION Y ELIMINACION
    pila.push(10); // inserta un elemento a la pila
    pila.push(20);
    pila.push(30);
    pila.push(40);
    pila.push(50);
    pila.pop(); // eliminar el elemento de la parte superior de la pila
    //pila.swap(cola2); ---->intercambia el contenido entre dos colas


    //ACCESO A LA MEMORIA Y CAPACIDAD
    cout<<pila.top()<<endl; // devuelve el elemento de la parte superior de la pila
    cout<<pila.size()<<endl; // devuelve el tamanho de la pila
    cout<<pila.empty()<<endl; // verifica si la pila esta vacia


    return 0;
}