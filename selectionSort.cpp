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

void Swap(int &m, int &n)
{
    int tmp = m;
    m = n;
    n = tmp;
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {        
        // find the minimum element from position i to the end
        int m = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[m]) m = j; // m holds the min position
        }

        // swap a[i] and the minimum element
        Swap(a[i], a[m]);
    }
}

int main()
{
    int myArr[100];
    int size = 13;

    Init(myArr, size);
    Show(myArr, size);

    selectionSort(myArr, size);
    Show(myArr, size);

    return 0;
}