#include <netdb.h>
#pragma once
struct Comms {
public:
    int mainSocket;
    int acceptSocket;
    const char* fromSocketName;
    const char* socketInstanceName;
    sockaddr_in service;
    Comms() {};
    virtual int RunSocket();
    int ReceiveMessage(const char* fromSocketName, int fromSocket);
    int SendMessage(const char* socketInstanceName, int toSocket);
};
