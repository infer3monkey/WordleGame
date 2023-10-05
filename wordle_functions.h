#ifndef WORDLE_FUNCTIONS_H
#define WORDLE_FUNCTIONS_H

#define GREEN "\033[42;30m"
#define GRAY "\033[47;30m"
#define YELLOW "\033[43;30m"
#define RESET "\033[0m"

#include<vector>
#include<iostream>
#include<algorithm>

int contains (char letter, std::string str){
    for (int i = 0; i < str.length();i++){
        if (letter == str[i]){
            return i;
        }
    }
    return -1;
}

std::string mainmenu(){
    std::string str;
    str += "===============================\n";
    str += "       Welcome to Wordle       \n";
    str += "===============================\n";
    str += "\n";
    str += "\n";
    str += "1. Play Wordle\n";
    str += "2. How to Play\n";
    str += "3. Statistics Summary\n";
    str += "4. Reset Statistics\n";
    str += "5. Exit\n";
    str += "\n";
    str += "\n";
    str += "Select a number:";

    return str;
}

bool containsList(std::string lookingFor, std::vector<std::string> list){
    if(std::find(list.begin(), list.end(), lookingFor) != list.end()) {
        return true;
    } else {
        return false;
    }
}

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

    for(int i = 0; i < 5; i++){//loop that makes more visually appealing
        std::string result;
        if(list[i] == 2){//if value is supposed to be green
            result = GREEN;
        } else if(list[i] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else {
            result = GRAY;
        }
        result += " --- ";
        result += RESET;
        answer += result;
    }
    answer += "\n";

    for(int i = 0; i < 5; i++){//loop that creates the string
        std::string result;
        if(list[i] == 2){//if value is supposed to be green
            result = GREEN;
            
        } else if(list[i] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else {
            result = GRAY;
        }
        result += "| ";
        result += attempt[i];
        result += " |";
        result += RESET;
        answer += result;
    }
    answer += "\n";

    for(int i = 0; i < 5; i++){//loop that makes more visually appealing
        std::string result;
        if(list[i] == 2){//if value is supposed to be green
            result = GREEN;
            
        } else if(list[i] == 1){//if value is supposed to be yellow
            result = YELLOW;
        } else {
            result = GRAY;
        }
        result += " --- ";
        result += RESET;
        answer += result;
    }
    return answer;
}

#endif