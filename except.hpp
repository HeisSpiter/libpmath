#ifndef __EXCEPT_HPP__
#define __EXCEPT_HPP__

#include <exception>

class TIntegerException : public std::exception
{
public:
    virtual const char * what() const throw() = 0;
};

#define DefineClass(name, msg)                        \
class T##name##Exception : public TIntegerException { \
public:                                               \
    virtual const char * what() const throw() {       \
        return msg;                                   \
    }                                                 \
}

DefineClass(Overflow, "An overflow occured!");
DefineClass(NullDivision, "A divison by 0 occured!");
DefineClass(NullPointer, "A null pointer was given!");

#endif /* #define __EXCEPT_HPP__ */
