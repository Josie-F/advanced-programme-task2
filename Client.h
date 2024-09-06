#include <iostream>

#include "Comms.h"

#pragma once
using namespace std;
struct Client : public Comms {
public:
    Client() {
        socketInstanceName = "Client";
        fromSocketName = "Server";
    };
    int RunSocket();
};