#include <bits/stdc++.h>
using namespace std;

bool flag = false;

bool cumpleCondicion(int producto, int rack, int resultado){
    if(producto + resultado > rack){
        return false;
    }
    return true;
}

bool isAllItemUsed(const vector<int> &usado){
    int count = 0;
    for(auto v : usado){
        count += v;
    }

    return count == 10;
}

void printSolution(const vector<int> &resultado){
    for(auto num : resultado){
        cout<<num<<" ";
    }
    cout<<endl;
}

void solve1(const vector<int> &cantProductos, const vector<int> &rack, vector<int> &resultado, vector<bool> &usado, int indexProductos){
    
    if(isAllItemUsed(resultado)){
        printSolution(resultado);
        flag = true;
        return;
    }
    
    if(indexProductos == rack.size()){
        return;
    }

    int producto = cantProductos[indexProductos];

    for(int i = 0; i < rack.size() ; i++){
        if(flag){
            return;
        }
        if(cumpleCondicion(producto, rack[i], resultado[i])){
            resultado[i] += producto;
            usado[indexProductos] = true;
            solve1(cantProductos, rack, resultado, usado, indexProductos + 1);
            resultado[i] -= producto;
            usado[indexProductos] = false;
        }
    }

}

void solve2(const vector<int> &cantProductos, const vector<int> &rack, vector<int> &resultado, vector<bool> &usado, int indexProductos){
    
    if(isAllItemUsed(resultado)){
        printSolution(resultado);
        return;
    }

    if(indexProductos == rack.size()){
        return ;
    }

    int producto = cantProductos[indexProductos];

    for(int i = 0; i < rack.size() ; i++){
        if(cumpleCondicion(producto, rack[i], resultado[i])){
            resultado[i] += producto;
            usado[indexProductos] = true;
            solve2(cantProductos, rack, resultado, usado, indexProductos + 1);
            resultado[i] -= producto;
            usado[indexProductos] = false;
        }
    }
}

void limpiarResultado(vector<int> &resultado){
    for(auto v : resultado){
        v = 0;
    }
}

int main(){
    
    vector<int> cantProductos = {2, 3, 1, 4};
    vector<int> rack = {3, 2, 5, 1, 3}, resultado(5, 0);
    vector<bool> usado(4, false);

    solve1(cantProductos, rack, resultado, usado, 0);
    if(!flag){
        cout<<"There's not exist any solution"<<endl;
    }
    flag = false;
    limpiarResultado(resultado);

    solve2(cantProductos, rack, resultado, usado, 0);

    return 0;
}