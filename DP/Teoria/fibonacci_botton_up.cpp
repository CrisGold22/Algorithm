#include <bits/stdc++.h>
using namespace std;

int fibonacci(int num){
    vector<int> dp(num + 1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2 ; i <= num ; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[num];
}

int main(){

    int num; cin>>num;
    cout << fibonacci(num)<<endl;

    return 0;
}