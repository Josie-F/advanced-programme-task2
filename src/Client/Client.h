#ifdef CLIENTBUILD
#include <iostream>

#include "../Comms/Comms.h"
#include "../Exceptions.h"

#pragma once
using namespace std;
struct Client : public Comms {
public:
    Client();
    ~Client() {};
    int Connect();
};
#endif