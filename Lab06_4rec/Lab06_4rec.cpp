#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void Sort(int* a, const int size, int i)
{
    int max = a[i];
    int imax = i;
    for (int j = i + 1; j < size; j++)
        if (max < a[j])
        {
            max = a[j];
            imax = j;
        }

    if (a[i] % 2 > 0) {
        a[imax] = a[i];
        a[i] = max;
    }


    if (i < size - 2)
        Sort(a, size, i + 1);
}

int Max(int* a, const int size, int i, int max)
{
    if (a[i] > max)
        max = a[i];
    if (i < size - 1)
        return Max(a, size, i + 1, max);
    else
        return max;
}

int Min(int* a, const int size, int i, int min)
{
    if (a[i] < min)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, i + 1, min);
    else
        return min;
}

void f1(int* a, const int size, int& s, int& d, int low, int high, int i) {
    if (i < size) {
        if (a[i] > 0)
            s += a[i];
        if (a[i] >= low && a[i] <= high)
            d *= a[i];
        f1(a, size, s, d, low, high, i + 1);
    }
}

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int main()
{
    int n;
    cout << "n = "; cin >> n;

    int* a = new int[n];
    Create(a, n, -10, 10, 0);
    Print(a, n, 0);

    int s = 0;
    int d = 1;

    int low = Min(a, n, 0, a[0]);
    int high = Max(a, n, 0, a[0]);

    f1(a, n, s, d, low, high, 0);
    cout << "s = " << s << endl;
    cout << "d = " << d << endl;

    Sort(a, n, 0);
    Print(a, n, 0);

    delete[] a;
    return 0;
}
