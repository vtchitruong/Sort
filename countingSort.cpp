#include <iostream>
#include <stdlib.h>

using namespace std;

void Init(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = rand() % 10;
    }
}

void Show(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';        
    }
    cout << endl;
}

void CountingSort(int a[], int n)
{
    // countArr is an array whose index range covers the entire range of values in array A
    int countArr[10] = { 0 }; // 10 is the maximum value of array A
    for (int i = 0; i < n; ++i)
    {
        // Each time a value occurs in array A, increase the counter at the index of countArr
        countArr[a[i]]++; 
    }

    // prepare for the last position which each element will take in the final ordered array (1-based position)
    for (int i = 1; i < 10; ++i)
    {
        countArr[i] += countArr[i - 1];
    }

    int res[n]; // result array
    for (int i = 0; i < n; ++i)
    {
        // put each element of A to its proper position
        res[--countArr[a[i]]] = a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        a[i] = res[i];
    }
}

int main()
{
    int myArr[100];
    int size = 30;

    Init(myArr, size);
    Show(myArr, size);

    CountingSort(myArr, size);
    Show(myArr, size);

    return 0;
}