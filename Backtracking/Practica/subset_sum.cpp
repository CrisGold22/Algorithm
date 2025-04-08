#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<int> &result){

} 

bool verifyNum(const vector<int> &pacheco, vector<int> &result, int sum, int level){
    if(accumulate(result.begin(), result.end(), 0) + pacheco[level] > sum){
        return false;
    }
    return true;    
}

void solve(const vector<int> &pacheco, vector<int> &result, int sum, int length, int level){
    if(level == length){
        if(accumulate(result.begin(), result.end(),0) == sum){
            printSolution(result);
        }
        return;
    }

    for(int i = level ; i < length ; i++){
        if(verifyNum(pacheco, result, sum, i)){
            
        }
    }

}

int main(){

    int num; cin>>num;
    vector<int> pacheco (num);
    vector<int> result;

    for(auto &a:pacheco){
        cin>>a;
    }
    
    int sum; cin>>sum;

    solve(pacheco, result, sum, num, 0);

    return 0;
}