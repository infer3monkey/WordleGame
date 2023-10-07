#include <iostream>
#include "wordle_functions.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    //put more things into header file, add the separate main menu options(stats, let people play again)
    //add unit tests especially for the wordle game itself(check lecture video), add keyboard viewer, turn everything to caps

    string attempt = "";
    string playerInput = "";
    vector<string> wordlist;
    vector<string> attemptlist;
    bool won = false;

    

    ifstream file2;
    file2.open("words.txt", ios::in);

    if (file2.is_open()){
        string word;
        while(file2 >> word){
            wordlist.push_back(word);
        }
        file2.close();
    }

    string solution = chooseRandom(wordlist);//randomly generated solution

    ifstream file;
    file.open("allowed.txt", ios::in);

    if (file.is_open()){
        string word;
        while(file >> word){
            wordlist.push_back(word);
        }
        file.close();
    }

    cout << mainmenu();

    bool mainmenubool = true;

    while(mainmenubool){ //main menu screen making sure input is valid
        getline(cin, playerInput);

        if (stoi(playerInput) == 1){//player wants to play wordle, breaks the program if not integer
            //mainmenubool = false;
            cout << "\nYou Are Now Playing Wordle. You Have 6 Valid Attempts" << endl;
            for(int i = 0; i < 6; i++){//wordle game
                getline(cin, attempt);

                bool inWords = containsList(attempt, wordlist);

                if (attempt.length() != 5){
                    cout << "invalid length try again" << endl;
                    i--;//invalid attempt
                } else if (inWords == false){
                    cout << "invalid word try again" << endl;
                    i--;//invalid attempt
                } else { //valid attempt return the word with correct colors
                    attemptlist.push_back(wordleGame(attempt, solution));
                    for(int i = 0; i < attemptlist.size();i++){
                        cout << attemptlist[i] << endl;
                    }
                }
                if (attempt == solution){
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
        } else if (stoi(playerInput) == 6){
            mainmenubool = false;
        } else {
            cout << "not a proper option or have not created it\nSelect a number:";
        }
        
    }

    
    

    return 0;
}