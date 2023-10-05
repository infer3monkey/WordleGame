#include <iostream>
#include "wordle_functions.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    //Select randomly, put more things into header file, add the separate main menu options(stats)
    //you only have 6 attempts to get it right not infinite, make more visually appealing
    //add unit tests especially for the wordle game itself, add keyboard viewer

    string solution = "worry";
    string attempt = "";
    string playerInput = "";
    vector<string> allowedlist;
    vector<string> wordlist;
    vector<string> attemptlist;

    ifstream file;
    file.open("allowed.txt", ios::in);

    if (file.is_open()){
        string word;
        while(file >> word){
            allowedlist.push_back(word);
        }
        file.close();
    }

    ifstream file2;
    file2.open("words.txt", ios::in);

    if (file2.is_open()){
        string word;
        while(file2 >> word){
            wordlist.push_back(word);
        }
        file2.close();
    }

    vector<string> mainmenustring = mainmenu();

    for (int i = 0; i < mainmenustring.size();i++){//printing out main menu
        if(i+1 != mainmenustring.size()){
            cout << mainmenustring[i] << endl;
        } else {
            cout << mainmenustring[i]; //last element no endl
        }
    }

    bool mainmenu = true;

    while(mainmenu){ //main menu screen making sure input is valid
        cin >> playerInput;

        if (stoi(playerInput) == 1){//player wants to play wordle, breaks the program if not integer
            mainmenu = false;
            cout << endl;
            cout << "You Are Now Playing Wordle. You Have 6 Valid Attempts" << endl;
            //can put the code here if needed?
        } else {
            cout << "not a proper option or have not created it" << endl;
            cout << "Select a number:";
        }
        
    }

    for(int i = 0; i < 6; i++){
        //cout << "Guess #" << i+1 << ":";
        cin >> attempt;

        bool inAllowed = containsList(attempt, allowedlist);
        bool inWords = containsList(attempt, wordlist);

        if (attempt.length() != 5){
            cout << "invalid length try again" << endl;
            i--;//invalid attempt
        } else if (inWords == false && inAllowed == false){
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
            break;
        }
    }
    cout << "You did not complete the Wordle in 6 attempts. The word was: " << solution << endl;

    return 0;
}