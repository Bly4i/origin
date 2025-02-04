#include "TS_ground.h"
#include <iostream>
using namespace std;

void TS_ground::tsground()
{
    do {
        distancelength();
        cout << "����� ��� ��������� ����������. ����������: " << value << endl;
        registeredTransportCount = 0;

        while (true) {
            cout << "��������������� ���������\n1. �������-���������\n2. �������\n3. �������\n4. �������-���������\n5. ������� ���������� �����\n0. ��� ������: " << endl;
            cin >> choice;

            switch (choice) {
            case 1:
                totalTime[registeredTransportCount] = runBoots();
                transportNames[registeredTransportCount] = "�������-���������";
                registeredTransportCount++;
                break;
            case 2:
                totalTime[registeredTransportCount] = runCamel();
                transportNames[registeredTransportCount] = "�������";
                registeredTransportCount++;
                break;
            case 3:
                totalTime[registeredTransportCount] = runCentaur();
                transportNames[registeredTransportCount] = "�������";
                registeredTransportCount++;
                break;
            case 4: {
                totalTime[registeredTransportCount] = runFastCamel();
                transportNames[registeredTransportCount] = "�������-���������";
                registeredTransportCount++;
                break;
            }
            case 5:
                if (registeredTransportCount < 2) {
                    cout << "���������� ���������������� ��� ������� 2 ������������ �������� ��� ������ �����������." << endl;
                }
                else {
                    cout << "���������� �����:\n";
                    sortResults();
                    for (int i = 0; i < registeredTransportCount; i++) {
                        cout << i + 1 << ". " << transportNames[i] << ": " << totalTime[i] << " �����." << endl;
                    }
                }
                break;
            case 0:
                return;
            default:
                cout << "�������� ����. ����������, ������� ����� ������������� ��������." << endl;
                break;
            }

            if (choice == 5 && registeredTransportCount >= 2) {
                break;
            }
        }

        cout << "������ �������� ��� ���� �����? 1 - ��, 0 - �����: ";
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
    cout << "�������-���������: ���������������\\n\\n";
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
    cout << "�������:���������������\n\n";
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
    cout << "�������:���������������\n\n";
    return totalTime;
}
int TS_ground::runFastCamel()
{
    int speed = 40;
    int travelTime = value / speed;
    int firstRestTime = 5;
    int secondRestTime = 6.5;
    int subsequentRestTime = 8;
    cout << "�������-���������:���������������\n\n";
    int rests = travelTime / 10;

    if (rests == 0) rests = 1;

    int totalRestTime = firstRestTime + (rests > 1 ? secondRestTime : 0) + (rests - 2) * subsequentRestTime;
    int totalTime = travelTime + totalRestTime;
    return totalTime;
}