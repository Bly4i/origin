#include <iostream>
#include <string>
#include <Windows.h>
#include "ts_air.h"
#include"ts_ground.h"
#include"ts_all.h"
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
            TS_ground groundRace;
            groundRace.tsair();
            break;
        }
        case 2: {
            TS_air airRace;
            airRace.tsair();
            break;
        }
        case 3: {
            TS_all allRace;
            allRace.tsair();
            break;
        }
        case 0: {
            exit(0);
            break;
        }
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
    }
    return 0;
}