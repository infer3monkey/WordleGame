#include <iostream>
#include "wordle_functions.h"

#define GREEN "\033[42;30m"
#define GRAY "\033[47;30m"
#define YELLOW "\033[43;30m"
#define RESET "\033[0m"

using namespace std;

//git init
//git add .
//git commit -m "message"
//git log 
//git checkout 
//more stuff in slides if needed

int main(int argc, char* argv[]) {
    //Create Main Menu

    //TODO: select this randomly from the words.txt file
    string solution = "SLATE";
    string attempt = "";
    cin >> attempt;

    cout << GRAY << attempt << RESET << endl;

    return 0;
}