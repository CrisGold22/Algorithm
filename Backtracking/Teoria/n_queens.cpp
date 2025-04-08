#include <bits/stdc++.h>
using namespace std;

bool validMovement(vector<vector<int>> &table, int rows, int columns, int num){
    for(int i=0 ; i < num ; i++){
        if(table[i][columns] == 1){
            return false;
        }
    }    

    for(int i = rows - 1, j = columns - 1; i > -1 and j > -1 ; i--, j--){
        if(table[i][j] == 1){
            return false;
        }
    }

    for(int i = rows, j = columns - 1; i < num and j < - 1 ; i++, j--){
        if(table[i][j] == 1){
            return false;
        }
    }

    return true;
}

bool solve_N_queens(vector<vector<int>> &table, int rows, int num){
    if(rows == num){
        return true;
    }

    //recorre por las columnas
    for(int i = 0 ; i < num ; i++){
        if(validMovement(table, rows, i, num)){
            table[rows][i] = 1;
            if(solve_N_queens(table, rows + 1, num)){
                return true;
            }
            table[rows][i] = 0;
        }
    }

    return false;
}

void printSolution(const vector<vector<int>> &table, int num){
    for(int i=0 ; i < num ; i++){
        for(int j=0 ; j < num ; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    cout<<"Ingrese el numero de casilleros NxN: "<<endl;
    int num; cin>>num;
    vector<vector<int>> table(num, vector<int>(num, 0));


    if(solve_N_queens(table, 0, num)){
        printSolution(table, num);
    } 
    else{
        cout<<"Doesn't exist any solution"<<endl;
    }

    return 0;
}