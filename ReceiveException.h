#include <exception>
using namespace std;
#pragma once
class ReceiveException : public exception {
public:
    int errNo;
    ReceiveException(){}
    ReceiveException(int err):errNo(err){ }
    const char * what() const noexcept override { // using noexcept as const throw() is deprecated. See https://en.cppreference.com/w/cpp/language/noexcept_spec -> Deprecates
        return "ReceiveException: Error occurred during execution of recv()";
    }
};