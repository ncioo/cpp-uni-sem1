#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstdio>

using namespace std;

struct Student
{
    char name[30];
    int groupId;
    int phys;
    int math;
    int info;
    double avg;
};
double gAvg = 0;
int studSize = 0;

void createFile()
{
    FILE *file = fopen("data.txt", "w");
    if (file == NULL)
    {
        cout << "Что-то пошло не так" << endl;
        return;
    }
    cout << endl;
    cout << "Файл создан" << endl;
    fclose(file);
}
void readFile()
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        cout << "Что-то пошло не так" << endl;
        return;
    }
    Student data;
    while (true)
    {
        int n = fread(&data, sizeof(Student), 1, file);
        if (n != 1)
            break;

        cout << endl;
        cout << "Фамилия: " << data.name << " | Группа: " << data.groupId
             << "\nФизика: " << data.phys << " | Математика: " << data.math << " | Информатика: " << data.info
             << "\nСредний балл: " << data.avg << endl;
    }
    fclose(file);
}
void addStud()
{
    FILE *file = fopen("data.txt", "a");
    if (file == NULL)
    {
        cout << "Что-то пошло не так" << endl;
        return;
    }
    Student data;

    cout << endl;
    cout << "Фамилия: " << endl;
    cin >> data.name;
    cout << "Группа: " << endl;
    cin >> data.groupId;
    cout << "Оценка по физике: " << endl;
    cin >> data.phys;
    cout << "Оценка по математике: " << endl;
    cin >> data.math;
    cout << "Оценка по информатике: " << endl;
    cin >> data.info;

    data.avg = round(((data.phys + data.math + data.info) / 3.0) * 100) / 100;
    gAvg += data.avg;
    studSize++;

    fwrite(&data, sizeof(Student), 1, file);
    fclose(file);
}
void task()
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        cout << "Что-то пошло не так" << endl;
        return;
    }
    FILE *out = fopen("out.txt", "a");
    if (out == NULL)
    {
        cout << "Что-то пошло не так" << endl;
        return;
    }
    Student data;

    double curAvg = gAvg / studSize;
    int groupId;

    cout << endl;
    cout << "Общий средний балл: " << curAvg << "\nВведите номер интересующей группы: " << endl;
    cin >> groupId;

    while (true)
    {
        int n = fread(&data, sizeof(Student), 1, file);
        if (n != 1)
            break;

        if (data.avg > curAvg && data.groupId == groupId)
        {
            cout << endl;
            cout << "Фамилия: " << data.name << " | Группа: " << data.groupId
                 << "\nФизика: " << data.phys << " | Математика: " << data.math << " | Информатика: " << data.info
                 << "\nСредний балл: " << data.avg << endl;
            fwrite(&data, sizeof(Student), 1, out);
        }
    }
    fclose(out);
    fclose(file);
}
int main()
{
    int action;
    while (true)
    {
        cout << endl;
        cout << "Выберите действие:"
             << "\n1. Создание файла"
             << "\n2. Просмотр файла"
             << "\n3. Добавление студентов"
             << "\n4. Запуск задания"
             << "\n0. Выход"
             << endl;

        cin >> action;
        switch (action)
        {
        case (1):
            createFile();
            break;
        case (2):
            readFile();
            break;
        case (3):
            addStud();
            break;
        case (4):
            task();
            break;
        default:
            return 0;
        }
    }

    system("pause");
    return 0;
}