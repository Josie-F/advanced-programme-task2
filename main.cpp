#include <iostream>

#include "Client.h"
#include "Server.h"

using namespace std;

int main() {
    try {
        // Server serverSocket = Server();
        // serverSocket.SetupSocket();
        // serverSocket.Configure();
        // serverSocket.Accept();

        Client clientSocket = Client();
        clientSocket.SetupSocket();
        clientSocket.Connect();
    } catch (
        SocketException& e) {  // catch as reference so as to not create copy
        cout << e.what() << " Error number: " << e.errNo
             << endl;  // could just call 'errno' directly here, however i
                       // wanted to use the exception information pattern.
    } catch (SendException& e) {
        cout << e.what() << " Error number: " << e.errNo << endl;
    } catch (ConnectException& e) {
        cout << e.what() << " Error number: " << e.errNo << endl;
    } catch (BindException& e) {
        cout << e.what() << " Error number: " << e.errNo << endl;
    }
    return 0;
}