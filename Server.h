#include <iostream>

#include "Comms.h"

#pragma once
using namespace std;
class Server : public Comms {
public:
    Server() {
        socketInstanceName = "Server";
        fromSocketName = "Client";
    };
    int RunSocket();
};
