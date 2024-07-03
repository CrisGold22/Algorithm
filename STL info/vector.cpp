#include <iostream>
#include <vector>  // nombre de la libreria

using namespace std;

int main(){

    vector<int> pacheco = {1,2,3,4,5}; // declarar un vector

    //capacidad
    int longitud = pacheco.size(); //tamanho del vector
    int capacidad = pacheco.capacity(); // tamanho maximo del vector
    // pacheco.reverse(size_t n); // aumentar el tamanho del vector
    // pacheco.shrink_to_fit(size_t n); // reducir el tamanho del vector
    bool verificar = pacheco.empty(); // verifica si el vector esta vacio o no (devuelve un valor bool (true o false))
    //pacheco.resize(9); // cambia el tamanho del vector. Puede aumentar o disminuir


    //ACCESO A LA MEMORIA
    cout<<pacheco[3]<<endl; //accede a un elemento en la posicion indicada
    cout<<pacheco.at(3)<<endl; // lo mismo que lo anterior pero mas adecuado para los vectores
    cout<<pacheco.front()<<endl; // devuelve el primer elemento del vector
    cout<<pacheco.back()<<endl; // devuelve el ultimo elemento del vector
    cout<<pacheco.data()<<endl; // devuelve el puntero del primer elemento

    //MODIFICADORES
    pacheco.push_back(6); //agregar un elemento al final del vector
    pacheco.pop_back(); // eliminar el ultimo elemento del vector
    pacheco.insert(pacheco.begin()+2,3); //ingresar un elemento en la posicion indicada 
    //parametros: (iterador pos, elemento)
    pacheco.erase(pacheco.begin()); // elimina un elemento en la posicion indicada
    //parametros: (iterador pos)
    pacheco.clear(); // elimina todos los elementos de vector

    //ITERADORES
    pacheco.begin(); // devuelve el iterador del primer elemento
    pacheco.end(); // devuelve el iterador del ultimo elemento
    pacheco.rbegin(); // devuelve el iterador del ultimo elemento(en reversa)
    pacheco.rend(); // devuelve el iterador del primer elemento(en reversa)

    //EXTRAS
    vector<int> andrei = {2,3,6,8};
    pacheco.swap(andrei); // intercambia los contenidos de dos vectores

    return 0;
}