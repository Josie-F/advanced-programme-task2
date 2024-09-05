#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>

#include "Comms.h"

#pragma once
using namespace std;
struct Client : public Comms {
    Client() {};
    int clientSocket;
    int acceptSocket;
    int RunSocket() {
        // no init or cleanup functions needed for MAC therefore not
        // implemented.
        sockaddr_in service;
        service.sin_family = AF_INET;
        inet_pton(AF_INET, ("127.0.0.1"), &service.sin_addr.s_addr);
        int port = 3001;
        service.sin_port = htons(port);

        clientSocket =
            -1;  // invalid socket from socket() will return negative i.e -1;
        clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (clientSocket < 0) {
            cout << "Error at socket(). Error number: " << errno << endl;
            return 0;
        } else {
            cout << "socket() worked" << endl;
        }

        if (connect(clientSocket, (sockaddr*)&service, sizeof(service)) == -1) {
            cout << "connect() - Failed to connect. Error number: " << errno
                 << endl;
            return 0;
        } else {
            cout << "connect() worked." << endl;
            cout << "Client is ready to send and receive data..." << endl;
        }
        while (1) {
            sendMessage();
            receiveMessage();
        }
        return 0;
    }
    int receiveMessage() {
        time_t rawtime;
        tm* utcTime;
        time(&rawtime);
        utcTime = gmtime(&rawtime);
        char receiveMessage[200] = "";
        int byteCount = recv(clientSocket, receiveMessage, 200, 0);
        if (byteCount < 0) {
            cout << "Client error: " << errno << endl;
            return 0;
        } else {
            cout << utcTime->tm_hour + 1 << ":" << utcTime->tm_min << ":"
                 << utcTime->tm_sec << " Server: " << receiveMessage << endl;
            ;
        }
    }
    int sendMessage() {
        time_t rawtime;
        tm* utcTime;
        time(&rawtime);
        utcTime = gmtime(&rawtime);
        char message[200];
        cout << "Enter your message" << endl;
        cin.getline(message, 200);
        int byteCount = send(clientSocket, message, 200, 0);
        if (byteCount == -1) {
            cout << "Client error when sending message:" << errno << endl;
            return -1;
        } else {
            cout << "Message sent at: " << utcTime->tm_hour + 1 << ":"
                 << utcTime->tm_min << ":" << utcTime->tm_sec
                 << endl;  // +1 BST (British Summer Time)
        }
    }
};
