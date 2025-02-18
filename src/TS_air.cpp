#include "TS_air.h"
#include<iostream>
#include <cstdlib>

void TS_air::tsair()
{
    do {
        distancelength();
        cout << "����� ��� ���������� ����������. ����������: " << value << endl;
        registeredTransportCount = 0;

        while (true) {
            cout << "��������������� ���������\n1. ����-������\n2. ���\n3. �����\n4. ������� ���������� �����\n5. ������� ������ ������������������ ��.\n0. ��� ������: " << endl; 
            cin >> choice;

            switch (choice) {
            case 1:
                if (registeredTransportCount < 3) {
                    totalTime[registeredTransportCount] = registerCarpetPlane();
                    transportNames[registeredTransportCount] = "����-������";
                    registeredTransportCount++;
                }
                else {
                    cout << "���������� ������������ ���������� ������������������ ��." << endl;
                }
                break;
            case 2:
                if (registeredTransportCount < 3) {
                    totalTime[registeredTransportCount] = registerEagle();
                    transportNames[registeredTransportCount] = "���";
                    registeredTransportCount++;
                }
                else {
                    cout << "���������� ������������ ���������� ������������������ ��." << endl;
                }
                break;
            case 3:
                if (registeredTransportCount < 3) {
                    totalTime[registeredTransportCount] = registerBroom();
                    transportNames[registeredTransportCount] = "�����";
                    registeredTransportCount++;
                }
                else {
                    cout << "���������� ������������ ���������� ������������������ ��." << endl;
                }
                break;
            case 4:
                if (registeredTransportCount < 2) {
                    cout << "���������� ���������������� ��� ������� 2 ������������ �������� ��� ������ �����������." << endl;
                }
                else {
                    cout << "���������� �����:\n";
                    sortResults();
                    for (int i = 0; i < registeredTransportCount; i++) {
                        cout << i + 1 << ". " << transportNames[i] << ": " << totalTime[i] << " �����." << endl;
                    }
                    break;
                }
                break;
            case 5:
                displayRegisteredTransports();
                break;
            case 0:
                exit(0);
            default:
                cout << "�������� ����. ����������, ������� ����� ������������� ��������." << endl;
                break;
            }
            if (choice == 4 && registeredTransportCount >= 2) {
                break;
            }
        }

        cout << "������ �������� ��� ���� �����? 1 - ��, 0 - �����: ";
        cin >> choice;
        if (choice == 0) {
            exit(0); 
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


void TS_air::displayRegisteredTransports() {
    if (registeredTransportCount == 0) {
        cout << "��� ������������������ ������������ �������." << endl;
        return;
    }

    cout << "������������������ ������������ ��������:" << endl;
    for (int i = 0; i < registeredTransportCount; i++) {
        cout << i + 1 << ". " << transportNames[i] << endl;
    }
}