#include <iostream>

#include "Comms.h"
#include "BindException.h"
#include "ListenException.h"
#include "AcceptException.h"

#pragma once
using namespace std;
class Server : public Comms {
public:
    Server();
    ~Server(){};
    int Configure();
    int Accept();
};
