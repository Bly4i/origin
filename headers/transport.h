#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>
using namespace std;

enum class TransportType {
    Ground,
    Air
};

class Transport {
public:
    virtual ~Transport() = default;

    virtual const char* getName() const = 0; // �������� ����������
    virtual TransportType getType() const = 0; // ��� ����������
    virtual double calcTimeRide(int distance) const = 0; // ������ ������� �� ���������
};

#endif // TRANSPORT_H