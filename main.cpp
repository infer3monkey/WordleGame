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
    string realsolution = "SLATE";
    string attempt = "";
    string solution;
    bool notfinished = true;
    //hello
    vector<string> allowedlist; //look into changing this into a set if it is slow

    ifstream file;
    file.open("allowed.txt", ios::in);

    if (file.is_open()){
        string word;
        while(file >> word){
            allowedlist.push_back(word);
        }
    }

    while (notfinished){
        solution = realsolution;
        cout << "Your input: ";
        cin >> attempt;

        if (attempt.length() != 5){
            cout << "invalid length try again" << endl;
        } else if (containsList(attempt, allowedlist)!= true){
            cout << "invalid word try again" << endl;
        } else { //valid attempt. go through every letter and give back the right colors
            for(int i = 0; i < 5;i++){ 
                if(attempt[i] == solution[i]){//green
                    cout << green(attempt[i]);
                    solution[i] = '-';
                } else if (contains(attempt[i], solution) != -1){//yellow
                    cout << yellow(attempt[i]);
                    solution[contains(attempt[i], solution)] = '-';
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