#include <exception>
using namespace std;
#pragma once
class SocketException : public exception {
public:
    int errNo;
    SocketException(){ }
    SocketException(int err):errNo(err){ }
    const char * what() const noexcept override { // using noexcept as const throw() is deprecated. See https://en.cppreference.com/w/cpp/language/noexcept_spec -> Deprecates
        return  ("SocketException: Error occurred during execution of socket()") ;
    }
};