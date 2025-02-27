#include "ts_air.h"
#include <iostream>
#include <cstdlib>

void TS_air::tsair() {
    do {
       cout << "������� ���������� ��� �����: ";
        cin >> distance;

        cout << "����� ��� ���������� ����������. ����������: " << distance << endl;
        registeredTransportCount = 0;

        while (true) {
            cout << "��������������� ���������\n"
                << "1. ����-������\n"
                << "2. ���\n"
                << "3. �����\n"
                << "4. ������� ���������� �����\n"
                << "5. ������� ������ ������������������ ��.\n"
                << "0. ��� ������: " << endl;

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
                   cout << "���������� ������������ ���������� ������������������ ��." << endl;
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
                    cout << "���������� ������������ ���������� ������������������ ��." << endl;
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
    cout << "������������������ ������������ ��������:\\n";
    for (int i = 0; i < registeredTransportCount; i++) {
        cout << i + 1 << ". " << transportNames[i] << endl;
    }
}