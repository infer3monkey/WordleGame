#ifndef WORDLE_FUNCTIONS_H
#define WORDLE_FUNCTIONS_H

#define GREEN "\033[42;30m"
#define GRAY "\033[47;30m"
#define YELLOW "\033[43;30m"
#define RESET "\033[0m"

#include<vector>
#include<iostream>

std::string yellow(std::string letter){
    std::string result = YELLOW;
    result += letter;
    result += RESET;
    return result;
}

std::string green(std::string letter){
    std::string result = GREEN;
    result += letter;
    result += RESET;
    return result;
}

std::string gray(std::string letter){
    std::string result = GRAY;
    result += letter;
    result += RESET;
    return result;
}


// Include functions here

#endif