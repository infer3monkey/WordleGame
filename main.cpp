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
    string realsolution = "SLATE";
    string attempt = "";
    string solution;
    bool notfinished = true;

    while (notfinished){
        solution = realsolution;
        cin >> attempt;
        if (attempt.length() != 5){
            cout << "invalid length try again" << endl;
        } else { //valid attempt. go through every letter and give back the right colors
            for(int i = 0; i < 5;i++){ // SLATE and SLASA as the guess would only have first s as green
                //SLATE AND ASASA as the guess would only have the first s as yellow
                //use a place holder
                if(attempt[i] == solution[i]){//green
                    cout << green(attempt[i]);
                    solution[i] = '-';
                } else if (contains(attempt[i], solution) != -1){
                    //yellow
                    cout << yellow(attempt[i]);
                    solution[contains(attempt[i], solution)] = '-';
                    //solution[i] = '-'; need to find where the thing
                } else { //gray
                    cout << gray(attempt[i]);
                }
            }
        }
        if (attempt == realsolution){
            cout << "\nCongrats you solved the Wordle!" << endl;
            notfinished = false;
        }
        cout << endl;
    }
    
    

    //cout << yellow(attempt) << endl;

    return 0;
}