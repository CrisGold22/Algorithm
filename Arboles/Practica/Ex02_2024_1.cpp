#include <iostream>
#include <stack>
using namespace std;

void contagios(int dias, int *cifras, int *intervalos){

    stack<int> pilaDias;
    stack<int> pilaIntervalo;
    int i=0;
    int n=1;

    while(i < dias){
        if(pilaDias.empty()){
            pilaDias.push(cifras[i]);
            pilaIntervalo.push(n);

            int intervalo = pilaIntervalo.top();
            intervalos[i] = intervalo;
            i++;
            n=1;
        }
        else{
            if(cifras[i] > pilaDias.top() ){
                int intervalo = pilaIntervalo.top();
                pilaDias.pop();
                pilaIntervalo.pop();
                n+=intervalo;
            }
            else{
                if(cifras[i] < pilaDias.top()){
                    pilaDias.push(cifras[i]);
                    pilaIntervalo.push(n);
                    int intervalo = pilaIntervalo.top();
                    intervalos[i] = intervalo;
                    n=1;
                }
                i++;
            }
        }
    }
    cout<<"Los incrementos son: {";
    for(int j=0;j<dias;j++){
        cout<<intervalos[j]-1;
        if(j<7)cout<<",";
    }
    cout<<"}";
}

int main(){

    int dias = 8;
    int cifras[dias] = {10, 20, 15, 10, 12, 10, 13, 18};
    int intervalos[8];

    contagios(dias, cifras, intervalos);

    return 0;
}