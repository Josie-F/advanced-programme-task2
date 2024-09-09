#include <iostream>
// if statement added to accomodate for exceptions that would be undefined if
// either client or server isnt specified. using 'if !defined()' instead of ifndef to allow the || operator. 
#if !defined(CLIENTBUILD) || !defined(SERVERBUILD)
#include "Exceptions.h"
#endif

#ifdef SERVERBUILD
#include "./Server/Server.h"
#endif
#ifdef CLIENTBUILD
#include "./Client/Client.h"
#endif
using namespace std;

int main() {
    try {
#ifdef SERVERBUILD
        Server serverSocket = Server();
        serverSocket.SetupSocket();
        serverSocket.Configure();
        serverSocket.Accept();
#endif
#ifdef CLIENTBUILD
        Client clientSocket = Client();
        clientSocket.SetupSocket();
        clientSocket.Connect();
#endif
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
    } catch (ReceiveException& e) {
       cout << e.what() << " Error number: " << e.errNo << endl; 
    } catch (ListenException& e) {
        cout << e.what() << " Error number: " << e.errNo << endl; 
     } catch (AcceptException& e) {
        cout << e.what() << " Error number: " << e.errNo << endl; 
    }
    return 0;
}
