#include <igloo/igloo.h>
#include "wordle_functions.h"

using namespace igloo;

//look at lecture 10 video to find out how to do unit test for color
Context(TODO){
    Spec(iisinstringigloo){
        int actual = contains('i', "igloo");
        int expected = 0;
        Assert::That(actual, Equals(expected));
    }
    Spec(iisnotinstringglue){
        int actual = contains('i', "glue");
        int expected = -1;
        Assert::That(actual, Equals(expected));
    }
    Spec(helloisinstringvector){
        std::string hello = "hello";
        std::vector<std::string> stringvec;
        stringvec.push_back("hello");
        bool actual = containsList(hello, stringvec);
        bool expected = true;
        Assert::That(actual, Equals(expected));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
