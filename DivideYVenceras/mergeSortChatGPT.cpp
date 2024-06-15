#include <iostream>
#include <fstream>

using namespace std;

void mergemid(int *array, int left, int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1], rightArray[n2];

    for(int i=0; i < n1 ; i++){
        leftArray[i] = array[left + i];
    }

    for(int i=0; i < n2 ; i++){
        rightArray[i] = array[mid + 1 + i];
    }

    int i=0 , j=0;
    int k = left;

    while(j < n1 and j < n2){
        if(leftArray[i] <= rightArray[j]){
            array[k] = leftArray[i];
            i++;
        }
        else{
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while(j<n2){
        array[k] = rightArray[j];
        j++;
        k++;
    }

}

void mergesort(int *array, int left, int right){

    if(left >= right){
        return;
    }

    int mid = (left + right)/2;

    mergesort(array, left, mid);
    mergesort(array, mid + 1, right);

    mergemid(array, left, mid, right);
}

int main(){

    int array[] = {6, 4, 5, 2, 3, 1};

    for(int i=0; i < 6 ; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    mergesort(array, 0, 6 - 1);

    for(int i=0; i < 6 ; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}