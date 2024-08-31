#include <iostream>
#include "Server.h"

using namespace std;

int main() {
    Server tcpConnect = Server();
    tcpConnect.RunSocket();
    return 0;
}