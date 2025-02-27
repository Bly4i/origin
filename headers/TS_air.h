
#ifndef TS_AIR_H
#define TS_AIR_H

#include "air_transport.h"
#include <iostream>
#include <cstring>

class TS_air {
private:
    static const int MAX_TRANSPORTS = 3;
    Transport* transports[MAX_TRANSPORTS];
    double totalTime[MAX_TRANSPORTS];
    const char* transportNames[MAX_TRANSPORTS];
    int registeredTransportCount;
    int distance;

    void sortResults();
    void displayRegisteredTransports();

public:
    TS_air() : registeredTransportCount(0), distance(0) {}

    void tsair();
};

#endif // TS_AIR_H
