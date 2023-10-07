#include <igloo/igloo.h>
#include "wordle_functions.h"

using namespace igloo;

Context(TODO){
    Spec(iisinstringigloo){//test for contains function
        int actual = contains('i', "igloo");
        int expected = 0;
        Assert::That(actual, Equals(expected));
    }
    Spec(iisnotinstringglue){//test for contains function
        int actual = contains('i', "glue");
        int expected = -1;
        Assert::That(actual, Equals(expected));
    }
    Spec(helloisinstringvector){//test for containsList function
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
