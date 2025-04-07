#include <bits/stdc++.h>
using namespace std;

int sumWeights(vector<pair<int, int>> &knapsack){
    int sum = 0;
    for(int i=0 ; i < knapsack.size() ; i++){
        sum += knapsack[i].first;
    }
    return sum;
}

int sumValues(vector<pair<int, int>> &knapsack){
    int sum = 0;
    for(int i=0 ; i < knapsack.size() ; i++){
        sum += knapsack[i].second;
    }
    return sum;
}

bool verifyWeight(const vector<pair<int, int>> &weight, vector<pair<int, int>> &knapsack, int level, int limit){
    if(sumWeights(knapsack) + weight[level].first > limit){
        return false;
    }
    return true;
}


void solve(const vector<pair<int, int>> &weight, vector<pair<int, int>> &knapsack, int level, int limit, int &answer, vector<pair<int, int>> &bestKnapsack){
    if(level == weight.size()){
        return;
    }

    int sum = 0;

    for(int i = level ; i < weight.size() ; i++){
        if(verifyWeight(weight, knapsack, level, limit)){
            knapsack.push_back(weight[i]);
            sum = sumValues(knapsack);
            if(sum > answer){
                answer = sum;
                bestKnapsack = knapsack;
            }
            solve(weight, knapsack, i + 1, limit, answer, bestKnapsack);
            knapsack.pop_back();
        }
    }
}

int main(){

    vector<pair<int, int>> weight;
    vector<pair<int, int>> knapsack;

    // first is weight, and second is price 
    weight.push_back(make_pair(3, 4));
    weight.push_back(make_pair(4, 5));
    weight.push_back(make_pair(5, 7));
    weight.push_back(make_pair(6, 8));

    cout<<"Ingrese el limite de la mochila: "<<endl;
    int limit; cin>>limit;
    int answer = 0;
    
    vector<pair<int, int>> bestKnapsack;

    solve(weight, knapsack, 0, limit, answer, bestKnapsack);
    
    if(answer != 0){
        cout<<"La respuesta es : "<<answer<<endl;
        for(auto &item : bestKnapsack){
            cout << "Peso: " << item.first << ", Valor: " << item.second << endl;
        }
    }
    else{
        cout<<"No existe solucion"<<endl;
    }
    
    return 0;
}