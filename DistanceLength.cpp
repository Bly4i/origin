#include "DistanceLength.h"

void DistanceLength::distancelength()
{
    cout << "������� ����� ��������� (������ ���� ������������): ";
    cin >> value;
    if (value <= 0) {
        cout << "�������� ����" << endl;
        value = 0;
    }
}