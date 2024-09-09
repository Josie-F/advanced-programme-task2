#ifdef CLIENTBUILD
#include "Client.h"

#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>
using namespace std;

// Client Constructor
Client::Client() {
    socketInstanceName = "Client";
    fromSocketName = "Server";
}

// Function to connect the client socket to server socket and send and receive messages.
int Client::Connect() {
    // connect the client socket to the server socket's address.
    if (connect(mainSocket, (sockaddr*)&service, sizeof(service)) == -1) {
        ConnectException connectError(errno);
        throw connectError;
    } else {
        cout << "Client connected to server." << endl;
        cout << socketInstanceName << " is ready to send and receive data from the server" << endl;
    }
    while (1) {
        int sendResponse = SendMessage(socketInstanceName, mainSocket);
        if (sendResponse == 1) {
            // if the client typed Quit, sendResponse will return 1 and we break and close the socket. 
            break;
        }
        ReceiveMessage(fromSocketName, mainSocket);
    }
    close(mainSocket);
    return 0;
}
#endif
