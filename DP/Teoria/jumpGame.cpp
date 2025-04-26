#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &ciudades, int num){
    int n = ciudades.size();

    vector<int> dp (n, INT_MAX);

    dp[0] = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= ciudades[i] ; j++){
            if(i + j < n){
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
    }

    return dp[num - 1];
}

int main(){

    vector<int> ciudades = {5, 2, 1, 4, 1};
    int num; cin>>num;

    cout<<solve(ciudades, num)<<endl;
    return 0;
}