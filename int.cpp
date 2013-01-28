#include "int.hpp"

int32_t TInteger::Divide(int32_t divisor, int32_t * reminder) const throw(TNullDivisionException, TNullPointerException)
{
    int32_t res;

    if (reminder == 0)
    {
        throw TNullPointerException();
    }

    if (divisor == 0)
    {
        throw TNullDivisionException();
    }

    *reminder = fValue;
    __asm__ __volatile__("call Div\n"
                         : "=a"(res), "=c"(reminder)
                         : "c"(reminder), "b"(divisor));
    return res;
}

int32_t TInteger::Sub(int32_t a, int32_t b) const throw(TOverflowException)
{
    bool Overflow;
    int32_t * Address = &b;

    __asm__ __volatile__("call Sub\n"
                         : "=a"(Overflow), "=c"(Address)
                         : "c"(Address), "d"(a));

    if (Overflow)
    {
        throw TOverflowException();
    }

    return b;
}

int32_t TInteger::Sum(int32_t a, int32_t b) const throw(TOverflowException)
{
    bool Overflow;
    int32_t * Address = &b;

    __asm__ __volatile__("call Sum\n"
                         : "=a"(Overflow), "=c"(Address)
                         : "c"(Address), "d"(a));

    if (Overflow)
    {
        throw TOverflowException();
    }

    return b;
}
