#ifndef __INT_HPP__
#define __INT_HPP__

#if defined(__x86_64__)
#define fastcall
#else
#define fastcall __attribute__((fastcall))
#endif

#include <iostream>
#include <sys/types.h>
#include "except.hpp"

bool fastcall Sum32(int32_t * a, int32_t b);
bool fastcall Sub32(int32_t * a, int32_t b);
int32_t fastcall Div32(int32_t * dividend, int32_t divisor);

class TInteger
{
private:
    int32_t fValue;

public:
    TInteger() { fValue = 0; }
    TInteger(int32_t value) { fValue = value; }
    TInteger(short value) { fValue = value; }
    TInteger(char value) { fValue = value; }
    TInteger(const TInteger& value) { fValue = value.fValue; }

    int32_t GetValue() const { return fValue; }
    void SetValue(int32_t value) { fValue = value; }

    int32_t operator+(int32_t a) const { return Sum(a, fValue); }
    int32_t operator+(const TInteger& a) const { return (*this)+(a.fValue); }

    TInteger& operator+=(int32_t a)
    {
        fValue = Sum(a, fValue);
        return *this;
    }

    TInteger& operator+=(const TInteger& a) { return (*this)+=(a.fValue); }
    TInteger& operator++() { return (*this)+=(1); }

    TInteger operator++(int unused)
    {
        TInteger old = *this;
        (*this)+=(1);
        return old;
    }

    int32_t operator-(int32_t a) const { return Sub(a, fValue); }
    int32_t operator-(const TInteger& a) const { return (*this)-(a.fValue); }

    TInteger& operator-=(int32_t a)
    {
        fValue = Sub(a, fValue);
        return *this;
    }

    TInteger& operator-=(const TInteger& a) { return (*this)-=(a.fValue); }
    TInteger& operator--() { return (*this)-=(1); }

    TInteger operator--(int unused)
    {
        TInteger old = *this;
        (*this)-=(1);
        return old;
    }

    int32_t operator<<(int32_t a) const { return fValue << a; }
    int32_t operator<<(const TInteger& a) const { return (*this)<<(a.fValue); }

    TInteger& operator<<=(int32_t a)
    {
        fValue = (*this)<<(a);
        return *this;
    }

    TInteger& operator<<=(const TInteger& a) { return (*this)<<=(a.fValue); }

    int32_t operator>>(int32_t a) const { return fValue >> a; }
    int32_t operator>>(const TInteger& a) const { return (*this)>>(a.fValue); }

    TInteger& operator>>=(int32_t a)
    {
        fValue = (*this)>>(a);
        return *this;
    }

    TInteger& operator>>=(const TInteger& a) { return (*this)>>=(a.fValue); }

    bool operator>(int32_t a) const { return (fValue > a); }
    bool operator>(const TInteger& a) const { return (*this)>(a.fValue); }
    bool operator<(int32_t a) const { return (fValue < a); }
    bool operator<(const TInteger& a) const { return (*this)<(a.fValue); }
    bool operator>=(int32_t a) const { return (fValue >= a); }
    bool operator>=(const TInteger& a) const { return (*this)>=(a.fValue); }
    bool operator<=(int32_t a) const { return (fValue <= a); }
    bool operator<=(const TInteger& a) const { return (*this)<=(a.fValue); }

    TInteger& operator=(int32_t a)
    {
        fValue = a;
        return *this;
    }

    TInteger& operator=(const TInteger& a) { return (*this)=(a.fValue); }

    int32_t operator/(int32_t a) const
    {
        int32_t rem;

        return Divide(a, &rem);
    }

    int32_t operator/(const TInteger& a) const { return (*this)/(a.fValue); }

    TInteger& operator/=(int32_t a)
    {
        int32_t rem;

        fValue = Divide(a, &rem);
        return *this;
    }

    TInteger& operator/=(const TInteger& a) { return (*this)/=(a.fValue); }

    bool operator!=(int32_t a) const { return (a != fValue); }
    bool operator!=(const TInteger& a) const { return (*this)!=(a.fValue); }
    bool operator==(int32_t a) const { return (a == fValue); }
    bool operator==(const TInteger& a) const { return (*this)==(a.fValue); }
    operator int32_t() { return fValue; };

    /* Implemented out of the class */
    int32_t Divide(int32_t divisor, int32_t * reminder) const throw(TNullDivisionException, TNullPointerException);
    int32_t Sub(int32_t a, int32_t b) const throw(TOverflowException);
    int32_t Sum(int32_t a, int32_t b) const throw(TOverflowException);

    /* Friend operators */
    friend std::ostream& operator<<(std::ostream& os, const TInteger& a);
    friend bool operator>(int32_t lhs, const TInteger& rhs);
    friend bool operator>=(int32_t lhs, const TInteger& rhs);
    friend bool operator<(int32_t lhs, const TInteger& rhs);
    friend bool operator<=(int32_t lhs, const TInteger& rhs);
};

inline std::ostream& operator<<(std::ostream& os, const TInteger& a)
{
    os << a.fValue;
}

inline bool operator>(int32_t lhs, const TInteger& rhs)
{
    return lhs > rhs.fValue;
}

inline bool operator>=(int32_t lhs, const TInteger& rhs)
{
    return lhs >= rhs.fValue;
}

inline bool operator<(int32_t lhs, const TInteger& rhs)
{
    return lhs < rhs.fValue;
}

inline bool operator<=(int32_t lhs, const TInteger& rhs)
{
    return lhs <= rhs.fValue;
}

#endif /* #define __INT_HPP__ */
