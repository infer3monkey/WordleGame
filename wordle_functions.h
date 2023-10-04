#ifndef WORDLE_FUNCTIONS_H
#define WORDLE_FUNCTIONS_H

#define GREEN "\033[42;30m"
#define GRAY "\033[47;30m"
#define YELLOW "\033[43;30m"
#define RESET "\033[0m"

#include<vector>
#include<iostream>
#include<algorithm>

//change the string to character possibly
std::string yellow(char letter){
    std::string result = YELLOW;
    result += letter;
    result += RESET;
    return result;
}

std::string green(char letter){
    std::string result = GREEN;
    result += letter;
    result += RESET;
    return result;
}

std::string gray(char letter){
    std::string result = GRAY;
    result += letter;
    result += RESET;
    return result;
}

int contains (char letter, std::string str){
    for (int i = 0; i < str.length();i++){
        if (letter == str[i]){
            return i;
        }
    }
    return -1;
}

std::vector<std::string> mainmenu(){
    std::vector<std::string> menu;
    menu.push_back("===============================");
    menu.push_back("       Welcome to Wordle       ");
    menu.push_back("===============================");
    menu.push_back("                               ");
    menu.push_back("                               ");
    menu.push_back("1. Play Wordle");
    menu.push_back("2. How to Play");
    menu.push_back("3. Statistics Summary");
    menu.push_back("4. Reset Statistics");
    menu.push_back("5. Exit");
    menu.push_back("                               ");
    menu.push_back("                               ");
    menu.push_back("Select a number:");
    return menu;
}

bool containsList(std::string lookingFor, std::vector<std::string> list){
    if(std::find(list.begin(), list.end(), lookingFor) != list.end()) {
        return true;
    } else {
        return false;
    }
}

/*int isGreen(std::string input, std::string str){//returns -1 if there is no exact position that should be green otherwise returns index where it should be green
    for (int i = 0; i < str.length();i++){
        if (input[i] == str[i]){//checking if it is green. first occurence
            return i;
        }
        return -1;//there is no value wehre this would be green
    }
}*/

std::string wordleGame(std::string attempt, std::string solution){//check for green, then check for yellow, then make everything else gray

    std::string answer = "";
    std::vector<int> list = {0, 0, 0, 0, 0};//0 stands for gray, 1 for yellow, 2 for green

    for(int i = 0; i < 5; i++){//loop for finding green
        if(attempt[i] == solution[i]){
            list[i] = 2;
            solution[i] = '-';
        }
    }

    for(int i =0; i < 5; i++){
        if(list[i] != 2){//if value not already green
            if(contains(attempt[i], solution) != -1){//value exists therefore yellow
                list[i] = 1;
                solution[contains(attempt[i], solution)] = '-';
            }
        }
    }

    for(int i = 0; i < 5; i++){//loop that creates the string

    }

    /*for(int i = 0; i < 5;i++){ 
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
            }*/
}





// Include functions here

#endif