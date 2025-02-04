#include "DistanceLength.h"

void DistanceLength::distancelength()
{
    cout << "Укажите длину дистанции (должна быть положительна): ";
    cin >> value;
    if (value <= 0) {
        cout << "Неверный ввод" << endl;
        value = 0;
    }
}