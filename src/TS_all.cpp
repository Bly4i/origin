#include "TS_all.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void TS_all::tsall()
{
    do {
        distancelength();
        cout << "Гонка для воздушного транспорта. Расстояние: " << value << endl;
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
            case 4:
                totalTime[registeredTransportCount] = runFastCamel();
                transportNames[registeredTransportCount] = "Верблюд-быстроход";
                registeredTransportCount++;
                break;
            case 5:
                totalTime[registeredTransportCount] = registerCarpetPlane();
                transportNames[registeredTransportCount] = "Ковёр-самолёт";
                registeredTransportCount++;
                break;
            case 6:
                totalTime[registeredTransportCount] = registerEagle();
                transportNames[registeredTransportCount] = "Орёл";
                registeredTransportCount++;
                break;
            case 7:
                totalTime[registeredTransportCount] = registerBroom();
                transportNames[registeredTransportCount] = "Метла";
                registeredTransportCount++;
                break;
            case 9:
                displayRegisteredTransports();
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
                    break;
                }
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
        cin >> choice;
        if (choice == 0) {
            exit(0);
        }
    } while (true);
}
void TS_all::sortResults()
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
void TS_all::displayRegisteredTransports() {
    if (registeredTransportCount == 0) {
        cout << "Нет зарегистрированных транспортных средств." << endl;
        return;
    }

    cout << "Зарегистрированные транспортные средства:" << endl;
    for (int i = 0; i < registeredTransportCount; i++) {
        cout << i + 1 << ". " << transportNames[i] << endl;
    }
}