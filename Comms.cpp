#include "Comms.h"

#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>
using namespace std;

int Comms::SetupSocket() {
    // no init or cleanup functions needed for MAC therefore not
    // implemented.
    port = 3001;
    service.sin_family = AF_INET;
    inet_pton(AF_INET, ("127.0.0.1"), &service.sin_addr.s_addr);
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
    char message[200];
    cout << "Enter your message below" << endl;
    cin.getline(message, 200);
    int byteCount = send(toSocket, message, 200, 0);
    if (byteCount == -1) {
        cout << socketName << " error when sending message:" << errno << endl;
        return -1;
    } else {
        SetCurrentTime();
        cout << "Message sent at: " << currentTime->tm_hour + 1 << ":"
             << currentTime->tm_min << ":" << currentTime->tm_sec
             << endl;  // +1 BST (British Summer Time)
    }
    // return 0;
}

int Comms::ReceiveMessage(const char* socketName, int fromSocket) {
    char receivedMessage[200];
    int byteCount = recv(fromSocket, receivedMessage, 200, 0);
    if (byteCount < 0) {
        cout << socketName << " error when receiving message: " << errno
             << endl;
        return -1;
    } else {
        SetCurrentTime();
        cout << currentTime->tm_hour + 1 << ":" << currentTime->tm_min << ":"
             << currentTime->tm_sec << " " << socketName << ": " << receivedMessage
             << endl;
        ;
    }
    // return 0;
}

void Comms::SetCurrentTime(){
    time_t rawtime;
    tm* utcTime;
    time(&rawtime);
    currentTime = gmtime(&rawtime);
}
