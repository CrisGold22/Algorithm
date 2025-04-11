#include <bits/stdc++.h>
using namespace std;
bool flag = false;

bool isSafe(vector<vector<int>> &table, int row, int column, int num){
    for(int i = 0; i < table.size() ; i++){
        if(table[row][i] == num){
            return false;
        }
    }

    for(int i = 0; i < table.size() ; i++){
        if(table[i][column] == num){
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &table, int row, int column){
    int length = table.size();

    if(row == length -1 and column == length){
        return true;
    }

    if(length == column){
        row++;
        column = 0;
    }   

    if(table[row][column] != 0){
        return solve(table, row, column + 1);
    }

    for(int i = 1 ; i <= length ; i++){
        if(isSafe(table, row, column, i)){
            table[row][column] = i;
            if(solve(table, row, column +1)){
                return true;
            }
            table[row][column] = 0;
        }
    }
    return false;
}

void printTable(const vector<vector<int>> &table){
    for(auto it:table){
        for(auto num:it){
            cout<<"["<<num<<"]";
        }
        cout<<endl;
    }
}

int main(){

    // vector<vector<int>> table = {{0, 0, 3, 0, 0},
    //                              {0, 5, 0, 0, 3},
    //                              {3, 0, 0, 1, 0},
    //                              {0, 3, 0, 0, 0},
    //                              {0, 0, 2, 3, 0}};

    vector<vector<int>> table = {{0, 0, 3},
                                 {3, 0, 0},
                                 {0, 3, 0}};

    if(solve(table, 0, 0)){
        printTable(table);
    }
    else{
        cout<<"There is not solution"<<endl;
    }

    return 0;
}