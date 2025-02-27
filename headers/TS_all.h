
#ifndef TS_ALL_H
#define TS_ALL_H

#include "all_transport.h"
#include <iostream>
#include <cstring>

class TS_all {
private:
    static const int MAX_TRANSPORTS = 7;
    Transport* transports[MAX_TRANSPORTS];
    double totalTime[MAX_TRANSPORTS];
    const char* transportNames[MAX_TRANSPORTS];
    int registeredTransportCount;
    int distance;

    void sortResults();
    void displayRegisteredTransports();

public:
    TS_all() : registeredTransportCount(0), distance(0) {}

    void tsair();
};

#endif // TS_all_H