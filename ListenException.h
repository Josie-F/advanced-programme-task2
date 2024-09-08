#include <exception>
using namespace std;
#pragma once
class ListenException : public exception {
public:
    int errNo;
    ListenException(){}
    ListenException(int err):errNo(err){ }
    const char * what() const noexcept override { // using noexcept as const throw() is deprecated. See https://en.cppreference.com/w/cpp/language/noexcept_spec -> Deprecates
        return "ListenException: Error occurred during execution of listen()";
    }
};