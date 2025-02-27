#ifndef AIR_TRANSPORT_H
#define AIR_TRANSPORT_H

#include "transport.h"

class CarpetPlane : public Transport {
public:
    const char* getName() const override {
        return "Ковёр-самолёт";
    }

    TransportType getType() const override {
        return TransportType::Air;
    }

    double calcTimeRide(int distance) const override {
        if (distance < 1000) return distance / 10.0;
        if (distance < 5000) return (distance * 0.97) / 10.0;
        if (distance < 10000) return (distance * 0.90) / 10.0;
        return (distance * 0.95) / 10.0;
    }
};

class Eagle : public Transport {
public:
    const char* getName() const override {
        return "Орёл";
    }

    TransportType getType() const override {
        return TransportType::Air;
    }

    double calcTimeRide(int distance) const override {
        return (distance * 0.94) / 8.0;
    }
};

class Broom : public Transport {
public:
    const char* getName() const override {
        return "Метла";
    }

    TransportType getType() const override {
        return TransportType::Air;
    }

    double calcTimeRide(int distance) const override {
        double reductionFactor = 1 - (distance / 1000.0) * 0.01;
        return (distance * reductionFactor) / 20.0;
    }
};

#endif // AIR_TRANSPORT_H