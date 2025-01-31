#include <iostream>
#include <string>
#include <Windows.h>
#include "DistanceLength.h"
#include "TS_ground.h"
#include "TS_air.h"
#include "TS_all.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice = 0;
    cout << "Добро пожаловать в гоночный симулятор!" << endl;
    cout << "1. Гонка для наземного транспорта " << endl;
    cout << "2. Гонка для воздушного транспорта " << endl;
    cout << "3. Гонка для всех транспортов  " << endl;
    while (true) {
        cin >> choice;
        switch (choice) {
        case 1: {
            TS_ground race;
            race.tsground();
            break;
        }
        case 2: {
            TS_air race;
            race.tsair();
            break;
            break;
        }
        case 3: {
            TS_all race;
            race.tsall();
            break;
            break;
        }
        case 0: {
            return 0;
            break;
        }
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
    }
    return 0;
}