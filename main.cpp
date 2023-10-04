#include <iostream>
#include "wordle_functions.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    //TODO: select this randomly from the words.txt file
    string solution = "slate";
    string attempt = "";
    bool notfinished = true;
    vector<string> allowedlist;
    vector<string> wordlist;

    ifstream file;
    file.open("allowed.txt", ios::in);

    if (file.is_open()){
        string word;
        while(file >> word){
            allowedlist.push_back(word);
        }
    }

    file.close();

    ifstream file2;
    file2.open("words.txt", ios::in);

    if (file2.is_open()){
        string word;
        while(file2 >> word){
            wordlist.push_back(word);
        }
    }

    file2.close();

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
        string playerInput;
        cin >> playerInput;

        if (stoi(playerInput) == 1){//player wants to play wordle
            mainmenu = false;
            cout << endl;
            //can put the code here if needed?
        } else {
            cout << "not a proper option or have not created it" << endl;
            cout << "Select a number:";
        }
        
    }
    
    while (notfinished){ //where the input happens for the wordle game
        cout << "Your guess: ";
        cin >> attempt;

        bool inAllowed = containsList(attempt, allowedlist);
        bool inWords = containsList(attempt, wordlist);

        if (attempt.length() != 5){
            cout << "invalid length try again" << endl;
        } else if (inWords == false && inAllowed == false){
            cout << "invalid word try again" << endl;
        } else { //valid attempt return the word with correct colors
            cout << wordleGame(attempt, solution) << endl;
        }
        if (attempt == solution){
            cout << "\nCongrats you solved the Wordle!" << endl;
            notfinished = false;
        }
    }

    return 0;
}