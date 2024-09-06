#include "Client.h"

#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>
using namespace std;

int Client::RunSocket() {
    // call parent runsocket
    const char* socketName = "Client";
    Comms::RunSocket();
    if (connect(mainSocket, (sockaddr*)&service, sizeof(service)) == -1) {
        cout << "connect() - Failed to connect. Error number: " << errno
             << endl;
        return 0;
    } else {
        cout << "connect() worked." << endl;
        cout << socketName << " is ready to send and receive data..." << endl;
    }
    while (1) {
        SendMessage(socketInstanceName, mainSocket);
        ReceiveMessage(fromSocketName, mainSocket);
    }
    return 0;
}
