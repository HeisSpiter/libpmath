#include <iostream>
#include "int.hpp"
#include "except.hpp"

bool gTryFailed = false;
unsigned int gRun = 0;
unsigned int gFailed = 0;

#define test_ok(res, exp)                                             \
    gRun++;                                                           \
    if ((res) != (exp)) {                                             \
        std::cout << "(" << __FILE__ << ":" << __LINE__;              \
        std::cout << ") Test failed. Expected: ";                     \
        std::cout << (exp) << ". Got: " << (res) << "." << std::endl; \
        gFailed++;                                                    \
    }

#define test_begin() \
    gRun = 0;        \
    gFailed = 0

#define test_end()                                   \
    std::cout << "(" << __FILE__ << ":" << __LINE__; \
    std::cout << ") " << gRun << " tests run, ";     \
    std::cout << gFailed << " failed" << std::endl

#define test_try(i) \
    gRun++;         \
    gTryFailed = i

#define test_try_set(i) \
    gTryFailed = i

#define test_try_end()                                   \
    if (gTryFailed) {                                    \
        std::cout << "(" << __FILE__ << ":" << __LINE__; \
        std::cout << ") Try test failed." << std::endl;  \
        gFailed++;                                       \
    }

int main(int, char **)
{
    int32_t j;
    TInteger i(1);
    TInteger k = 2;
    TInteger dummy;

    test_begin();

    test_ok(i, 1);
    test_ok(k, 2);

    dummy = i;
    test_ok(dummy, 1);
    test_ok(dummy, i);

    test_ok(k > i, true);
    test_ok(k >= i, true);
    test_ok(k > 2, false);
    test_ok(k >= 2, true);

    test_ok(i > k, false);
    test_ok(i >= k, false);
    test_ok(2 > k, false);
    test_ok(2 >= k, true);

    test_ok(i < k, true);
    test_ok(i <= k, true);
    test_ok(i < 1, false);
    test_ok(i <= 1, true);

    test_ok(k < i, false);
    test_ok(k <= i, false);
    test_ok(1 < i, false);
    test_ok(1 <= i, true);

    j = int32_t(k);
    test_ok(j, 2);
    j = i;
    test_ok(j, 1);
    j = (int32_t)k;
    test_ok(j, 2);

    dummy = i++;
    test_ok(dummy, 1);
    test_ok(i, 2);
    dummy = ++i;
    test_ok(dummy, 3);
    test_ok(i, 3);
    i += 5;
    test_ok(i, 8);

    i = -2;
    test_ok(i, -2);
    i++;
    test_ok(i, -1);
    i++;
    test_ok(i, 0);
    i++;
    test_ok(i, 1);

    test_try(true);
    try
    {
        while (true)
        {
            i += i;
        }
    }
    catch (TIntegerException& ie)
    {
        std::cout << "An exception occured! " << ie.what() << std::endl;
        std::cout << "Last i value:" << i.GetValue() << std::endl;
        test_try_set(false);
    }
    test_try_end();

    i = 1;
    test_ok(i, 1);
    dummy = i--;
    test_ok(dummy, 1);
    test_ok(i, 0);
    dummy = --i;
    test_ok(dummy, -1);
    test_ok(i, -1);
    i -= 5;
    test_ok(i, -6);
    i = 3;
    test_ok(i, 3);
    i -= 5;
    test_ok(i, -2);

    j = 2;
    test_try(true);
    try
    {
        while (true)
        {
            i -= j;
            j += j;
        }
    }
    catch (TIntegerException& ie)
    {
        std::cout << "An exception occured! " << ie.what() << std::endl;
        std::cout << "Last i value:" << i.GetValue() << std::endl;
        test_try_set(false);
    }
    test_try_end();

    test_try(true);
    try
    {
        j = k.Divide(1, 0);
    }
    catch (TIntegerException& ie)
    {
        std::cout << "An exception occured! " << ie.what() << std::endl;
        test_try_set(false);
    }
    test_try_end();

    test_try(true);
    try
    {
        j = k.Divide(0, 0);
    }
    catch (TIntegerException& ie)
    {
        std::cout << "An exception occured! " << ie.what() << std::endl;
        test_try_set(false);
    }
    test_try_end();

    test_try(true);
    try
    {
        j = k / 0;
    }
    catch (TIntegerException& ie)
    {
        std::cout << "An exception occured! " << ie.what() << std::endl;
        test_try_set(false);
    }
    test_try_end();

    j = k / 2;
    test_ok(j, 1);

    j = k / -2;
    test_ok(j, -1);

    k = 8;
    k /= 3;
    test_ok(k, 2);
    k = -8;
    k /= 3;
    test_ok(k, -2);
    k = 8;
    k /= -3;
    test_ok(k, -2);
    k = -8;
    k /= -3;
    test_ok(k, 2);

    i = 4;
    i = i.Divide(3, &j);
    test_ok(i, 1);
    test_ok(j, 1);

    i = 6;
    i = i.Divide(2, &j);
    test_ok(i, 3);
    test_ok(j, 0);

    i = 6;
    test_ok(i >> 1, 3);
    test_ok(i << 2, 24);
    k = 1;
    test_ok(i >> k, 3);
    k = 2;
    test_ok(i << k, 24);

    i <<= 1;
    test_ok(i, 12);
    i <<= k;
    test_ok(i, 48);
    i >>= 1;
    test_ok(i, 24);
    i >>= k;
    test_ok(i, 6);

    test_end();

    return 0;
}
