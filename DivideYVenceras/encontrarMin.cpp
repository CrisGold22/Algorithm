#include <iostream>
#include <cstring>

using namespace std;

void findMaxNumber(int *array, int left, int right, int &num){

    if(left >= right){
        return;
    }
    int mid = (left + right)/2;

    if(array[mid] > num){
        num = array[mid];
    }

    findMaxNumber(array, left, mid, num);
    findMaxNumber(array, mid + 1, right, num);
}

int main(){

    int array[11] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int cantidad = 11;
    int maxNumber = 0;
    
    findMaxNumber(array, 0, cantidad - 1, maxNumber);
    cout<<maxNumber<<endl;
    return 0;
}