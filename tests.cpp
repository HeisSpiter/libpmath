#include "tests.hpp"

bool gTryFailed;
unsigned int gRun;
unsigned int gFailed;

int main(int, char **)
{
    TestInteger();

    return 0;
}
