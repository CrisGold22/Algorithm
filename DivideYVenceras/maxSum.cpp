#include <iostream>
#include <climits>

using namespace std;

int maximo(int a, int b) { 
    if (a > b)
        return a;
    else
        return b;
}

int maximo3(int a, int b, int c) { 
    return maximo(maximo(a, b), c); 
}

// Encuentra la suma m�xima posible en arr[] tal que arr[m] sea parte de ella
int maximaSumaCruzada(int arr[], int posicion_inicial, int posicion_medio, int posicion_final) 
{
    int suma = 0;
    int suma_izquierda = -999999;
    for (int i = posicion_medio; i >= posicion_inicial; i--) 
    {
        suma = suma + arr[i];
        if (suma > suma_izquierda) 
            suma_izquierda = suma;
    }

    suma = 0;
    int suma_derecha = -999999;
    for (int i = posicion_medio+1; i <= posicion_final; i++) 
    {
        suma = suma + arr[i];
        if (suma > suma_derecha) 
            suma_derecha = suma;
    }
    return maximo3(suma_izquierda + suma_derecha, suma_izquierda, suma_derecha);
}

int maximaSumaSubarreglo(int arr[], int posicion_inicial, int posicion_final) 
{
   //CASO BASE: solo un elemento
   if (posicion_inicial == posicion_final) 
     return arr[posicion_inicial];

   //Encontramos el punto medio
   int posicion_medio = (posicion_inicial + posicion_final)/2;
   return maximo3(maximaSumaSubarreglo(arr, posicion_inicial, posicion_medio),//subarreglo izquierda
                  maximaSumaSubarreglo(arr, posicion_medio+1, posicion_final),//subarreglo derecha
                  maximaSumaCruzada(arr, posicion_inicial, posicion_medio, posicion_final));//cruzado
}


int main() 
{
   int arr[] = {-2, 3, -4, 5, 7};
   int n = 5;
   int maxima_suma = maximaSumaSubarreglo(arr, 0, n-1);
   cout << "La m�xima suma contigua es: " << maxima_suma;
   return 0;
}