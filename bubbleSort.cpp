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

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {       
        for (int j = 0; j < n - 1 - i; ++j)
        {            
            if (a[j] > a[j + 1])
                Swap(a[j], a[j + 1]);
        }        
    }
}

int main()
{
    int myArr[100];
    int size = 13;

    Init(myArr, size);
    Show(myArr, size);

    bubbleSort(myArr, size);
    Show(myArr, size);

    return 0;
}