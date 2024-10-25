#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/*
    [][q][][]
    [q][][][]
    [][][q][]
    [][][][q]
*/

bool isSafe(vector<vector<int>> board, int i, int col){
    return true;
}

bool solution(vector<vector<int>> board, int col){
    int n = board.size();

    if(col >= n){
        return true;
    }

    for(int i=0 ; i < n ; i++){
        if(isSafe(board, i, col)){
            board[i][col] = 1;
            if(solution(board, col + 1)){
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

void solve_N_queens(int num){
    vector<vector<int>> board(num, vector<int>(num,0));

    if(solution(board, 0) == false){
        cout<<"Doesn't exist any solution"<<endl;
    }
    else{

    }
}

int main(){

    int num; cin>>num;

    solve_N_queens(num);

    return 0;
}