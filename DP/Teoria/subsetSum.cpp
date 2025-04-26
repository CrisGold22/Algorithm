#include <bits/stdc++.h>
using namespace std;

bool solve(const vector<int> &billetes, int cantidad){
    int n = billetes.size();
    vector<vector<bool>> dp (n + 1, vector<bool> (cantidad + 1, false));

    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = true;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= cantidad ; j++){
            if(j < billetes[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - billetes[i - 1]];
            }
        }
    }

    return dp[n][cantidad];
}

int main(){

    vector<int> billetes = {20, 20, 50, 50, 50, 100};
    int cantidad; cin>>cantidad;

    if(solve(billetes, cantidad)){
        cout<<"Puede entragar el vuelo"<<endl;
    }
    else{
        cout<<"No se puede entragar el vuelo"<<endl;
    }

    return 0;
}