#include <iostream>

#include "Client.h"
#include "Server.h"

using namespace std;

int main() {
    Server serverSocket = Server();
    serverSocket.SetupSocket();
    serverSocket.Configure();
    serverSocket.Accept();

    // Client clientSocket = Client();
    // clientSocket.SetupSocket();
    // clientSocket.Connect();
    return 0;
}