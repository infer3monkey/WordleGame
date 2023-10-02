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

    bool notfinished = true;

    while (notfinished){
        cin >> attempt;
        if (attempt.length() != 5){
            cout << "invalid length try again" << endl;
        } else { //valid attempt. go through every letter and give back the right colors
            for(int i = 0; i < 5;i++){
                if(attempt[i] == solution[i]){//green
                    cout << green(attempt[i]);
                } else if (attempt[i] == solution[0] || attempt[i] == solution[1] || attempt[i] == solution[2] || attempt[i] == solution[3] || attempt[i] == solution[4]){
                    //yellow
                    cout << yellow(attempt[i]);
                } else { //gray
                    cout << gray(attempt[i]);
                }
            }
        }
        if (attempt == solution){
            cout << "\nCongrats you solved the Wordle!" << endl;
            notfinished = false;
        }
        cout << endl;
    }
    
    

    //cout << yellow(attempt) << endl;

    return 0;
}