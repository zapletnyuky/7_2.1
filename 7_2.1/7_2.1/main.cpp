// Lab_7_2_1.cpp
// Заплетнюк Юлія Іванівна
// Лабораторна робота No 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 7
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int MaxMin(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));
    
    const int LOW = -100, HIGH = 100;
    
    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;
    int **a = new int*[k];
        for (int i = 0; i < k; i++)
          a[i]=new int[n];
    
    Create(a, k, n, LOW, HIGH);
    Print(a, k, n);
    
   cout << "MaxMin = " << MaxMin(a, k, n) << endl;
    for (int i=0; i<k; i++)
        delete [] a[i];
    delete []a;
    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i=0; i<k; i++)
        for (int j=0; j<n; j++)
            a[i][j] = Low + rand() % (High-Low+1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i=0; i<k; i++)
    {
        for (int j=0; j<n; j++)
            cout << setw(6) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int MaxMin(int** a, const int k, const int n)
{
    int min, max = -101;
    
    for (int i=0; i<k; i++)
    {
        min = a[i][0];
        for (int j=0; j<n; j++)
            if ( a[i][j] < min )
                min = a[i][j];
        if ( i == 0 )
            max = min;
        if ( min > max )
            max = min;
}
return max;
    
}
