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

// optimize bubbleSort
void bubbleSort2(int a[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; ++i)
    {    
        swapped = false; // no swap occur

        for (int j = 0; j < n - 1 - i; ++j)
        {            
            if (a[j] > a[j + 1])
            {
                Swap(a[j], a[j + 1]);
                swapped = true; // at least one swap occurs
            }
        }

        // if no swap occur, then finish
        if (!swapped)        
            break;
    }
}

int main()
{
    int myArr[100];
    int size = 13;

    Init(myArr, size);
    Show(myArr, size);

    bubbleSort2(myArr, size);
    Show(myArr, size);

    return 0;
}