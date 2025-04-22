#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int> &lista, vector<int> &solucion, vector<vector<int>> &soluciones, int level){
    if(level == lista.size()){
        return;
    }

    for(int i = level ; i < lista.size() ; i++){
        solucion.push_back(lista[i]);
    }

}

int main(){

    vector<int> lista = {4, 5, 9, 2}, solucion;
    vector<vector<int>> soluciones;

    solve(lista, solucion, soluciones, 0);


    return 0;
}