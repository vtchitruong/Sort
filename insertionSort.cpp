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

void insertionSort(int a[], int n)
{
    int tmp;
    for (int i = 1; i < n; ++i)
    {
        tmp = a[i]; // hold the value of a[i]   

        int j = i; // start from position i and iterate back to the head of the array

        // if there is an element less than tmp (aka a[i]), then shift it one position to the right
        // so that there will be an available postion for a[i] inserting
        while (a[j - 1] > tmp)
        {
            a[j] = a[j - 1];
            j--;
        }

        a[j] = tmp; // insert tmp (aka a[i]) to that available position
    }
}

int main()
{
    int myArr[100];
    int size = 13;

    Init(myArr, size);
    Show(myArr, size);

    insertionSort(myArr, size);
    Show(myArr, size);

    return 0;
}