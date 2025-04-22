#include <bits/stdc++.h>
using namespace std;

int dp_knap(const vector<int> &profit, const vector<int> &weight, int limit){
    int length = weight.size();
    vector<vector<int>> dp (length + 1, vector<int> (limit + 1));

    for(int i = 0 ; i <= length ; i++){
        for(int j = 0 ; j <= limit ; j++){
            if(i == 0 or j == 0){
                dp[i][j] = 0;
            }
            else{
                int pick = 0;
                if(weight[i - 1] <= j){
                    pick = profit[i - 1] + dp[i - i][j - weight[i -1]];
                }
                int notPick = dp[i - 1][j];
                dp[i][j] = max(pick, notPick);
            }
        }
    }
    
    return dp[length][limit];  
}

int knapSol(int limit){
    vector<int> profit = {1, 2, 3};
    vector<int> weight = {4, 5, 6};

    return dp_knap(profit, weight, limit);
}

int main(){
    int limit = 3;

    cout<<knapSol(limit)<<endl;

    return 0;
}