#include <iostream>
#include "wordle_functions.h"
#include <fstream>
#include <ctype.h>

using namespace std;

int main(int argc, char* argv[]) {
    //add stat options, make case sensitivity not matter
    //add unit tests, add keyboard viewer

    string playerInput = "";
    vector<string> wordlist = listgeneration();
    vector<string> attemptlist;
    string solution = solutiongeneration();
    bool won = false;
    cout << mainmenu();
    bool mainmenubool = true;

    while(mainmenubool){ //main menu
        getline(cin, playerInput);

        if (stoi(playerInput) == 1){//player wants to play wordle
            cout << "\nYou Are Now Playing Wordle. You Have 6 Valid Attempts" << endl;
            for(int i = 0; i < 6; i++){//loop for 6 attempts
                getline(cin, playerInput);

                if (containsList(playerInput, wordlist) == false){
                    cout << "invalid word" << endl;
                    i--;
                } else { //valid attempt return the word with correct colors
                    attemptlist.push_back(wordleGame(playerInput, solution));
                    for(int i = 0; i < attemptlist.size();i++){
                        cout << attemptlist[i] << endl;
                    }
                }
                if (playerInput == solution){//if guessed the word correctly
                    cout << "\nCongrats you solved the Wordle in " << i+1 << " attempts!" << endl;
                    won = true;
                    break;
                }
            }
            if (won == false){//loss message
                cout << "You did not complete the Wordle in 6 attempts. The word was: " << solution << endl;
            }
            bool wordlegamemenu = true;
            cout << "Press [enter] to go back to the main menu\n";
            while(wordlegamemenu){
                getline(cin, playerInput);
                if(playerInput == ""){
                    wordlegamemenu = false;
                }
            }
            cout << "\n" << mainmenu();

        } else if (stoi(playerInput) == 2) {//player wants to go to how to play screen
            cout << howtoplaymenu();
            bool howtoplaymenu = true;
            while(howtoplaymenu){
                getline(cin, playerInput);
                if(playerInput == ""){
                    howtoplaymenu = false;
                }
            }
            cout << "\n" << mainmenu();
        } else if (stoi(playerInput) == 5){//player wants to exit
            mainmenubool = false;
        } else {
            cout << "not a proper option or have not created it\nSelect a number:";
        }
        
    }

    return 0;
}