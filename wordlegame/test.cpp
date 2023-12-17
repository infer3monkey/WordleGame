#include <igloo/igloo.h>
#include "wordle_functions.h"
#define GREEN "\033[32m"
#define GRAY "\033[37m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

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
    Spec(helloisallgreen){//test for input of hello when the solution is hello
        std::string actual = wordleGame("hello", "hello");
        std::string expected;
        expected += GREEN"/---\\" RESET GREEN"/---\\" RESET GREEN"/---\\" RESET GREEN"/---\\" RESET GREEN"/---\\" RESET;
        expected += "\n";
        expected += GREEN"| h |" RESET GREEN"| e |" RESET GREEN"| l |" RESET GREEN"| l |" RESET GREEN"| o |" RESET;
        expected += "\n";
        expected += GREEN"\\---/" RESET GREEN"\\---/" RESET GREEN"\\---/" RESET GREEN"\\---/" RESET GREEN"\\---/" RESET;
        Assert::That(actual, Equals(expected));
    }
    Spec(slateandstate){//test for slate and state
        std::string actual = wordleGame("state", "slate");
        std::string expected;
        expected += GREEN"/---\\" RESET GRAY"/---\\" RESET GREEN"/---\\" RESET GREEN"/---\\" RESET GREEN"/---\\" RESET;
        expected += "\n";
        expected += GREEN"| s |" RESET GRAY"| t |" RESET GREEN"| a |" RESET GREEN"| t |" RESET GREEN"| e |" RESET;
        expected += "\n";
        expected += GREEN"\\---/" RESET GRAY"\\---/" RESET GREEN"\\---/" RESET GREEN"\\---/" RESET GREEN"\\---/" RESET;
        Assert::That(actual, Equals(expected));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
