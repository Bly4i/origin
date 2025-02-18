#pragma once

#include "TS_air.h"
#include"TS_ground.h"
#include <string>

class TS_all : public TS_air, TS_ground
{
public:
    int choice = 0;
    int registeredTransportCount = 0;
    int totalTime[7];
    string transportNames[7];

    void tsall();
    void sortResults();
    void displayRegisteredTransports();
};