#include <exception>
using namespace std;
#pragma once
class SendException : public exception {
public:
    int errNo;
    SendException(){}
    SendException(int err):errNo(err){ }
    const char * what() const noexcept override { // using noexcept as const throw() is deprecated. See https://en.cppreference.com/w/cpp/language/noexcept_spec -> Deprecates
        return "SendException: Error occurred during execution of send()";
    }
};