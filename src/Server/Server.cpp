#ifdef SERVERBUILD
#include "Server.h"

#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>
using namespace std;

// Constructor for server
Server::Server() {
    socketInstanceName = "Server";
    fromSocketName = "Client";
}

// Configure the server socket. This includes binding the socket and listening for incoming connections.
int Server::Configure() {
    // bind the socket to a port and address (service)
    if (bind(mainSocket, (sockaddr*)&service, sizeof(service)) == -1) {
        BindException bindError(errno);
        throw bindError;
    } else {
        cout << "Server socket is now bound to an address and port" << endl;
    }
    // listen for incoming connections
    if (listen(mainSocket, 1) == -1) {
        ListenException listenError(errno);
        throw listenError;
    } else {
        cout << "Server is now listening for incoming "
                "connections"
             << endl;
    }
    return 0;
}

// Accept an incoming connection (Client)
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
            // if receivedResponse is 1 it means the client quit. 
            break;
        }
        SendMessage(socketInstanceName, acceptSocket);
    }
    close(mainSocket);
    return 0;
}
#endif
