#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

double result(int funNumber)
{
    double a, b, z, x, fx, res;
    double z1, z2;
    cout << "\n a, b, z = ";

    if (!((cin >> a) && (cin >> b) && (cin >> z)))
    {
        cout << "\nВведите числовые данные" << endl;
        return 0;
    }

    if (z <= 0)
    {
        x = pow(z, 2) / 2;
    }
    else
    {
        x = sqrt(z);
    };

    switch (funNumber)
    {
    case 1:
        fx = 2 * x;
        // cout << "\nВыбранная функция: f(x) = 2x" << endl;
        break;
    case 2:
        fx = pow(x, 2);
        // cout << "\nВыбранная функция: f(x) = x^2" << endl;
        break;
    case 3:
        fx = x / 3;
        // cout << "\nВыбранная функция: f(x) = x/3" << endl;
        break;
    }

    z1 = b * fx / cos(x);
    z2 = log(tan(x / 2));
    res = z1 + a * z2;

    return res;
}

int main()
{
    int funNumber;
    double res;

    cout << "\n1. f(x) = 2x\n2. f(x) = x^2\n3. f(x) = x/3\nВыберите функцию: ";
    if (!(cin >> funNumber) || funNumber > 3 || funNumber <= 0)
    {
        cout << "\nВведите действительный номер" << endl;
        return 0;
    }

    res = result(funNumber);
    cout << "Результат: " << res << endl;

    system("pause");
    return 0;
}