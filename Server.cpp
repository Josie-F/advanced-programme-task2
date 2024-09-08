#include "Server.h"

#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>
using namespace std;

Server::Server() {
    socketInstanceName = "Server";
    fromSocketName = "Client";
}

int Server::Configure() {
    if (bind(mainSocket, (sockaddr*)&service, sizeof(service)) == -1) {
        BindException bindError(errno);
        throw bindError;
    } else {
        cout << "bind() is valid!" << endl;
    }
    if (listen(mainSocket, 1) == -1) {
        ListenException listenError(errno);
        throw listenError;
    } else {
        cout << "listen() worked. Server is waiting for incoming "
                "connections..."
             << endl;
    }
    return 0;
}

int Server::Accept() {
    acceptSocket = accept(mainSocket, NULL, NULL);
    if (acceptSocket == -1) {
        AcceptException acceptError(errno);
        throw acceptError;
    }
    cout << "A client has connected!" << endl;
    while (1) {
        int receivedResponse = ReceiveMessage(fromSocketName, acceptSocket);
        if (receivedResponse == 1) {
            break;
        }
        SendMessage(socketInstanceName, acceptSocket);
    }
    close(mainSocket);
    return 0;
}
