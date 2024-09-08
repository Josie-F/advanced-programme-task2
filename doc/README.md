# advanced-programming-task2
Task 2 for the Advanced Programming module

This programme is a Chat Application between a Server and a Client socket using a TCP connection.

## Run the Chat Application: 
There will be a Server and client executable (available within /clientProject and /serverProject)

Run the server socket:
1. cd into `/serverProject`
2. run `./server`
The server socket will start and wait for incoming connections.

Run the client socket:

3. now cd into `/clientProject`
4. run `./client`

The client will connect to the server socket.
You can now exchange messages by initiating a chat from the client. Subsequently the server can reply. 
You can close the programme by typing `Quit` from the client. This will close both sockets. 

## If you want to build the project yourself:
This project makes use of cmake to build the application.
Depending on whether you want to build the server or the client, you'll need to have cmake installed and run different cmake commands. 

### For a client build:
Delete the current client executable
1. cd into `/clientProject`
2. run `cmake .. -G "Unix Makefiles" -DCMAKE_CLIENT_BUILD=ON`
3. run `make`
4. run `./client`

### For a server build:
Delete the current server executable
1. cd into `/serverProject`
2. run `cmake .. -G "Unix Makefiles" -DCMAKE_SERVER_BUILD=ON`
3. run `make`
4. run `./server`