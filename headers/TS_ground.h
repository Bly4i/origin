
#ifndef TS_GROUND_H
#define TS_GROUND_H

#include "ground_transport.h"
#include <iostream>
#include <cstring>

class TS_ground {
private:
    static const int MAX_TRANSPORTS = 4;
    Transport* transports[MAX_TRANSPORTS];
    double totalTime[MAX_TRANSPORTS];
    const char* transportNames[MAX_TRANSPORTS];
    int registeredTransportCount;
    int distance;

    void sortResults();
    void displayRegisteredTransports();

public:
    TS_ground() : registeredTransportCount(0), distance(0) {}

    void tsair();
};

#endif // TS_GROUND_H