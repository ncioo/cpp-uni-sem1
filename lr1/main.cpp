#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    double x, y, z, res;
    double f1, f2, z1, z2, z3, z4, z5;
    cout << "\nx, y, z = ";

    if (!((cin >> x) && (cin >> y) && (cin >> z)))
    {
        cout << "\nВведите числовые данные" << endl;
        return 0;
    }

    f1 = y / x;
    f2 = y - x;

    z1 = fabs(pow(x, f1) - pow(f1, (1.0 / 3)));
    z2 = cos(y) - (z / f2);
    z3 = 1 + pow(f2, 2);
    z4 = z2 / z3;
    res = z1 + f2 * z4;

    cout
        << "\nx = " << x << "\ny = " << y << "\nz = " << z << "\nres = " << res << " | w = 1.2131" << endl;
    system("pause");
    return 0;
}