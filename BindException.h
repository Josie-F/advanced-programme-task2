#include <exception>
using namespace std;
#pragma once
class BindException : public exception {
public:
    int errNo;
    BindException(){}
    BindException(int err):errNo(err){ }
    const char * what() const noexcept override { // using noexcept as const throw() is deprecated. See https://en.cppreference.com/w/cpp/language/noexcept_spec -> Deprecates
        return "BindException: Error occurred during execution of bind()";
    }
};