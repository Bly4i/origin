#include "TS_ground.h"
#include <iostream>
using namespace std;

void TS_ground::tsground()
{
    do {
        distancelength();
        cout << "Гонка для наземного транспорта. Расстояние: " << value << endl;
        registeredTransportCount = 0;

        while (true) {
            cout << "Зарегистрируйте транспорт\n1. Ботинки-вездеходы\n2. Верблюд\n3. Кентавр\n4. Верблюд-быстроход\n5. Вывести результаты гонки\n0. для выхода: " << endl;
            cin >> choice;

            switch (choice) {
            case 1:
                totalTime[registeredTransportCount] = runBoots();
                transportNames[registeredTransportCount] = "Ботинки-вездеходы";
                registeredTransportCount++;
                break;
            case 2:
                totalTime[registeredTransportCount] = runCamel();
                transportNames[registeredTransportCount] = "Верблюд";
                registeredTransportCount++;
                break;
            case 3:
                totalTime[registeredTransportCount] = runCentaur();
                transportNames[registeredTransportCount] = "Кентавр";
                registeredTransportCount++;
                break;
            case 4: {
                totalTime[registeredTransportCount] = runFastCamel();
                transportNames[registeredTransportCount] = "Верблюд-быстроход";
                registeredTransportCount++;
                break;
            }
            case 5:
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
            case 0:
                return;
            default:
                cout << "Неверный ввод. Пожалуйста, введите номер транспортного средства." << endl;
                break;
            }

            if (choice == 5 && registeredTransportCount >= 2) {
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

void TS_ground::sortResults()
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

int TS_ground::runBoots()
{
    int speed = 6;
    int firstRestTime = 10;
    int subsequentRestTime = 5;
    int travelTime = value / speed;
    cout << "Ботинки-вездеходы: зарегистрирован\\n\\n";
    int rests = (travelTime - 1) / 60;
    if (rests < 0) rests = 0;
    int totalRestTime = rests > 0 ? firstRestTime + (rests - 1) * subsequentRestTime : 0;
    int totalTime = travelTime + totalRestTime;
    return totalTime;
}
int TS_ground::runCamel() {
    int speed = 10;
    int firstRestTime = 5;
    int subsequentRestTime = 8;
    int travelTime = value / speed;
    cout << "Верблюд:зарегистрирован\n\n";
    int rests = (travelTime - 1) / 30;
    int totalRestTime = rests > 0 ? firstRestTime + (rests - 1) * subsequentRestTime : 0;
    int totalTime = travelTime + totalRestTime;
    return totalTime;
}
int TS_ground::runCentaur()
{
    int speed = 15;
    int restTime = 2;
    int travelTime = value / speed;
    int rests = travelTime / 8;
    int totalRestTime = rests * restTime;
    int totalTime = travelTime + totalRestTime;
    cout << "Кентавр:зарегистрирован\n\n";
    return totalTime;
}
int TS_ground::runFastCamel()
{
    int speed = 40;
    int travelTime = value / speed;
    int firstRestTime = 5;
    int secondRestTime = 6.5;
    int subsequentRestTime = 8;
    cout << "Верблюд-быстроход:зарегистрирован\n\n";
    int rests = travelTime / 10;

    if (rests == 0) rests = 1;

    int totalRestTime = firstRestTime + (rests > 1 ? secondRestTime : 0) + (rests - 2) * subsequentRestTime;
    int totalTime = travelTime + totalRestTime;
    return totalTime;
}