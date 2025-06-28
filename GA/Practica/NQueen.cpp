#include <bits/stdc++.h>
using namespace std;

struct Caso {
    vector<int> cromosoma; // cromosoma[i] = columna de la reina en la fila i
    int fitness;

    // Generar cromosoma válido: una permutación de 0 a n-1
    void generarCromosoma(int n) {
        cromosoma.resize(n);
        iota(cromosoma.begin(), cromosoma.end(), 0); // [0, 1, ..., n-1]
        random_shuffle(cromosoma.begin(), cromosoma.end());
        fitness = calcularConflictos(n);
    }

    // Calcular conflictos: solo se deben evaluar diagonales (no filas ni columnas)
    int calcularConflictos(int n) {
        int conflictos = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(i - j) == abs(cromosoma[i] - cromosoma[j])) {
                    conflictos++;
                }
            }
        }
        return conflictos;
    }

    // Mutar: intercambiar dos columnas (posiciones del cromosoma)
    void mutar(double prob) {
        if (((double)rand() / RAND_MAX) < prob) {
            int i = rand() % cromosoma.size();
            int j = rand() % cromosoma.size();
            swap(cromosoma[i], cromosoma[j]);
        }
    }
};

// Generar población inicial
void generarPoblacion(vector<Caso>& poblacion, int n) {
    for (auto& caso : poblacion) {
        caso.generarCromosoma(n);
    }
}

// Cruce por punto aleatorio (Order Crossover - OX simplificado)
Caso cruzar(const Caso& padre1, const Caso& padre2) {
    int n = padre1.cromosoma.size();
    Caso hijo;
    hijo.cromosoma.resize(n, -1);

    int punto1 = rand() % n;
    int punto2 = rand() % n;
    if (punto1 > punto2) swap(punto1, punto2);

    // Copiar segmento del padre1
    for (int i = punto1; i <= punto2; ++i) {
        hijo.cromosoma[i] = padre1.cromosoma[i];
    }

    // Rellenar con valores del padre2
    int index = (punto2 + 1) % n;
    for (int i = 0; i < n; ++i) {
        int val = padre2.cromosoma[(punto2 + 1 + i) % n];
        if (find(hijo.cromosoma.begin(), hijo.cromosoma.end(), val) == hijo.cromosoma.end()) {
            hijo.cromosoma[index] = val;
            index = (index + 1) % n;
        }
    }

    hijo.fitness = hijo.calcularConflictos(n);
    return hijo;
}

// Algoritmo Genético
Caso algoritmoGenetico(int n, int tamPoblacion, int generaciones, double mutacion) {
    vector<Caso> poblacion(tamPoblacion);
    generarPoblacion(poblacion, n);

    for (int gen = 0; gen < generaciones; ++gen) {
        // Ordenar por fitness (menor es mejor)
        sort(poblacion.begin(), poblacion.end(), [](const Caso& a, const Caso& b) {
            return a.fitness < b.fitness;
        });

        cout << "Generación " << gen + 1 << " - Mejor fitness: " << poblacion[0].fitness << endl;
        // if (poblacion[0].fitness == 0) break;

        // Selección por torneo
        vector<Caso> nuevaPoblacion;
        nuevaPoblacion.push_back(poblacion[0]); // elitismo

        while (nuevaPoblacion.size() < tamPoblacion) {
            Caso padre1 = poblacion[rand() % (tamPoblacion / 2)];
            Caso padre2 = poblacion[rand() % (tamPoblacion / 2)];
            Caso hijo = cruzar(padre1, padre2);
            hijo.mutar(mutacion);
            nuevaPoblacion.push_back(hijo);
        }

        poblacion = nuevaPoblacion;
    }

    return *min_element(poblacion.begin(), poblacion.end(), [](const Caso& a, const Caso& b) {
        return a.fitness < b.fitness;
    });
}

int main() {
    int n, tamPoblacion, generaciones;
    double mutacion;
    srand(time(0));

    cout << "Ingrese el valor de N (tamaño del tablero): ";
    cin >> n;
    cout << "Ingrese el tamaño de la población: ";
    cin >> tamPoblacion;
    cout << "Ingrese el número de generaciones: ";
    cin >> generaciones;
    cout << "Ingrese la probabilidad de mutación (por ejemplo, 0.2): ";
    cin >> mutacion;

    Caso mejor = algoritmoGenetico(n, tamPoblacion, generaciones, mutacion);

    // Mostrar la mejor solución
    cout << "\nMejor solución encontrada (columna por fila):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Fila " << i << " -> Columna " << mejor.cromosoma[i] << endl;
    }
    cout << "Conflictos: " << mejor.fitness << endl;

    return 0;
}
