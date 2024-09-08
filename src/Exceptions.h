#include <exception>
using namespace std;
#pragma once
// Header file that groups the individual classes of exceptions which can be thrown
// throughout the application. I've kept it in a header file as it is minimum implementation/logic.

class AcceptException : public exception {
public:
    int errNo;
    AcceptException() {
    }
    AcceptException(int err) : errNo(err) {
    }
    const char* what() const noexcept
        override {  // using noexcept as const throw() is deprecated. See
                    // https://en.cppreference.com/w/cpp/language/noexcept_spec
                    // -> Deprecates
        return "AcceptException: Error occurred during execution of accept()";
    }
};

#pragma once
class BindException : public exception {
public:
    int errNo;
    BindException() {
    }
    BindException(int err) : errNo(err) {
    }
    const char* what() const noexcept override {
        return "BindException: Error occurred during execution of bind()";
    }
};

#pragma once
class ConnectException : public exception {
public:
    int errNo;
    ConnectException() {
    }
    ConnectException(int err) : errNo(err) {
    }
    const char* what() const noexcept override {
        return "ConnectException: Error occurred during execution of connect()";
    }
};

#pragma once
class ListenException : public exception {
public:
    int errNo;
    ListenException() {
    }
    ListenException(int err) : errNo(err) {
    }
    const char* what() const noexcept override {
        return "ListenException: Error occurred during execution of listen()";
    }
};

#pragma once
class ReceiveException : public exception {
public:
    int errNo;
    ReceiveException() {
    }
    ReceiveException(int err) : errNo(err) {
    }
    const char* what() const noexcept override {
        return "ReceiveException: Error occurred during execution of recv()";
    }
};

#pragma once
class SendException : public exception {
public:
    int errNo;
    SendException() {
    }
    SendException(int err) : errNo(err) {
    }
    const char* what() const noexcept override {
        return "SendException: Error occurred during execution of send()";
    }
};

#pragma once
class SocketException : public exception {
public:
    int errNo;
    SocketException() {
    }
    SocketException(int err) : errNo(err) {
    }
    const char* what() const noexcept override {
        return ("SocketException: Error occurred during execution of socket()");
    }
};
