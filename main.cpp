#include <iostream>
#include "wordle_functions.h"



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

    cout << yellow(attempt) << endl;

    return 0;
}