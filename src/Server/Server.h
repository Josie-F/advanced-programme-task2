#ifdef SERVERBUILD
#include <iostream>

#include "../Comms/Comms.h"
#include "../Exceptions.h"

#pragma once
using namespace std;
class Server : public Comms {
public:
    Server();
    ~Server(){};
    int Configure();
    int Accept();
};
#endif