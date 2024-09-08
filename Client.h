#include <iostream>

#include "Comms.h"
#include "Exceptions.h"

#pragma once
using namespace std;
struct Client : public Comms {
public:
    Client();
    ~Client() {};
    int Connect();
};