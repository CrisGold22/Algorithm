#include <iostream>
#include <map>  //nombre de la libreria
#include <string> //libreria para el ejemplo

using namespace std;

int main(){
    //declaracion de un mapa: map<{tipo clave} , {tipo valor}>
    map <string,int> mapa;
    //ejemplo con cant de orejonas por equipo

    //INSERCION Y ELIMINACION
    mapa.insert(make_pair("Real Madrid",14)); //POS: make_pair() es para facilitar la entrada de datos. 
    //De caso contrario se tendria que ingresar de la siguiente manera:
    //mapa.insert(pair<string, int>("Real Madrid", 14))
    mapa.insert(make_pair("Barcelona",5));
    mapa.insert(make_pair("Inter de Milan",7));
    mapa.insert(make_pair("Bayern Munich",6));
    //mapa.clear();   ---> elimina todos los elementos del mapa
    mapa.empty(); // verifica si el mapa esta vacio
    mapa.size(); // devuelve el numero de elementos en el mapa

    int champions = mapa["Real Madrid"]; // accede al valor asociado a la clave indicada
    cout<<champions<<endl; 

    // EXTRA
    auto it = mapa.find("Barcelona"); // busca elementos en funcion de su clave
    if(it != mapa.end()){
        cout<<"A ganado "<< it->second <<endl;
    }
    else{
        cout<<"No encontrado"<<endl;
    }
    cout<<mapa.count("Manchester City"); // devuelve true or false(1 o 0) si existe la clave indicada en el mapa
    

    return 0;
}