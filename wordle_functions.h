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
    menu.push_back("=      Welcome to Wordle      =");
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
    menu.push_back("Select an option:");
    return menu;
}

bool containsList(std::string lookingFor, std::vector<std::string> list){
    if(std::find(list.begin(), list.end(), lookingFor) != list.end()) {
        return true;
    } else {
        return false;
    }
}



// Include functions here

#endif