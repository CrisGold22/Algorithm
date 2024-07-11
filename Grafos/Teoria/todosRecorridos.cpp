#include <iostream>
using namespace std;

const int V = 5; // Número de vértices

void imprimirCamino(int camino[], int longitud) {
    for (int i = 0; i < longitud; i++) {
        cout << camino[i] << " ";
    }
    cout << endl;
}

void buscarCaminos(int graph[V][V], int u, int d, bool visitado[], int camino[], int& longitud) {
    visitado[u] = true;
    camino[longitud] = u;
    longitud++;

    if (u == d) {
        imprimirCamino(camino, longitud);
    } else {
        for (int i = 0; i < V; i++) {
            if (graph[u][i] && !visitado[i]) {
                buscarCaminos(graph, i, d, visitado, camino, longitud);
            }
        }
    }

    longitud--;
    visitado[u] = false;
}

void encontrarCaminos(int graph[V][V], int origen, int destino) {
    bool visitado[V] = {false};
    int camino[V];
    int longitud = 0;
    buscarCaminos(graph, origen, destino, visitado, camino, longitud);
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };

    int origen = 0; // Nodo de origen
    int destino = 4; // Nodo de destino

    cout << "Todos los caminos del nodo " << origen << " al nodo " << destino << " son:" << endl;
    encontrarCaminos(graph, origen, destino);

    return 0;
}
