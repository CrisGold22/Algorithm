#include <bits/stdc++.h>
using namespace std;

int ToNumber(char car){
    switch(car){
        case 'A': return 0;
        case 'B': return 1; 
        case 'C': return 2; 
        case 'D': return 3; 
        case 'E': return 4; 
        case 'F': return 5; 
        case 'G': return 6; 
        case 'H': return 7; 
    }
    return -1;
}

bool verificarCamino(const vector<int> vector){
    for(auto num : vector){
        if(num != 0){
            return true;
        }
    }
    return false;
}

int solve(const vector<vector<int>> &grafo, char inicio, char final){

    int numInicio = ToNumber(inicio), numFinal = ToNumber(final);
    if(numInicio == numFinal) return 0;

    int resultado = 0, minimo = INT_MAX, current = numInicio, newCurrent = numInicio;

    while(true){
        if(verificarCamino(grafo[current])){
            for(int i = 0 ; i < grafo.size() ; i++){
                if(grafo[current][i] != 0 and grafo[current][i] < minimo){
                    newCurrent = i;
                    minimo = grafo[current][i];
                }
            }
            current = newCurrent;
            resultado += minimo;

            if(current == numFinal){
                break;
            }
            else{
                minimo = INT_MAX;
            }
        }
        else{
            resultado = -1;
            break;
        }
    }

    return resultado;
}

int main(){
    
    vector<vector<int>> grafo = {{0, 4, 5, 6, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 2, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 3},
                                 {0, 0, 0, 0, 0, 3, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 10, 0},
                                 {0, 0, 0, 0, 0, 0, 2, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0}};

    int resultado = solve(grafo, 'A', 'G');

    if(resultado != -1){
        cout<<resultado<<endl;
    }
    else{
        cout<<"No hay solucion"<<endl;
    }

    return 0;
}