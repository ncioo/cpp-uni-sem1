#include <iostream>
#include <stdio.h>

using namespace std;

int max(int *array, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
void sort(int **array, int n, int m)
{
    int *temp;
    for (long i = 0; i < n; i++)
    {
        for (long j = n - 1; j > i; j--)
        {
            if (max(*(array + j - 1), n) > max(*(array + j), n))
            {
                temp = *(array + j - 1);
                *(array + j - 1) = *(array + j);
                *(array + j) = temp;
            }
        }
    }
}
int main()
{
    int n, m;

    cout << "Введите количество строк и количество столбцов (NxM): " << endl;

    if (!((cin >> n) && (cin >> m)))
    {
        cout << "\nВведите число" << endl;
        return 0;
    }

    int **array = new int *[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cout << "[" << i << "][" << j << "] = ";
            cin >> array[i][j];
        }
    }

    cout << "Ваша матрица: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }

    sort(array, n, m);

    cout << "Ваша переработанная матрица: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    system("pause");
    return 0;
}