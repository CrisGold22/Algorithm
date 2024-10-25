#include <bits/stdc++.h>
using namespace std;

//Viene a ser la estructura general sobre el algoritmo de backtracking

void findSolution(/*parameters*/){
    if(true /*valid solution*/){
        //store the solution
        //return;
    }

    for(/*all choice*/int i=0 ;i < 9; i++){
        if(true /*valid choice*/){
            //apply(choice);
            findSolution(/*parameters*/);
            //backtrack(remove choice);
        }
    }
    return;
}

int main(){

    findSolution();

    return 0;
}