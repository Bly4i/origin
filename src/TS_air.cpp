#include "ts_air.h"
#include <iostream>
#include <cstdlib>

void TS_air::tsair() {
    do {
       cout << "Введите расстояние для гонки: ";
        cin >> distance;

        cout << "Гонка для воздушного транспорта. Расстояние: " << distance << endl;
        registeredTransportCount = 0;

        while (true) {
            cout << "Зарегистрируйте транспорт\n"
                << "1. Ковёр-самолёт\n"
                << "2. Орёл\n"
                << "3. Метла\n"
                << "4. Вывести результаты гонки\n"
                << "5. Вывести список зарегистрированных ТС.\n"
                << "0. Для выхода: " << endl;

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                if (registeredTransportCount < MAX_TRANSPORTS) {
                    transports[registeredTransportCount] = new CarpetPlane();
                    totalTime[registeredTransportCount] = transports[registeredTransportCount]->calcTimeRide(distance);
                    transportNames[registeredTransportCount] = transports[registeredTransportCount]->getName();
                    registeredTransportCount++;
                }
                else {
                   cout << "Достигнуто максимальное количество зарегистрированных ТС." << endl;
                }
                break;

            case 2:
                if (registeredTransportCount < MAX_TRANSPORTS) {
                    transports[registeredTransportCount] = new Eagle();
                    totalTime[registeredTransportCount] = transports[registeredTransportCount]->calcTimeRide(distance);
                    transportNames[registeredTransportCount] = transports[registeredTransportCount]->getName();
                    registeredTransportCount++;
                }
                else {
                    cout << "Достигнуто максимальное количество зарегистрированных ТС." << endl;
                }
                break;

            case 3:
                if (registeredTransportCount < MAX_TRANSPORTS) {
                    transports[registeredTransportCount] = new Broom();
                    totalTime[registeredTransportCount] = transports[registeredTransportCount]->calcTimeRide(distance);
                    transportNames[registeredTransportCount] = transports[registeredTransportCount]->getName();
                    registeredTransportCount++;
                }
                else {
                    cout << "Достигнуто максимальное количество зарегистрированных ТС." << endl;
                }
                break;

            case 4:
                if (registeredTransportCount < 2) {
                    cout << "Необходимо зарегистрировать как минимум 2 транспортных средства для вывода результатов." << endl;
                }
                else {
                    cout << "Результаты гонки:\n";
                    sortResults();
                    for (int i = 0; i < registeredTransportCount; i++) {
                        cout << i + 1 << ". " << transportNames[i] << ": " << totalTime[i] << " часов." << endl;
                    }
                }
                break;

            case 5:
                displayRegisteredTransports();
                break;

            case 0:
                exit(0);

            default:
                cout << "Неверный ввод. Пожалуйста, введите номер транспортного средства." << endl;
                break;
            }

            if (choice == 4 && registeredTransportCount >= 2) {
                break;
            }
        }

        cout << "Хотите провести еще одну гонку? 1 - Да, 0 - Выйти: ";
        int choice;
        cin >> choice;
        if (choice == 0) {
            exit(0);
        }

    } while (true);
}

void TS_air::sortResults() {
    for (int i = 0; i < registeredTransportCount - 1; i++) {
        for (int j = 0; j < registeredTransportCount - i - 1; j++) {
            if (totalTime[j] > totalTime[j + 1]) {
               swap(totalTime[j], totalTime[j + 1]);
                swap(transportNames[j], transportNames[j + 1]);
            }
        }
    }
}

void TS_air::displayRegisteredTransports() {
    cout << "Зарегистрированные транспортные средства:\\n";
    for (int i = 0; i < registeredTransportCount; i++) {
        cout << i + 1 << ". " << transportNames[i] << endl;
    }
}