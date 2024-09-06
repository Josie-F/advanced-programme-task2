#include <iostream>

#include "Client.h"
#include "Server.h"

using namespace std;

int main() {
    Server tcpConnect = Server();
    tcpConnect.RunSocket();
    // Client clientConnect = Client();
    // clientConnect.RunSocket();
    return 0;
}