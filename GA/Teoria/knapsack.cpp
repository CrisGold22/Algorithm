#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int NUM_OBJETOS = 3;
const int CAPACIDAD = 50;
const int TAM_POBLACION = 6;
const int GENERACIONES = 50;
const float TASA_MUTACION = 0.1;

vector<int> valores = {60, 100, 120};
vector<int> pesos = {10, 20, 30};

// Representa un individuo (una solución)
struct Individuo {
    vector<int> cromosoma;
    int fitness;

    Individuo() {
        cromosoma.resize(NUM_OBJETOS);
        for (int i = 0; i < NUM_OBJETOS; i++)
            cromosoma[i] = rand() % 2;
        fitness = calcularFitness();
    }

    int calcularFitness() {
        int valor_total = 0, peso_total = 0;
        for (int i = 0; i < NUM_OBJETOS; i++) {
            if (cromosoma[i]) {
                valor_total += valores[i];
                peso_total += pesos[i];
            }
        }
        return (peso_total <= CAPACIDAD) ? valor_total : 0;
    }

    void mutar() {
        for (int i = 0; i < NUM_OBJETOS; i++) {
            if ((float)rand() / RAND_MAX < TASA_MUTACION) {
                cromosoma[i] = 1 - cromosoma[i]; // Flip bit
            }
        }
        fitness = calcularFitness();
    }
};

// Operación de cruce entre dos padres
Individuo cruzar(const Individuo &padre1, const Individuo &padre2) {
    Individuo hijo;
    for (int i = 0; i < NUM_OBJETOS; i++) {
        hijo.cromosoma[i] = (rand() % 2) ? padre1.cromosoma[i] : padre2.cromosoma[i];
    }
    hijo.fitness = hijo.calcularFitness();
    return hijo;
}

bool compararFitness(const Individuo &a, const Individuo &b) {
    return a.fitness > b.fitness;
}

int main() {
    srand(time(0));
    vector<Individuo> poblacion(TAM_POBLACION);

    for (int generacion = 0; generacion < GENERACIONES; generacion++) {
        sort(poblacion.begin(), poblacion.end(), compararFitness);

        // Mostrar mejor individuo
        cout << "Generación " << generacion
             << " | Mejor valor: " << poblacion[0].fitness
             << " | Cromosoma: ";
        for (int bit : poblacion[0].cromosoma)
            cout << bit;
        cout << endl;

        // Selección de los mejores para reproducción
        vector<Individuo> nueva_poblacion;
        nueva_poblacion.push_back(poblacion[0]); // elitismo
        nueva_poblacion.push_back(poblacion[1]);

        // Cruce y mutación
        while (nueva_poblacion.size() < TAM_POBLACION) {
            Individuo hijo = cruzar(poblacion[0], poblacion[1]);
            hijo.mutar();
            nueva_poblacion.push_back(hijo);
        }

        poblacion = nueva_poblacion;
    }

    return 0;
}
