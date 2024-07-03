#include <iostream>
#include <list>  //nombre de la libreria

using namespace std;

int main(){

    list <int> lista;  //declaracion de la lista

    //CAPACIDAD
    cout<<lista.size()<<endl; // tamanho de la lista
    lista.resize(8); // se cambia el tamanho de la lista
    
    //INSERCION Y ELIMINACION
    //NOTA: no se puede acceder a un ubicacion en especifico con el operador [] (como se usa en los arreglos)
    lista.push_front(1); // insertar un elemento al inicio de la lista
    lista.push_back(2); //insertar un elemento al final de la lista 
    lista.insert(++lista.begin(),5); // insertar un elemento en la posicion indicada
    //parametros(iterador pos, elemento)
    lista.pop_back(); // elimina el ultimo elemento
    lista.pop_front(); // elimina el primer elemento
    lista.erase(lista.begin()); // eliminar un elemento de la posicion indicada
    lista.clear(); // elimina todos los elementos de la lista

    //EXTRA
    cout<<lista.empty()<<endl; // verifica si la lista esta vacia
    lista.remove(2); // elimina todos los elementos de la lista que hemos definido
    lista.reverse(); // invierte el orden de la lista (no quiere decir que lo ordena de forma descendente)
    lista.sort(); // ordena la lista de forma ascendente
    lista.unique(); // elimina todos los elementos repetidos
    
    list <int> lista2 = {1,2,3,4};

    lista2.swap(lista); // intercambia el contenido de las dos listas


    return 0;
}