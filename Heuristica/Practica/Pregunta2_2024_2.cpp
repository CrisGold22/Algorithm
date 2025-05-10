#include <bits/stdc++.h>
using namespace std;

struct Producto{
    string nombre;
    int cantLatas;
    int longitud;
    int altura;

    Producto(string n, int c, int l, int a){
        nombre = n;
        cantLatas = c;
        longitud = l;
        altura = a;
    }

};

bool compara(Producto a, Producto b){
    return a.altura * a.longitud > b.altura * b.longitud;
}



int main(){

    vector<Producto> productos = {Producto("Latas de mentolato", 5, 2, 3),
                                  Producto("Latas de crema Nivea", 10, 9, 3),
                                  Producto("Latas de Atun", 15, 14, 7),
                                  Producto("Latas de conserva", 20, 15, 20),
                                  Producto("Latas de aceite industrial", 20, 22, 18)};

    
    //Primero se tiene que ordenar de mayor area a menor
    sort(productos.begin(), productos.end(), compara);
    
    int L = 50, H = 50, LRestante, HRestante, cantLaminas = 1;
    LRestante = L;
    HRestante = H;


    return 0;
}