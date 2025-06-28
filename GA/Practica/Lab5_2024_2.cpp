#include <bits/stdc++.h>
using namespace std;

#define TAM_POBLACION 20
#define TAM_MATRIZ 5
#define GENERACIONES 1000
#define PROB_CRUCE 0.8
#define MUTACION 0.1

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
    for(int i = 0 ; i < TAM_MATRIZ ; i++){
        int contador = 0;
        for(int j = 0 ; j < TAM_MATRIZ ; j++){
            if(caso.cromosoma[i * TAM_MATRIZ + j] == 1){
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
    // Paso 1: Calcular suma total del fitness
    double sumaFitness = 0.0;
    for (const auto& ind : poblacion) {
        sumaFitness += ind.fitness;
    }

    // Paso 2: Generar un número aleatorio entre 0 y sumaFitness
    double r = ((double)rand() / RAND_MAX) * sumaFitness;

    // Paso 3: Recorrer la población y elegir el individuo correspondiente
    double acumulado = 0.0;
    for (const auto& ind : poblacion) {
        acumulado += ind.fitness;
        if (acumulado >= r) {
            return ind;
        }
    }

    // En caso de redondeo numérico, devolver el último
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
            while (num1 == num2) num2 = rand() % TAM_MATRIZ; // Asegurar que no sea el mismo índice

            swap(hijo.cromosoma[i * TAM_MATRIZ + num1], hijo.cromosoma[i * TAM_MATRIZ + num2]); // Intercambiar tareas
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
    //aqui se realiza la evaluacion de cada poblacion
    evaluar_poblacion(poblacion);
    //impresion del mejor elemento de la primera poblacion
    auto mejorElemento = max_element(poblacion.begin(), poblacion.end(), [](const Individuo &a, const Individuo &b){
        return a.fitness > b.fitness;
    });
    vector<int> mejorFitness = {mejorElemento->fitness};
    cout << "Poblacion inicial, best_fitness = " << mejorElemento->fitness << endl;

    for(int i = 0 ; i < GENERACIONES ; i++){
        //seleccion de parejas por metodo de la ruleta
        vector<pair<Individuo, Individuo>> listaPadres;
        for(int i = 0 ; i < poblacion.size() / 2 ; i++){
            Individuo ind1 = seleccionRuleta(poblacion), ind2 = seleccionRuleta(poblacion);
            listaPadres.push_back({ind1, ind2});
        }

        //cruce los padres para la formacion de dos hijos
        vector<Individuo> nueva_poblacion;
        for(auto padres : listaPadres){
            pair<Individuo, Individuo> hijos = cruzar(padres.first, padres.second); //formacion de los hijos
            //mutacion de los hijos
            mutarHijo(hijos.first);
            mutarHijo(hijos.second);
            //ingreso de los hijos mutados
            nueva_poblacion.push_back(hijos.first);
            nueva_poblacion.push_back(hijos.second);
        }

        evaluar_poblacion(nueva_poblacion);
        
        poblacion = reemplazo(nueva_poblacion, poblacion);
    }

}

int main(){

    srand(time(0));
    //Primero, se realiza la creacion de poblacion inicial
    vector<Individuo> poblacion = inicializar_poblacion();
    
    //Donde empieza el algoritmo genetico
    algoritmo_genetico(poblacion);


    return 0;
}