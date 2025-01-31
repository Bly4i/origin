#include "TS_air.h"
#include<iostream>

void TS_air::tsair()
{
    do {
        distancelength();
        cout << "Гонка для воздушного транспорта. Расстояние: " << value << endl;
        registeredTransportCount = 0;
        while (true) {
            cout << "Зарегистрируйте транспорт\n1. Ковёр-самолёт\n2. Орёл\n3. Метла\n4. Вывести результаты гонки\n0. для выхода: " << endl;
            cin >> choice;
            switch (choice) {
            case 1:
                totalTime[registeredTransportCount] = registerCarpetPlane();
                transportNames[registeredTransportCount] = "Ковёр-самолёт";
                registeredTransportCount++;
                break;
            case 2:
                totalTime[registeredTransportCount] = registerEagle();
                transportNames[registeredTransportCount] = "Орёл";
                registeredTransportCount++;
                break;
            case 3:
                totalTime[registeredTransportCount] = registerBroom();
                transportNames[registeredTransportCount] = "Метла";
                registeredTransportCount++;
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
                    break;
                }
                break;
            case 0:
                return;
            default:
                cout << "Неверный ввод. Пожалуйста, введите номер транспортного средства." << endl;
                break;
            }
            if (choice == 4 && registeredTransportCount >= 2) {
                break;
            }
        }

        cout << "Хотите провести еще одну гонку? 1 - Да, 0 - Выйти: ";
        cin >> choice;
        if (choice != 1) {
            break;
        }
    } while (true);
}
void TS_air::sortResults()
{
    for (int i = 0; i < registeredTransportCount - 1; i++) {
        for (int j = 0; j < registeredTransportCount - i - 1; j++) {
            if (totalTime[j] > totalTime[j + 1]) {
                swap(totalTime[j], totalTime[j + 1]);
                swap(transportNames[j], transportNames[j + 1]);
            }
        }
    }
}

double  adjustCarpetDistance(double distance) {
    if (distance < 1000) return distance;
    if (distance < 5000) return distance * 0.97;
    if (distance < 10000) return distance * 0.90;
    return distance * 0.95;
}

int TS_air::registerCarpetPlane() {
    double adjustedDistance = adjustCarpetDistance(value);
    return static_cast<int>(adjustedDistance / 10);
}

int TS_air::registerEagle() {
    double adjustedDistance = value * 0.94;
    return static_cast<int>(adjustedDistance / 8);
}

int TS_air::registerBroom() {
    double reductionFactor = 1 - (value / 1000) * 0.01;
    double adjustedDistance = value * reductionFactor;
    return static_cast<int>(adjustedDistance / 20);
}