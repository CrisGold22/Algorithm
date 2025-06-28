#include <bits/stdc++.h>
using namespace std;

#define TAM_POBLACION 20
#define TAM_MATRIZ 5
#define GENERACIONES 1000
#define PROB_CRUCE 0.8
#define MUTACION 0.1
#define ELITE 2

vector<vector<int>> ganancia = {{9, 2, 7, 8 ,6},
                                {6, 4, 3, 7, 8},
                                {5, 8, 1, 8, 3},
                                {7, 6, 9, 4, 2},
                                {8, 6, 7, 5, 9}};

struct Individuo{
    vector<int> cromosoma;
    int fitness;

    Individuo(){
        cromosoma.resize(TAM_MATRIZ * TAM_MATRIZ);
        fitness = 0;
    }
};

bool verificarCromosoma(const Individuo &caso){
    // Verificar filas
    for(int i = 0 ; i < TAM_MATRIZ ; i++){
        int contador = 0;
        for(int j = 0 ; j < TAM_MATRIZ ; j++){
            if(caso.cromosoma[i * TAM_MATRIZ + j] == 1){
                contador++;
            }
        }
        if(contador > 1) return false;
    }
    // Verificar columnas
    for(int j = 0; j < TAM_MATRIZ; j++) {
        int contador = 0;
        for(int i = 0; i < TAM_MATRIZ; i++) {
            if(caso.cromosoma[i * TAM_MATRIZ + j] == 1) {
                contador++;
            }
        }
        if(contador > 1) return false;
    }
    return true;
}

vector<Individuo> inicializar_poblacion(){
    vector<Individuo> poblacion_valida;

    while(poblacion_valida.size() < TAM_POBLACION){
        Individuo pacheco;
        for(int i = 0 ; i < TAM_MATRIZ * TAM_MATRIZ ; i++){
            pacheco.cromosoma[i] = rand() % 2;
        }
        if(verificarCromosoma(pacheco)){
            poblacion_valida.push_back(pacheco);
        }
    }
    return poblacion_valida;
}

void evaluar_poblacion(vector<Individuo> &poblacion){
    for(auto &num : poblacion){
        int gananciaTotal = 0;
        for(int i = 0 ; i < num.cromosoma.size() ; i++){
            if(num.cromosoma[i]){
                gananciaTotal += ganancia[i / TAM_MATRIZ][i % TAM_MATRIZ];
            }
        }
        num.fitness = gananciaTotal;
    }
}

Individuo seleccionRuleta(const vector<Individuo>& poblacion) {
    double sumaFitness = 0.0;
    for (const auto& ind : poblacion) {
        sumaFitness += ind.fitness;
    }

    double r = ((double)rand() / RAND_MAX) * sumaFitness;

    double acumulado = 0.0;
    for (const auto& ind : poblacion) {
        acumulado += ind.fitness;
        if (acumulado >= r) {
            return ind;
        }
    }

    return poblacion.back();
}

pair<Individuo, Individuo> cruzar(const Individuo &padre1, const Individuo &padre2){
    vector<Individuo> poblacion_valida;

    while(poblacion_valida.size() < 2){
        Individuo pacheco;
        for(int i = 0 ; i < TAM_MATRIZ * TAM_MATRIZ ; i++){
            pacheco.cromosoma[i] = (rand() % 2) ? padre1.cromosoma[i] : padre2.cromosoma[i];
        }
        if(verificarCromosoma(pacheco)){
            poblacion_valida.push_back(pacheco);
        }
    }

    return make_pair(poblacion_valida[0], poblacion_valida[1]);
}

void mutarHijo(Individuo &hijo){
    for(int i = 0 ; i < TAM_MATRIZ ; i++){
        if (((double)rand() / RAND_MAX) <= MUTACION) {
            int num1 = rand() % TAM_MATRIZ;
            int num2 = rand() % TAM_MATRIZ;
            while (num1 == num2) num2 = rand() % TAM_MATRIZ;

            swap(hijo.cromosoma[i * TAM_MATRIZ + num1], hijo.cromosoma[i * TAM_MATRIZ + num2]);
        }
    }
}

vector<Individuo> reemplazo(vector<Individuo> nueva_poblacion, vector<Individuo> poblacion){
    vector<Individuo> siguiente_poblacion;
    poblacion.insert(poblacion.end(), nueva_poblacion.begin(), nueva_poblacion.end());
    sort(poblacion.begin(), poblacion.end(), [](Individuo &a, Individuo &b){
        return a.fitness > b.fitness;
    });

    for(int i = 0 ; i < TAM_POBLACION ; i++){
        siguiente_poblacion.push_back(poblacion[i]);
    }
    return siguiente_poblacion;
}

void algoritmo_genetico(vector<Individuo> &poblacion){
    evaluar_poblacion(poblacion);

    sort(poblacion.begin(), poblacion.end(), [](const Individuo &a, const Individuo &b){
        return a.fitness > b.fitness;
    });
    cout << "Poblacion inicial, best_fitness = " << poblacion[0].fitness << endl;

    for(int i = 0 ; i < GENERACIONES ; i++){
        vector<Individuo> nueva_poblacion(poblacion.begin(), poblacion.begin() + ELITE); // elitismo

        while(nueva_poblacion.size() < TAM_POBLACION){
            Individuo ind1 = seleccionRuleta(poblacion);
            Individuo ind2 = seleccionRuleta(poblacion);
            pair<Individuo, Individuo> hijos = cruzar(ind1, ind2);
            mutarHijo(hijos.first);
            mutarHijo(hijos.second);

            nueva_poblacion.push_back(hijos.first);
            if (nueva_poblacion.size() < TAM_POBLACION)
                nueva_poblacion.push_back(hijos.second);
        }
        poblacion = reemplazo(nueva_poblacion, poblacion);
        evaluar_poblacion(poblacion);

        sort(poblacion.begin(), poblacion.end(), [](const Individuo &a, const Individuo &b){
            return a.fitness > b.fitness;
        });
        if (i % 100 == 0) {
            cout << "Generacion " << i << " - Mejor fitness: " << poblacion[0].fitness << endl;
        }
    }

    cout << "\nMejor cromosoma final (ganancia: " << poblacion[0].fitness << "):\n";
    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            cout << poblacion[0].cromosoma[i * TAM_MATRIZ + j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    srand(time(0));
    vector<Individuo> poblacion = inicializar_poblacion();
    algoritmo_genetico(poblacion);
    return 0;
}
