#pragma once

#include "DistanceLength.h"
#include <string>
class TS_air : virtual public DistanceLength
{
public:
    int choice = 0;
    int registeredTransportCount = 0;
    int totalTime[3];
    string transportNames[3];

    void tsair();
    void sortResults();
    int registerCarpetPlane();
    int registerEagle();
    int registerBroom();
    void displayRegisteredTransports();
};