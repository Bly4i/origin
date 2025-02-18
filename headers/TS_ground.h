#pragma once

#include "DistanceLength.h"
#include <string>

class TS_ground : virtual public DistanceLength {
public:
    int choice = 0;
    int registeredTransportCount = 0;
    int totalTime[4];
    string transportNames[4];

    void tsground();
    void sortResults();
    int runBoots();
    int runCamel();
    int runCentaur();
    int runFastCamel();
    void displayRegisteredTransports();
};