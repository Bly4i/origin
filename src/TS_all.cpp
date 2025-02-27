#include "ts_all.h"
#include <iostream>
#include <cstdlib>

void TS_all::tsair() {
    do {
        cout << "Введите расстояние для гонки: ";
        cin >> distance;

        cout << "Гонка для всех транспортов. Расстояние: " << distance << endl;
        registeredTransportCount = 0;

        while (true) {
            cout << "Зарегистрируйте транспорт \n"
                << "1. Ботинки-вездеходы\n"
                << "2. Верблюд\n"
                << "3. Кентавр\n"
                << "4. Верблюд-быстроход\n"
                << "5. Ковёр-самолёт\n"
                << "6. Орёл\n"
                << "7. Метла\n"
                << "8. Вывести результаты гонки\n"
                << "9.Вывести список зарегистрированных ТС.\n"
                << "0. для выхода: " << endl;
            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                if (registeredTransportCount < MAX_TRANSPORTS) {
                    transports[registeredTransportCount] = new Boots();
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
                    transports[registeredTransportCount] = new Camel();
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
                    transports[registeredTransportCount] = new Centaur();
                    totalTime[registeredTransportCount] = transports[registeredTransportCount]->calcTimeRide(distance);
                    transportNames[registeredTransportCount] = transports[registeredTransportCount]->getName();
                    registeredTransportCount++;
                }
            case 4:
                if (registeredTransportCount < MAX_TRANSPORTS) {
                    transports[registeredTransportCount] = new FastCamel();
                    totalTime[registeredTransportCount] = transports[registeredTransportCount]->calcTimeRide(distance);
                    transportNames[registeredTransportCount] = transports[registeredTransportCount]->getName();
                    registeredTransportCount++;
                }
            case 5:
                if (registeredTransportCount < MAX_TRANSPORTS) {
                    transports[registeredTransportCount] = new CarpetPlane();
                    totalTime[registeredTransportCount] = transports[registeredTransportCount]->calcTimeRide(distance);
                    transportNames[registeredTransportCount] = transports[registeredTransportCount]->getName();
                    registeredTransportCount++;
                }
            case 6:
                if (registeredTransportCount < MAX_TRANSPORTS) {
                    transports[registeredTransportCount] = new Eagle();
                    totalTime[registeredTransportCount] = transports[registeredTransportCount]->calcTimeRide(distance);
                    transportNames[registeredTransportCount] = transports[registeredTransportCount]->getName();
                    registeredTransportCount++;
                }
            case 7:
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

            case 8:
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

            case 9:
                displayRegisteredTransports();
                break;

            case 0:
                exit(0);

            default:
                cout << "Неверный ввод. Пожалуйста, введите номер транспортного средства." << endl;
                break;
            }

            if (choice == 8 && registeredTransportCount >= 2) {
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

void TS_all::sortResults() {
    for (int i = 0; i < registeredTransportCount - 1; i++) {
        for (int j = 0; j < registeredTransportCount - i - 1; j++) {
            if (totalTime[j] > totalTime[j + 1]) {
                swap(totalTime[j], totalTime[j + 1]);
                swap(transportNames[j], transportNames[j + 1]);
            }
        }
    }
}

void TS_all::displayRegisteredTransports() {
    cout << "Зарегистрированные транспортные средства:\\n";
    for (int i = 0; i < registeredTransportCount; i++) {
        cout << i + 1 << ". " << transportNames[i] << endl;
    }
}