#include <bits/stdc++.h>
using namespace std;

struct Item{
    int peso;
    int valor;
    int id;
    double ratio;
};

// local search
vector<int> localSearch(const vector<int>& solucion, const vector<Item>& items, int capacidad) {
    vector<bool> en_mochila(items.size() + 1, false); // asumimos id empieza desde 1
    int peso_actual = 0;
    int valor_actual = 0;

    for (int id : solucion) {
        en_mochila[id] = true;
        for (const auto& item : items) {
            if (item.id == id) {
                peso_actual += item.peso;
                valor_actual += item.valor;
                break;
            }
        }
    }

    vector<int> mejor_solucion = solucion;
    int mejor_valor = valor_actual;

    for (const auto& item : items) {
        if (en_mochila[item.id]) continue; // ya está incluido

        if (peso_actual + item.peso <= capacidad) {
            int nuevo_valor = valor_actual + item.valor;
            if (nuevo_valor > mejor_valor) {
                vector<int> nueva_solucion = mejor_solucion;
                nueva_solucion.push_back(item.id);
                mejor_solucion = nueva_solucion;
                mejor_valor = nuevo_valor;
                peso_actual += item.peso;
            }
        }
    }

    return mejor_solucion;
}

int verifica(const vector<Item>& items, double rcl) {
    int count = 0;
    for (const auto& item : items) {
        if (item.ratio >= rcl) count++;
    }
    return count;
}

// construction 
vector<int> construction(vector<Item> items, int capacidad, double alpha){

    sort(items.begin(), items.end(), [](Item a, Item b){
        return a.ratio < b.ratio;
    });

    vector<int> soluciones;

    int residual = capacidad;
    int valor = 0;

    while(not items.empty()){
        double beta = items[0].ratio, tauron = items.back().ratio;
        double rcl = beta - alpha * (beta - tauron);
        int ind = verifica(items, rcl);
        int ind_aleatorio = rand() % ind;

        if(residual - items[ind_aleatorio].peso >= 0){
            soluciones.push_back(items[ind_aleatorio].id);
            residual -= items[ind_aleatorio].peso;
            valor += items[ind_aleatorio].valor;
        }
        items.erase(items.begin() + ind_aleatorio);
    }

    return soluciones;
}

int sumarValores(const vector<int>& solucion, const vector<Item>& items) {
    int total = 0;
    for (int id : solucion) {
        for (const auto& item : items) {
            if (item.id == id) {
                total += item.valor;
                break;
            }
        }
    }
    return total;
}


// grasp algoritm
vector<int> grasp(const vector<Item> &items, int capacidad, int max_iter, double alpha){
    vector<int> bestSolution;
    int bestValue = INT_MIN;

    for(int i = 0 ; i < max_iter ; i++){
        vector<int> solution = construction(items, capacidad, alpha);
        solution = localSearch(solution, items, capacidad);

        int currentValue = sumarValores(solution, items);
        if(currentValue > bestValue){
            bestValue = currentValue;
            bestSolution = solution;
        }
    }

    return bestSolution;
}

// funcion main
int main(){

    vector<Item> items = {
        { 10, 60, 1}, { 20, 100, 2 }, { 30, 120, 3 }, {40, 80, 4}
    };

    for(auto &item : items){
        item.ratio = (double)item.valor / item.peso;
    }

    int capacidad = 50;
    int max_iter = 100;
    double alpha = 0.3;

    vector<int> solution = grasp(items, capacidad, max_iter, alpha);

    for (int id : solution) {
        cout << "Objeto " << id << " ";
    }
    cout << "\nValor total: " << sumarValores(solution, items) << endl;


    return 0;
}