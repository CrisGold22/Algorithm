#include <bits/stdc++.h>
using namespace std;

int fibRec(int num, vector<int> &memo){
    // Caso Base
    if(num <= 1){
        return num;
    }

    //verifica si el output existe
    if(memo[num] != -1){
        return memo[num];
    }

    //calcula y guarda el output para un futuro uso
    memo[num] = fibRec(num - 1, memo) + fibRec(num - 2, memo);

    return memo[num];
}

int fibonacci(int num){
    vector<int> memo(num + 1, -1);
    return fibRec(num, memo);
}

int main(){

    int num; cin >> num;

    cout << fibonacci(num) << endl;

    return 0;
}