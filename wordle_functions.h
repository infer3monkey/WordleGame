#ifndef WORDLE_FUNCTIONS_H
#define WORDLE_FUNCTIONS_H

#define GREEN "\033[42;30m"
#define GRAY "\033[47;30m"
#define YELLOW "\033[43;30m"
#define RESET "\033[0m"

#include<vector>
#include<iostream>

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


// Include functions here

#endif