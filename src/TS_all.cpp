#include "TS_all.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void TS_all::tsall()
{
    do {
        distancelength();
        cout << "����� ��� ���������� ����������. ����������: " << value << endl;
        registeredTransportCount = 0;
        while (true) {
            cout << "��������������� ��������� \n"
                << "1. �������-���������\n"
                << "2. �������\n"
                << "3. �������\n"
                << "4. �������-���������\n"
                << "5. ����-������\n"
                << "6. ���\n"
                << "7. �����\n"
                << "8. ������� ���������� �����\n"
                << "9.������� ������ ������������������ ��.\n"
                << "0. ��� ������: " << endl;
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
            case 4:
                totalTime[registeredTransportCount] = runFastCamel();
                transportNames[registeredTransportCount] = "�������-���������";
                registeredTransportCount++;
                break;
            case 5:
                totalTime[registeredTransportCount] = registerCarpetPlane();
                transportNames[registeredTransportCount] = "����-������";
                registeredTransportCount++;
                break;
            case 6:
                totalTime[registeredTransportCount] = registerEagle();
                transportNames[registeredTransportCount] = "���";
                registeredTransportCount++;
                break;
            case 7:
                totalTime[registeredTransportCount] = registerBroom();
                transportNames[registeredTransportCount] = "�����";
                registeredTransportCount++;
                break;
            case 9:
                displayRegisteredTransports();
                break;
            case 8:
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
            case 0:
                exit(0);
            default:
                cout << "�������� ����. ����������, ������� ����� ������������� ��������." << endl;
                break;
            }
            if (choice == 8 && registeredTransportCount >= 2) {
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
        cout << "��� ������������������ ������������ �������." << endl;
        return;
    }

    cout << "������������������ ������������ ��������:" << endl;
    for (int i = 0; i < registeredTransportCount; i++) {
        cout << i + 1 << ". " << transportNames[i] << endl;
    }
}