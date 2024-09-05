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
    int serverSocket; // socket returns an int on MAC
    int acceptSocket;
    int RunSocket() {
        // no init or cleanup functions needed for MAC therefore not
        // implemented.
        sockaddr_in service;
        service.sin_family = AF_INET;
        int port = 3001;
        service.sin_port = htons(port);
        inet_pton(AF_INET, ("127.0.0.1"), &service.sin_addr.s_addr);

        serverSocket =
            -1;  // invalid socket from socket() will return negative i.e -1;
        serverSocket =
            socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  // create the socket
        if (serverSocket < 0) {                         // is invalid?
            cout << "socket() failed. Error number: " << errno << endl;
            return 0;
        } else {
            cout << "socket() worked!" << endl;
        }

        if (bind(serverSocket, (sockaddr*)&service, sizeof(service)) ==
            -1) {  // bind step
            cout << "bind() failed. Error number: " << errno << endl;
            close(serverSocket);
            return 0;
        } else {
            cout << "bind() is valid!" << endl;
        }
        if (listen(serverSocket, 1) == -1) {
            cout << "listen() failed. Error listening on socket. Error number: "
                 << errno << endl;
        } else {
            cout << "listen() worked. Server is waiting for incoming "
                    "connections..."
                 << endl;
        }

        acceptSocket = accept(serverSocket, NULL, NULL);
        if (acceptSocket == -1) {
            cout << "accept() failed. Error number: " << errno << endl;
            return -1;
        }
        cout << "Accepted incoming connection" << endl;
        while (1) {
            receiveMessage();
            sendMessage();
        }
        return 0;
    }
    int sendMessage() {
        time_t rawtime;
        tm* utcTime;
        time(&rawtime);
        utcTime = gmtime(&rawtime);
        char message[200];
        cout << "Enter your message" << endl;
        cin.getline(message, 200);
        int byteCount = send(acceptSocket, message, 200, 0);
        if (byteCount == -1) {
            cout << "Server error on send: " << errno << endl;
            return -1;
        } else {
            cout << "Message sent at: " << utcTime->tm_hour + 1 << ":"
                 << utcTime->tm_min << ":" << utcTime->tm_sec
                 << endl;  // +1 BST (British Summer Time)
        }
    }
    int receiveMessage() {
        time_t rawtime;
        tm* utcTime;
        time(&rawtime);
        utcTime = gmtime(&rawtime);
        char receiveMessage[200] = "";
        int byteCount = recv(acceptSocket, receiveMessage, 200, 0);
        if (byteCount < 0) {
            cout << "Server encountered an error: " << errno << endl;
            return 0;
        } else {
            cout << utcTime->tm_hour + 1 << ":" << utcTime->tm_min << ":"
                 << utcTime->tm_sec << " Client: " << receiveMessage << endl;
        }
    }
};
