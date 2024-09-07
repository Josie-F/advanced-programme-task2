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
        cout << "bind() failed. Error number: " << errno << endl;
        close(mainSocket);
        return 0;
    } else {
        cout << "bind() is valid!" << endl;
    }
    if (listen(mainSocket, 1) == -1) {
        cout << "listen() failed. Error listening on socket. Error number: "
             << errno << endl;
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
        cout << "accept() failed. Error number: " << errno << endl;
        return -1;
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
