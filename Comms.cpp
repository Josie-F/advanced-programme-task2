#include "Comms.h"

#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>
using namespace std;

int Comms::RunSocket() {
    // no init or cleanup functions needed for MAC therefore not
    // implemented.
    service.sin_family = AF_INET;
    inet_pton(AF_INET, ("127.0.0.1"), &service.sin_addr.s_addr);
    int port = 3001;
    service.sin_port = htons(port);

    mainSocket =
        -1;  // invalid socket from socket() will return negative i.e -1;
    mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (mainSocket < 0) {
        cout << "Error at socket(). Error number: " << errno << endl;
        return 0;
    } else {
        cout << "socket() worked" << endl;
    }
    return 0;
}

int Comms::SendMessage(const char* socketName, int toSocket) {
    time_t rawtime;
    tm* utcTime;
    time(&rawtime);
    utcTime = gmtime(&rawtime);
    char message[200];
    cout << "Enter your message" << endl;
    cin.getline(message, 200);
    int byteCount = send(toSocket, message, 200, 0);
    if (byteCount == -1) {
        cout << socketName << " error when sending message:" << errno << endl;
        return -1;
    } else {
        cout << "Message sent at: " << utcTime->tm_hour + 1 << ":"
             << utcTime->tm_min << ":" << utcTime->tm_sec
             << endl;  // +1 BST (British Summer Time)
    }
    // return 0;
}

int Comms::ReceiveMessage(const char* socketName, int fromSocket) {
    time_t rawtime;
    tm* utcTime;
    time(&rawtime);
    utcTime = gmtime(&rawtime);
    char receiveMessage[200] = "";
    int byteCount = recv(fromSocket, receiveMessage, 200, 0);
    if (byteCount < 0) {
        cout << socketName << " error when receiving message: " << errno
             << endl;
        return -1;
    } else {
        cout << utcTime->tm_hour + 1 << ":" << utcTime->tm_min << ":"
             << utcTime->tm_sec << " " << socketName << " " << receiveMessage
             << endl;
        ;
    }
    // return 0;
}