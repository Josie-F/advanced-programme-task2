#include <iostream>

#include "Comms.h"

#pragma once
using namespace std;
class Server : public Comms {
public:
    Server();
    ~Server(){};
    int Configure();
    int Accept();
};
