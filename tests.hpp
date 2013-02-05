#ifndef __TESTS_HPP__
#define __TESTS_HPP__

#include <iostream>

extern bool gTryFailed;
extern unsigned int gRun;
extern unsigned int gFailed;

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

void TestInteger();

#endif /* #define __TESTS_HPP__ */
