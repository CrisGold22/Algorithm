#include <iostream>
#include <limits.h> //para la constante m�xima de enteros INT_MAX

#define V 5 //cantidad de v�rtices del grafo

using namespace std;

void MostrarSolucion(int distancias[]){
	for (int i=0; i<V; i++){
		cout << i << " " << distancias[i]<< endl;
	}
}

int MinimaDistancia(int distancias[], bool visitado[]){
	int indice_minimo, minima_distancia=INT_MAX;
	
	for (int i=0; i<V; i++){
		if (visitado[i]==false && distancias[i]<=minima_distancia){
			minima_distancia=distancias[i];
			indice_minimo=i;
		}
	}
	return indice_minimo;	
}
void dijkstra(int grafo[V][V], int origen){
	int distancias[V];
	bool visitados[V];
	
	for (int i=0; i<V; i++){
		distancias[i]=INT_MAX;
		visitados[i]=false;
	}
	
	distancias[origen]=0;
	
	for (int vertice=0; vertice<V-1; vertice++){
		int vertice_minima_distancia=MinimaDistancia(distancias, visitados);

		visitados[vertice_minima_distancia]=true;
		
		for (int i=0; i<V; i++){
			if (!visitados[i]
			&& grafo[vertice_minima_distancia][i]
			&& distancias[vertice_minima_distancia]!= INT_MAX
			&& distancias[vertice_minima_distancia] + grafo[vertice_minima_distancia][i] < distancias[i]) 
			distancias[i]=distancias[vertice_minima_distancia] + grafo[vertice_minima_distancia][i];
		}
	}
	MostrarSolucion(distancias); 
}

int main (){
	int grafo[V][V]={{0,3,0,7,0},
			{3,0,4,2,0},
			{0,4,0,5,6},
			{7,2,5,0,4},
			{0,0,6,4,0}};
			
	dijkstra(grafo, 0);
	
	return 0;
}