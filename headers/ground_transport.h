#ifndef GROUND_TRANSPORT_H
#define GROUND_TRANSPORT_H

#include "transport.h"
#include <iostream>

class Boots : public Transport {
public:
    const char* getName() const override {
        return "Ботинки-вездеходы";
    }

    TransportType getType() const override {
        return TransportType::Ground;
    }

    double calcTimeRide(int distance) const override {
        int speed = 6;
        int firstRestTime = 10;
        int subsequentRestTime = 5;
        int travelTime = distance / speed;
        int rests = (travelTime - 1) / 60;
        if (rests < 0) rests = 0;
        int totalRestTime = rests > 0 ? firstRestTime + (rests - 1) * subsequentRestTime : 0;
        return travelTime + totalRestTime;
    }
};

class Camel : public Transport {
public:
    const char* getName() const override {
        return "Верблюд";
    }

    TransportType getType() const override {
        return TransportType::Ground;
    }

    double calcTimeRide(int distance) const override {
        int speed = 10;
        int firstRestTime = 5;
        int subsequentRestTime = 8;
        int travelTime = distance / speed;
        int rests = (travelTime - 1) / 30;
        int totalRestTime = rests > 0 ? firstRestTime + (rests - 1) * subsequentRestTime : 0;
        return travelTime + totalRestTime;
    }
};

class Centaur : public Transport {
public:
    const char* getName() const override {
        return "Кентавр";
    }

    TransportType getType() const override {
        return TransportType::Ground;
    }

    double calcTimeRide(int distance) const override {
        int speed = 15;
        int restTime = 2;
        int travelTime = distance / speed;
        int rests = travelTime / 8;
        int totalRestTime = rests * restTime;
        return travelTime + totalRestTime;
    }
};

class FastCamel : public Transport {
public:
    const char* getName() const override {
        return "Верблюд-быстроход";
    }

    TransportType getType() const override {
        return TransportType::Ground;
    }

    double calcTimeRide(int distance) const override {
        int speed = 40;
        int travelTime = distance / speed;
        int firstRestTime = 5;
        int secondRestTime = 6.5;
        int subsequentRestTime = 8;
        int rests = travelTime / 10;

        if (rests == 0) rests = 1;

        int totalRestTime = firstRestTime + (rests > 1 ? secondRestTime : 0) + (rests - 2) * subsequentRestTime;
        return travelTime + totalRestTime;
    }
};

#endif // GROUND_TRANSPORT_H