#include <netdb.h>

#include "time.h"
#include "SocketException.h"
#include "SendException.h"
#include "ReceiveException.h"

#pragma once
class Comms {
private:
    int port;
    tm* currentTime;

protected:  // only available to child classes
    int mainSocket;
    int acceptSocket;
    const char* fromSocketName;
    const char* socketInstanceName;
    sockaddr_in service;

public:
    Comms() {};
    int SetupSocket();
    int ReceiveMessage(const char* fromSocketName, int fromSocket);
    int SendMessage(const char* socketInstanceName, int toSocket);
    void SetCurrentTime();
};
