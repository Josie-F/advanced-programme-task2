#include "Server.h"

#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>
using namespace std;

int Server::RunSocket() {
    // call parent function 
    Comms::RunSocket();

    if (bind(mainSocket, (sockaddr*)&service, sizeof(service)) ==
        -1) {  // bind step
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

    acceptSocket = accept(mainSocket, NULL, NULL);
    if (acceptSocket == -1) {
        cout << "accept() failed. Error number: " << errno << endl;
        return -1;
    }
    cout << "Accepted incoming connection" << endl;
    while (1) {
        ReceiveMessage(fromSocketName, acceptSocket);
        SendMessage(socketInstanceName, acceptSocket);
    }
    return 0;
}
