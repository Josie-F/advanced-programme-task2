#include <iostream>
#include "Server.h"
#include "Client.h"

using namespace std;

int main() {
    Server tcpConnect = Server();
    tcpConnect.RunSocket();
    // Client clientConnect = Client();
    // clientConnect.RunSocket();
    return 0;
}