#include <iostream>
#include "wordle_functions.h"
#include<fstream>



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
    string realsolution = "acorn";
    string attempt = "";
    string solution;
    bool notfinished = true;
    vector<string> allowedlist; //look into changing this into a set if it is slow
    vector<string> wordlist; //look into changing this into a set if it is slow

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
    
    while (notfinished){ //the actual wordle game itself
        solution = realsolution;
        cout << "Your guess: ";
        cin >> attempt;

        bool inAllowed = containsList(attempt, allowedlist);
        bool inWords = containsList(attempt, wordlist);

        if (attempt.length() != 5){
            cout << "invalid length try again" << endl;
        } else if (inWords == false && inAllowed == false){
            cout << "invalid word try again" << endl;
        //move this into wordle_functions.h as a function
        } else { //valid attempt. go through every letter and give back the right colors
            for(int i = 0; i < 5;i++){ 
                if(attempt[i] == solution[i]){//green
                    cout << green(attempt[i]);
                    solution[i] = '-';
                } else if (contains(attempt[i], solution) != -1){//yellow
                    if(isGreen(attempt, solution) == -1){
                        cout << yellow(attempt[i]);
                        solution[contains(attempt[i], solution)] = '-';
                    } else { //there is another value that should be green
                        cout << gray(attempt[i]);
                        //solution[contains(attempt[i], solution)] = '-';
                    }
                    
                } else { //gray
                    cout << gray(attempt[i]);
                }
            }
            cout << endl;
        }
        if (attempt == realsolution){
            cout << "\nCongrats you solved the Wordle!" << endl;
            notfinished = false;
        }
    }

    return 0;
}