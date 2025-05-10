#include <bits/stdc++.h>
using namespace std;

void intercambioInt(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

void ordenarVectores(vector<int> &ganancia, vector<int> &peso, int n){
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(ganancia[i]/peso[i] < ganancia[j]/peso[j]){
                intercambioInt(ganancia[i], ganancia[j]);
                intercambioInt(peso[i], peso[j]);
            }
        }
    }
}

void printVector(const vector<int> &v){
    for(auto num : v){
        cout<<num<<" ";
    }
    cout<<endl;
}

void mejorSolucion(vector<int> ganancia, vector<int> peso, int &minPeso, int &maxGanancia, int limite){
    
    int n = ganancia.size(), pesoTemp = 0, gananciaTemp = 0;

    // Primero se tiene que ordenar los arreglos en funcion del ratio de Ganancia / Peso
    ordenarVectores(ganancia, peso, n);
    // NOTA: Se ordena en funcion del ratio (double)

    for(int i = 0 ; i < n ; i++){
        if(peso[i] + pesoTemp <= limite){
            pesoTemp += peso[i];
            gananciaTemp += ganancia[i];
        }
    }

    minPeso = limite - pesoTemp;
    maxGanancia = gananciaTemp;
    // cout<<pesoTemp<<endl;
    // cout<<gananciaTemp<<endl;

}

int main(){

    // vector<int> ganancia = {10, 15, 10, 24, 8}, peso = {2, 3, 5, 12, 2};
    vector<int> ganancia = {10, 15, 10, 14, 8, 5}, peso = {2, 3, 5, 12, 2, 5};
    int limite = 20;

    int minPeso, maxGanancia;
    mejorSolucion(ganancia, peso, minPeso, maxGanancia, limite);

    cout<<"Solucion empleando un algoritmo heurisico voraz:"<<endl;
    cout<<"Peso sobrante en el contenedor: "<<minPeso<<" Tn"<<endl;
    cout<<"Ganancia de la exportacion: "<<maxGanancia<<" en miles de dolares"<<endl;

    return 0;
}