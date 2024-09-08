#include "Client.h"

#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>
using namespace std;

Client::Client() {
    socketInstanceName = "Client";
    fromSocketName = "Server";
}
int Client::Connect() {
    // call parent runsocket
    const char* socketName = "Client";
    if (connect(mainSocket, (sockaddr*)&service, sizeof(service)) == -1) {
        ConnectException connectError(errno);
        throw connectError;
    } else {
        cout << "connect() worked." << endl;
        cout << socketName << " is ready to send and receive data..." << endl;
    }
    while (1) {
        int sendResponse = SendMessage(socketInstanceName, mainSocket);
        if (sendResponse == 1) {
            break;
        }
        ReceiveMessage(fromSocketName, mainSocket);
    }
    close(mainSocket);
    return 0;
}
