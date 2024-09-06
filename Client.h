#include <iostream>

#include "Comms.h"

#pragma once
using namespace std;
struct Client : public Comms {
public:
    Client();
    ~Client(){};
    int Connect();
};