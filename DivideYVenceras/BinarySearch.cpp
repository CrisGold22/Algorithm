#include <iostream>
#include <array>
#include <cmath>

using namespace std;

int binarySearch(int *array, int num, int cantidad){
    int mid, left = 0, right = cantidad -1;

    while(left <= right){
        mid = (left + right)/2;
        if(num == array[mid]){
            return mid;
        }
        else if (array[mid] < num){
            left = mid + 1; 
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){

    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int cantidad = 10;

    if(binarySearch(array, 2, cantidad)!=-1){
        cout<<"El elemento se encuentra en la posicion "<<binarySearch(array, 2, cantidad)<<endl;
    }
    else{
        cout<<"No se encuentra el elemento pedido"<<endl;
    }
    
    return 0;
}