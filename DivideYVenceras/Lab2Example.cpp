#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int matriz[1000][10]{};

void funcion(int left, int right, int &minNum, int &maxNum, int nivel, int &contador){
    if(left >= right){
        return;
    }
    int mid = (left + right)/2;
    if(matriz[nivel][mid] > maxNum){
        maxNum = matriz[nivel][mid];
        contador=0;
    }
    if(matriz[nivel][mid] == maxNum){
        contador++;
    }

    funcion(left, mid, minNum, maxNum, nivel, contador);
    funcion(mid + 1, right, minNum, maxNum, nivel, contador);
}

void recursionFunction(int cantidad, int nivel, int &minNum, int &registro){
    if(cantidad == nivel){
        return;
    }
    int maxNum=0, contador=0;
    funcion(0, 9, minNum, maxNum, nivel, contador);
    cout<<maxNum<<" "<<contador<<endl;
    if(contador < minNum){
        minNum = contador;
        registro = nivel+1;
    }
    recursionFunction(cantidad, nivel +1, minNum, registro);
}

int main(){

    ifstream archivo("datos.txt", ios::in);

    int cantidad; archivo>>cantidad;
    int pacheco=0;

    for(int i=0;i<cantidad;i++){
        for(int j=0;j<10;j++){
            archivo>>matriz[i][j];
        } 
    }
    
    int minNum = 999999;
    int registro;

    recursionFunction(cantidad, 0, minNum, registro);

    cout<<"La respuesta es el registro "<<registro<<endl;
    /*
    for(int i=0 ; i<cantidad ; i++){
        for(int j=0; j<10 ; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return 0;
}