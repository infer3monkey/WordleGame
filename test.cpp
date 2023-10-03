#include <igloo/igloo.h>
#include "wordle_functions.h"

using namespace igloo;

Context(TODO){
    Spec(iisinstringigloo){
        int expected = contains('i', "igloo");
        int actual = 0;
        Assert::That(expected, Equals(actual));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
