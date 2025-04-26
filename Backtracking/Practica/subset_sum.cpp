#include <bits/stdc++.h>
using namespace std;
bool flag = false;

void printSolution(vector<int> &result){
    for(auto num:result){
        cout<<num<<" ";
    }
    cout<<endl;
} 

bool verifyNum(const vector<int> &pacheco, vector<int> &result, int sum, int level){
    if(accumulate(result.begin(), result.end(), 0) + pacheco[level] > sum){
        return false;
    }
    return true;    
}

void solve(const vector<int> &pacheco, vector<int> &result, int sum, int length, int level){
    if(level == length){
        return;
    }

    for(int i = level ; i < length ; i++){
        if(verifyNum(pacheco, result, sum, i)){
            result.push_back(pacheco[i]);
            if(accumulate(result.begin(), result.end(),0) == sum){
                flag = true;
                printSolution(result);
            }
            solve(pacheco, result, sum, length, i + 1);
            result.pop_back();
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

    if(!flag){
        cout<<"There is not solution"<<endl;
    }

    return 0;
}