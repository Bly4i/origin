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

    virtual const char* getName() const = 0; // Название транспорта
    virtual TransportType getType() const = 0; // Тип транспорта
    virtual double calcTimeRide(int distance) const = 0; // Расчёт времени по дистанции
};

#endif // TRANSPORT_H