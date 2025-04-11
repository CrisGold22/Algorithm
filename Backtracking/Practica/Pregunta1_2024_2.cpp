#include <bits/stdc++.h>
using namespace std;

bool hayEspacio(vector<int> &resultado, int peso, int pesoMax){
    if(accumulate(resultado.begin(), resultado.end(), 0) + peso > pesoMax){
        return false;
    }
    return true;
}

void solve(const vector<int> &ropaSucia, int precio, vector<int> &resultado, int level, int pesoMax, int &minPrecio, int &pesoActual, vector<int> &best){
    int length = ropaSucia.size();
    if(level == length){
        return;
    }
    
    for(int i = level ; i < length ; i++){
        if(hayEspacio(resultado, ropaSucia[i], pesoMax)){
            resultado.push_back(ropaSucia[i]);
            if(accumulate(resultado.begin(), resultado.end(), 0) > pesoActual){
                pesoActual = accumulate(resultado.begin(), resultado.end(), 0);
                best = resultado;
            }
            solve(ropaSucia, precio, resultado, i + 1, pesoMax, minPrecio, pesoActual, best);
            resultado.pop_back();
        }
    }
}

void imprimirPacientesDenegados(const vector<int> &ropaSucia, const vector<int> &resultadoPorPiso, int num){
    int i = 0, j = 0;

    cout<<"Piso "<<num + 1<<": ";
    while(i < ropaSucia.size()){
        if(ropaSucia[i] == resultadoPorPiso[j]){
            i++;
            j++;
        }
        else{
            cout<<i + 1<<" ";
            i++;
        }
    }
    cout<<endl;
}

void imprimirPorcentaje(const vector<int> &ropaSucia, const vector<int> &resultadoPorPiso, int num){
    cout<<"Porcentaje piso "<<num + 1<<": ";
    double porcentaje = ((double)accumulate(resultadoPorPiso.begin(), resultadoPorPiso.end(), 0)/(double)accumulate(ropaSucia.begin(), ropaSucia.end(), 0))*100;
    cout<<porcentaje<<"%"<<endl; 
}

void imprimirMaxMinLavadora(const vector<vector<int>> resultado){
    int max = INT_MIN, min = INT_MAX;
    int indexMax = INT_MIN, indexMin = INT_MAX;
    int i = 0;

    for(auto v : resultado){
        if(max < accumulate(v.begin(), v.end(), 0)){
            max = accumulate(v.begin(), v.end(), 0); 
            indexMax = i;
        }
        if(min > accumulate(v.begin(), v.end(), 0)){
            min = accumulate(v.begin(), v.end(), 0);
            indexMin = i;
        }
        i++;
    }

    cout<<"Piso Max: "<<indexMax + 1<<" Peso: "<<max<<endl;
    cout<<"Piso Min: "<<indexMin + 1<<" Peso: "<<min<<endl;
}

int main(){

    vector<vector<int>> ropaSucia{{14, 11, 10, 19, 14, 11},
                                {20, 11, 11, 10, 15, 17, 9},
                                {15, 16, 15, 16},
                                {11, 4, 19, 12, 10},
                                {18, 12}};

    vector<int> precio = {5, 6, 8, 5, 9}, resultado;
    vector<vector<int>> resultadoPorPiso;


    int pesoMax; cout<<"Ingrese el peso maximo: "<<endl; cin>>pesoMax;
    int minPrecio = INT_MAX, pesoActual = 0;

    for(int i=0 ; i < ropaSucia.size() ; i++){
        vector<int> best;
        solve(ropaSucia[i], precio[i], resultado, 0, pesoMax, minPrecio, pesoActual, best);
        resultadoPorPiso.push_back(best);
        pesoActual = 0;
    }

    for(int i=0 ; i < ropaSucia.size() ; i++){
        imprimirPacientesDenegados(ropaSucia[i], resultadoPorPiso[i], i);
    }   
    cout<<endl;

    for(int i=0 ; i < ropaSucia.size() ; i++){
        imprimirPorcentaje(ropaSucia[i], resultadoPorPiso[i], i);
    }
    cout<<endl;

    imprimirMaxMinLavadora(resultadoPorPiso);
    cout<<endl;

    return 0;
}