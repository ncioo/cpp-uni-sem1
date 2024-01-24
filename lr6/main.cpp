#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string oldString = "4 5 7 1 20 9 33 41 2 6",
           newString;
    int numbers[10];

    cout << "Ваша строка: " << oldString << endl;

    int temp = 0, place = 0;

    for (int i = 0; i < oldString.length() + 1; i++)
    {
        if (oldString[i] != ' ')
        {
            int num;
            stringstream ss;
            ss << oldString[i];
            ss >> num;
            temp = temp * 10 + num;

            if (i == oldString.length() - 1)
            {
                numbers[place] = temp;
                place++;
                temp = 0;
            }
        }
        else
        {
            numbers[place] = temp;
            place++;
            temp = 0;
        }
    }

    sort(begin(numbers), end(numbers));

    for (int i = 0; i < place; i++)
    {
        string str;
        stringstream ss;
        ss << numbers[i];
        ss >> str;
        newString += str += " ";
    }

    cout << "Ваша новая строка: " << newString << endl;

    system("pause");
    return 0;
}