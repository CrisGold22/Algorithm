#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue <int> cola; //PS: No se puede inicializar una cola con los valores previos

    //INSERCION Y ELIMINACION
    cola.push(1); //inserta un elemento al final de la cola
    cola.push(2);
    cola.push(3);
    cola.push(4);
    cola.push(5);
    cola.pop(); //elimina el primer elemento de la cola
    
    //ACCESO A LA MEMORIA
    cout<<cola.front()<<endl; // devuelve el primer elemento de la cola
    cout<<cola.back()<<endl; // devuelve el ultimo elemento de la cola
    //PS: no se puede acceder a un elemento de un posicion arbitraria

    queue <int> cola2; // de elementos {4,5,6}
    cola.swap(cola2); // intercambia el contenido entre las dos colas

    return 0;
}