#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    double array[20];
    int n, fill, minIndex, lastIndex;
    double cur, min = 0, res;

    cout << "Введите размер массива (3-20)" << endl;

    if (!(cin >> n))
    {
        cout << "\nВведите число" << endl;
        return 0;
    }
    if (n < 3 || n > 20)
    {
        cout << "\nРазмер не должен выходить за допустимые пределы" << endl;
        return 0;
    }

    cout << "1. Случайно\n2. Ввод с клавиатуры\nВыберите заполнение (" << n << " элементов):" << endl;
    cin >> fill;

    switch (fill)
    {
    case (1):
        for (int i = 0; i <= n; i++)
        {
            cur = rand() % 20 - 5;
            array[i] = cur;
        }
        break;
    case (2):
        for (int i = 0; i <= n; i++)
        {
            cout << "Введите " << i + 1 << "-ый элемент" << endl;
            cin >> array[i];
        }
        break;
    }

    cout << "Массив: [";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
        if (array[i] < min)
        {
            min = array[i];
            minIndex = i;
        }
        if (array[i] < 0)
        {
            lastIndex = i;
        }
    }
    cout << "]" << endl;

    if (minIndex >= lastIndex || !minIndex || !lastIndex)
    {
        cout << "Невозможно высчитать сумму. Попробуйте другой массив" << endl;
    }
    else
    {
        for (int i = minIndex; i <= lastIndex; i++)
        {
            res += fabs(array[i]);
        }
        cout << "Сумма модулей:" << res << "\nМинимальный элемент:" << array[minIndex] << "\nПоследний отрицательный элемент:" << array[lastIndex] << endl;
    }

    system("pause");
    return 0;
}