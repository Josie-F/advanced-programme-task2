#include <exception>
using namespace std;
#pragma once
class AcceptException : public exception {
public:
    int errNo;
    AcceptException(){}
    AcceptException(int err):errNo(err){ }
    const char * what() const noexcept override { // using noexcept as const throw() is deprecated. See https://en.cppreference.com/w/cpp/language/noexcept_spec -> Deprecates
        return "AcceptException: Error occurred during execution of accept()";
    }
};