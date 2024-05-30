#include <iostream>
#include <cmath>

using namespace std;

void findNumber(int *array, int left, int right){
    int mid;
    //caso paca un elemento 
    if(left > right){
        return;
    }
    if(left == right){
        cout<<array[left]<<endl; 
        return;
    }

    mid = (left + right-1)/2;
    //caso para dos elementos
    if(mid%2==0){
        if(array[mid] == array[mid + 1]){
            findNumber(array, mid + 2, right);
        }
        else{
            findNumber(array, left, mid);
        }
    }
    else{
        if(array[mid] == array[mid - 1]){
            findNumber(array, mid + 1, right);
        }
        else{
            findNumber(array, left, mid-1);
        }
    }

    //recursion para dividir el algoritmo original en en dos mitades


}

int main(){

    int array[11] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    int cantidad = 10;

    findNumber(array, 0, cantidad);

    return 0;
}