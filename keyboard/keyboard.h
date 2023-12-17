#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "../wordlegame/wordle_functions.h"

#define GREEN "\033[32m"
#define GRAY "\033[37m"
#define REALGRAY "\033[90m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

int findletterindex(char letter, std::vector<char> letters){
    for(int i = 0; i < letters.size(); i++){
        if(letters[i] == letter){
            return i;
        }
    }
    return 0;
}

void updatekeyboard(){
    std::ifstream file;
    std::string solution = "";
    file.open("../wordlegame/guesses.txt", std::ios::in);
    std::vector<std::string> guesses;
    std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::vector<int> lettervalues = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//0 is gray, 1 is yellow, 2 is green, 3 is for real gray

    if (file.is_open()){
        std::string word;
        while(file >> word){
            if(solution == ""){//for the solution
                solution = word;
            } else {//for the other words
                guesses.push_back(word);
            }
        }
        file.close();
    }

    for(int i = 0; i < guesses.size();i++){//looping through every guess for green first
        for(int j = 0; j < 5; j++){
            if(guesses[i][j] == solution[j]){
                int index = findletterindex(guesses[i][j], letters);
                if(lettervalues[index]==0){
                    lettervalues[index] = 2;
                }
            }
        }
    }

    for(int i =0; i < guesses.size();i++){//looping through every guess for yellow
        for(int j = 0; j < 5; j++){
            int index = findletterindex(guesses[i][j], letters);
            if(lettervalues[index] != 2 && lettervalues[index] == 0){
                if(contains(guesses[i][j], solution) != -1){//if the letter is not already green and exists in this word it is yellow
                    lettervalues[index] = 1;
                }
            }
        }
    }

    for(int i = 0; i < guesses.size();i++){
        for(int j = 0; j < 5; j++){
            int index = findletterindex(guesses[i][j], letters);
            if(lettervalues[index] == 0){
                lettervalues[index] = 3;
            }
        }
    }
    std::vector<int> firstrow = {16, 22, 4, 17, 19, 24, 20, 8, 14, 15};//q w e r t y u i o p
    std::vector<int> secondrow = {0, 18, 3, 5, 6, 7, 9, 10, 11};//a s d f g h j k l
    std::vector<int> thirdrow = {25, 23, 2, 21, 1, 13, 12};//z x c v b n m 
    
    std::string keyboard;

    system("clear");
    
    //start of first row
    for(int i = 0; i < firstrow.size(); i++){//loop that makes more visually appealing
        std::string result;
        if(lettervalues[firstrow[i]] == 2){//if value is supposed to be green
            result = GREEN;
        } else if(lettervalues[firstrow[i]] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else if(lettervalues[firstrow[i]] == 3) {//if values is truly gray
            result = REALGRAY;
        } else {
            result = GRAY;
        }
        result += "/---\\";
        result += RESET;
        keyboard += result;
    }
    keyboard += "\n";

    for(int i = 0; i < firstrow.size(); i++){//loop that puts the letters in string
        std::string result;
        if(lettervalues[firstrow[i]] == 2){//if value is supposed to be green
            result = GREEN;
        } else if(lettervalues[firstrow[i]] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else if(lettervalues[firstrow[i]] == 3) {//if values is truly gray
            result = REALGRAY;
        } else {
            result = GRAY;
        }
        result += "| ";
        result += letters[firstrow[i]];
        result += " |";
        result += RESET;
        keyboard += result;
    }
    keyboard += "\n";

    for(int i = 0; i < firstrow.size(); i++){//loop that makes more visually appealing
        std::string result;
        if(lettervalues[firstrow[i]] == 2){//if value is supposed to be green
            result = GREEN;
        } else if(lettervalues[firstrow[i]] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else if(lettervalues[firstrow[i]] == 3) {//if values is truly gray
            result = REALGRAY;
        } else {
            result = GRAY;
        }
        result += "\\---/";
        result += RESET;
        keyboard += result;
    } //end of first row
    keyboard += '\n';
    keyboard+= "  ";
    //start of second row
    for(int i = 0; i < secondrow.size(); i++){//loop that makes more visually appealing
        std::string result;
        if(lettervalues[secondrow[i]] == 2){//if value is supposed to be green
            result = GREEN;
        } else if(lettervalues[secondrow[i]] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else if(lettervalues[secondrow[i]] == 3) {//if values is truly gray
            result = REALGRAY;
        } else {
            result = GRAY;
        }
        result += "/---\\";
        result += RESET;
        keyboard += result;
    }
    keyboard += "\n";
    keyboard+= "  ";
    for(int i = 0; i < secondrow.size(); i++){//loop that puts the letters in string
        std::string result;
        if(lettervalues[secondrow[i]] == 2){//if value is supposed to be green
            result = GREEN;
        } else if(lettervalues[secondrow[i]] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else if(lettervalues[secondrow[i]] == 3) {//if values is truly gray
            result = REALGRAY;
        } else {
            result = GRAY;
        }
        result += "| ";
        result += letters[secondrow[i]];
        result += " |";
        result += RESET;
        keyboard += result;
    }
    keyboard += "\n";
    keyboard+= "  ";
    for(int i = 0; i < secondrow.size(); i++){//loop that makes more visually appealing
        std::string result;
        if(lettervalues[secondrow[i]] == 2){//if value is supposed to be green
            result = GREEN;
        } else if(lettervalues[secondrow[i]] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else if(lettervalues[secondrow[i]] == 3) {//if values is truly gray
            result = REALGRAY;
        } else {
            result = GRAY;
        }
        result += "\\---/";
        result += RESET;
        keyboard += result;
    } //end of second row

    keyboard += '\n';
    keyboard+= "      ";
    //start of third row
    for(int i = 0; i < thirdrow.size(); i++){//loop that makes more visually appealing
        std::string result;
        if(lettervalues[thirdrow[i]] == 2){//if value is supposed to be green
            result = GREEN;
        } else if(lettervalues[thirdrow[i]] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else if(lettervalues[thirdrow[i]] == 3) {//if values is truly gray
            result = REALGRAY;
        } else {
            result = GRAY;
        }
        result += "/---\\";
        result += RESET;
        keyboard += result;
    }
    keyboard += "\n";
    keyboard+= "      ";
    for(int i = 0; i < thirdrow.size(); i++){//loop that puts the letters in string
        std::string result;
        if(lettervalues[thirdrow[i]] == 2){//if value is supposed to be green
            result = GREEN;
        } else if(lettervalues[thirdrow[i]] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else if(lettervalues[thirdrow[i]] == 3) {//if values is truly gray
            result = REALGRAY;
        } else {
            result = GRAY;
        }
        result += "| ";
        result += letters[thirdrow[i]];
        result += " |";
        result += RESET;
        keyboard += result;
    }
    keyboard += "\n";
    keyboard+= "      ";
    for(int i = 0; i < thirdrow.size(); i++){//loop that makes more visually appealing
        std::string result;
        if(lettervalues[thirdrow[i]] == 2){//if value is supposed to be green
            result = GREEN;
        } else if(lettervalues[thirdrow[i]] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else if(lettervalues[thirdrow[i]] == 3) {//if values is truly gray
            result = REALGRAY;
        } else {
            result = GRAY;
        }
        result += "\\---/";
        result += RESET;
        keyboard += result;
    } //end of third row
    
    std::cout << keyboard << std::endl;
}

#endif