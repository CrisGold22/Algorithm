#include <iostream>

using namespace std;

void merge(int *array, int left, int mid, int right){
    int p , q;

    int longitud1, longitud2;
    longitud1 = (mid + 1) - left;
    longitud2 = right - mid; 

    int arreglo1[longitud1 + 1];
    int arreglo2[longitud2 + 1];

    arreglo1[longitud1] = 9999999;
    arreglo2[longitud2] = 9999999;

    for(int i=left ; i < mid + 1 ; i++){
        arreglo1[i - left] = array[i];
    }
    for(int i=mid + 1; i <= right ; i++){
        arreglo2[i - (mid + 1)] = array[i];
    }
    p = q = 0;

    for(int i=left ; i<=right ; i++){
        if(arreglo1[p]<arreglo2[q]){
            array[i] = arreglo1[p++];
        }
        else{
            array[i] = arreglo2[q++];
        }
    }
}

void mergesort(int *array, int left, int right){
    int mid;
    if(left == right){
        return;
    }
    mid = (left + right)/2;

    mergesort(array, left, mid);
    mergesort(array, mid + 1, right);
    merge(array, left, mid, right);
}

int main(){

    int a; cin>>a;
    int array[a]{};

    for(int i = 0 ; i<a ; i++){
        cin>>array[i];
    }

    mergesort(array, 0, a-1);
    
    for(int i=0 ; i < a ; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;