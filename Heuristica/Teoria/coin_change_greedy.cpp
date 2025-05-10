#include <bits/stdc++.h>
using namespace std;

int coin_change_greedy(vector<int> coins, int num){
    sort(coins.begin(), coins.end(), greater());

    for(int i = 0 ; i < coins.size();){
        if(num < coins[i]){
            i++;
        }   
        else{
            num -= coins[i];
        }
    }

    if(num == 0){
        return 1;
    }
    else{
        return 0;
    }

}

int main(){

    vector<int> coins = {25, 10, 5, 1};
    int num = 63;

    int result = coin_change_greedy(coins, num);
    
    if(result == 1){
        cout<<"Si hay respuesta"<<endl;
    }
    else{
        cout<<"No se puede puede hacer el cambio exacto con el enfoque voraz"<<endl;
    }

    return 0;
}