#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    double a, b, h, res;
    double Y, S;
    cout << "\n a, b, h, n = ";

    if (!((cin >> a) && (cin >> b) && (cin >> h) && (cin >> n)))
    {
        cout << "\nВведите числовые данные" << endl;
        return 0;
    };

    for (double x = a; x <= b; x += h)
    {
        Y = ((1 + pow(x, 2)) / 2) * atan(x) - x / 2;
        S = 0;

        for (int k = 1; k <= n; k++)
        {
            S += pow(-1, k + 1) * (pow(x, 2 * k + 1) / ((4 * pow(k, 2)) - 1));
        }

        cout << "Y(X) = " << Y << " | S(X) = " << S << " | |Y(X) - S(X)| = " << fabs(Y - S) << "\n";
    }
    system("pause");
    return 0;
}