#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>

#include "Comms.h"

#pragma once
using namespace std;
class Server : public Comms {
public:
    Server() {};
    int RunSocket() {
        // no init or cleanup functions needed for MAC therefore not implemented.
        int serverSocket;  // socket returns an int on MAC
        int acceptSocket;
        sockaddr_in service;
        service.sin_family = AF_INET;
        inet_pton(AF_INET, ("127.0.0.1"), &service.sin_addr.s_addr);
        int port = 3001;

        serverSocket =
            -1;  // invalid socket from socket() will return negative i.e -1;
        serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // create the socket
        if (serverSocket < 0) { // is invalid?
            cout << "socket() failed. Error number: " << errno << endl;
            return 0;
        } else {
            cout << "socket() is valid!" << endl;
        }

        if (bind(serverSocket, (sockaddr*)&service, sizeof(service)) == -1) { // bind step
            cout << "bind() failed. Error: " << errno << endl;
            close(serverSocket);
            return 0;
        } else {
            cout << "bind() is valid!" << endl;
        }
        if (listen(serverSocket, 1) == -1) {
            cout << "listen(): Error listening on socket " << errno << endl;
        } else {
            cout << "listen() is valid, waiting for any incoming connections..." << endl;
        }

        // not yet tested. need client.
        acceptSocket = accept(serverSocket, NULL, NULL);
        if (acceptSocket == -1) {
            cout << "accept() has failed: " << errno << endl;
            return -1;
        }
        cout << "Accepted incoming connection" << endl;
        system("pause");
        return 0;
    }
};
// close(serverSocket);
