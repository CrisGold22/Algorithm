#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void merge(int *array, int left, int mid, int right)
{

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = array[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        rightArray[i] = array[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = left;

    int decimal1, decimal2;

    while (i < n1 and j < n2)
    {
        decimal1 = leftArray[i]%100;
        decimal1/=10;
        decimal2 = rightArray[j]%100;
        decimal2/=10;
        if (decimal1<=decimal2)
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = leftArray[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int left, int right)
{

    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

void print(int *array)
{
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{

    int array[7];
    int id, impact, risk;

    ifstream archivo("EX1_01_2024_1_datos.txt", ios::in);
    if (not archivo.is_open())
    {
        cout << "ERROR datos.txt" << endl;
        exit(1);
    }

    for (int i = 0; i < 7; i++)
    {
        archivo >> id;
        if (archivo.eof())
            break;
        archivo >> impact >> risk;
        array[i] = id * 100 + impact * 10 + risk;
    }

    print(array);
    mergeSort(array, 0, 6);
    print(array);

    return 0;
}