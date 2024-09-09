#include "Comms.h"

#include <arpa/inet.h>  // for inet_pton()
#include <netdb.h>
#include <unistd.h>  // needed for close ()

#include <iostream>
using namespace std;

// Function to set up a socket
int Comms::SetupSocket() {
    // no init or cleanup functions needed for MAC therefore not
    // implemented.
    // create the port and address.
    port = 3001;
    service.sin_family = AF_INET;
    inet_pton(AF_INET, ("127.0.0.1"), &service.sin_addr.s_addr);
    service.sin_port = htons(port);

    // create a TCP connection socket
    mainSocket =
        -1;  // invalid socket from socket() will return negative i.e -1;
    mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (mainSocket < 0) {
        SocketException socketError(errno);
        throw socketError;
    } else {
        cout << "Created a socket" << endl;
    }
    return 0;
}

// Function to send a message to given socket.
int Comms::SendMessage(const char* socketName, int toSocket) {
    char message[200];
    cout << "Enter your message below" << endl;
    cin.getline(message, 200);
    // send a char array to the specified socket, with the message the user
    // typed into the command line.
    int byteCount = send(toSocket, message, 200, 0);
    if (byteCount == -1) {
        SendException sendError(errno);
        throw sendError;
    } else {
        // set and use current time for UI purposes.
        SetCurrentTime();
        cout << "Message sent at: " << currentTime->tm_hour + 1 << ":"
             << currentTime->tm_min << ":" << currentTime->tm_sec
             << endl;  // +1 BST (British Summer Time)
    }
    if ((strcmp(socketInstanceName, "Client") == 0)) {
        if ((strcmp(message, "Quit") == 0) ||
            (strcmp(message, "QUIT") ==
             0)) {  // if the client typed quit, return and close the
                    // connection.
            cout << "Closing client" << endl;
            return 1;
        }
    }
    return 0;
}

// Function to receive message from given socket.
int Comms::ReceiveMessage(const char* socketName, int fromSocket) {
    char receivedMessage[200];
    // receive incoming message from specified socket.
    int byteCount = recv(fromSocket, receivedMessage, 200, 0);
    if (byteCount < 0) {
        ReceiveException receiveError(errno);
        throw receiveError;
    } else {
        if ((strcmp(socketInstanceName, "Server") == 0)) {
            if ((strcmp(receivedMessage, "Quit") == 0) ||
                (strcmp(receivedMessage, "QUIT") ==
                 0)) {  // if the client typed quit, return and close the server
                        // connection.
                cout << "Client disconnected. Closing server" << endl;
                return 1;
            }
        }
        // set and use current time for UI purposes.
        SetCurrentTime();
        cout << currentTime->tm_hour + 1 << ":" << currentTime->tm_min << ":"
             << currentTime->tm_sec << " " << socketName << ": "
             << receivedMessage << endl;
        ;
    }
    return 0;
}

// Helper function to set current time which is used for UI purposes.
void Comms::SetCurrentTime() {
    time_t rawtime;
    tm* utcTime;
    time(&rawtime);
    currentTime = gmtime(&rawtime);
}
