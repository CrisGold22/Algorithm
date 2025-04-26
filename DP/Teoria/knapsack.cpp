#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &profit, const vector<int> &weight, int num){
    int n = profit.size();

    vector<vector<int>> dp(n + 1, vector<int> (num + 1));

    for(int i = 0 ; i < n + 1; i++){
        dp[i][0] = 0;
    }

    for(int i = 0 ; i < num + 1; i++){
        dp[0][i] = 0;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= num ; j++){
            if(j < weight[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + profit[i - 1]);
            }
        }
    }

    return dp[n][num];
}

int main(){
    // problema de la mochila

    vector<int> profit = {1, 2, 3}, weight = {4, 5, 1};
    int num = 9;

    cout<<solve(profit, weight, num)<<endl;

    return 0;
}