#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
/*
[ ][ ][x][ ]
[x][ ][ ][ ]
[ ][ ][ ][x]
[ ][x][ ][ ]
*/

<<<<<<< HEAD
bool validSolution(vector<vector<int>> &table, int rows, int columns, int num){
    for(int i=0 ; i < num ; i++){
        if(table[i][columns] == table[rows][columns]) continue;

        if(table[i][columns] == 1){
            return false;
        }
    }

    for(int i=0 ; i < num ; i++){
        if(table[rows][i] == table[rows][columns]) continue;

        if(table[rows][i] == 1){
            return false;
        }
    }

    for(int i = rows - 1, j = columns - 1 ; i > - 1 and j > -1 ; i--, j--){
        if(table[i][j] == 1){
            return false;
        }
    }

    for(int i = rows - 1, j = 0 ; i > -1 and j < num ; i++){
        if(table[i][j] == 1){
            return false;
        }
    }

=======
//cambio que se hizo al archivo

bool isSafe(vector<vector<int>> board, int i, int col){
>>>>>>> 812e6e4f4401e460398f9ec71c02f70f453dcd68
    return true;
}

void solve_N_queens(vector<vector<int>> &table, int rows, int num){

    if(rows == num){
        return;
    }

    for(int i=0 ; i < num ; i++){
        if(validSolution(table, rows, i, num)){
            table[rows][i] = 1;
            solve_N_queens(table, rows + 1, num);
            table[rows][i] = 0;
        }
    }
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

    int num; cin>>num;
    vector<vector<int>> table(num, vector<int>(num, 0));

    solve_N_queens(table, 0, num);
    
    printSolution(table, num);

    return 0;
}