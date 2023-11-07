#ifndef WORDLE_FUNCTIONS_H
#define WORDLE_FUNCTIONS_H

#include <string>
#define GREEN "\033[32m"
#define GRAY "\033[37m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>

int contains (char letter, std::string str){//if letter is in string returns index it was found at otherwise returns -1
    for (int i = 0; i < str.length();i++){
        if (letter == str[i]){
            return i;
        }
    }
    return -1;
}

std::string mainmenu(){//creates a string with the main menu
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
    //std::cout << str; for later
    return str;
}

std::string statisticssummary(){//creates a string with the statistic summary page
    std::string str;
    //grab values from file
    std::ifstream file2;
    std::vector<std::string> wordlist;
    std::vector<int> attemptnumlist;
    std::vector<int> winlist;
    
    int count = 1; //keeping track of whether the data is the solution, # of attempts, or whether or not you won
    int timesplayed = 0;
    int averageattempts = 0;
    double winpercentage = 0;
    int currentstreak = 0;
    int longeststreak = 0;
    file2.open("statistics.txt", std::ios::in);
    if (file2.is_open()){
        std::string word;
        while(file2 >> word){
            if(count == 1){//word
                wordlist.push_back(word);
                count++;
            } else if (count == 2){//# of attempts
                attemptnumlist.push_back(stoi(word));
                averageattempts+= stoi(word);
                count++;
            } else { //win or loss
                winlist.push_back(stoi(word));
                if (stoi(word) == 1){ //won
                    currentstreak++;
                    if (currentstreak > longeststreak){
                    longeststreak = currentstreak;
                    }
                    winpercentage += 1;
                } else { //lost
                    currentstreak = 0;
                }
                count = 1;
                timesplayed++;
            }
        }
         file2.close();
    }
    averageattempts = averageattempts/(timesplayed);
    winpercentage = winpercentage/(timesplayed);
    
    str += "================================\n";
    str += "       Statistics Summary       \n";
    str += "================================\n";
    str += "Times Played:                  " + std::to_string(timesplayed);
    str += "\nAverage Attempts:              " + std::to_string(averageattempts);
    str += "\nWin Percentage:                " + std::to_string(winpercentage);
    str += "\nCurrent Streak:                " + std::to_string(currentstreak);
    str += "\nLongest Streak:                " + std::to_string(longeststreak);
    str += "\n";
    str += "--------------------------------\n";
    str += "Word         Attempts        Win\n";
    str += "--------------------------------\n";
    //grab values from file
    return str;
}

void updatingstatistics(std::string solution, bool won, int attempts){
    std::ofstream file;
    file.open("statistics.txt", std::ios::app);//opening file for appending values
    if (file.is_open()){
        file << solution << " " << attempts << " " << won << "\n";
    }
    file.close();
}

void resetstatistics(){
    std::ofstream file;
    file.open("statistics.txt", std::ios::out);
    file.close();
}

bool containsList(std::string lookingFor, std::vector<std::string> list){//returns whether or not a specific string is in a list of strings
    if(std::find(list.begin(), list.end(), lookingFor) != list.end()) {
        return true;
    } else {
        return false;
    }
}

std::string chooseRandom(std::vector<std::string> words){//chooses a random index in given vector
    srand((unsigned) time(NULL));
    int random = (rand() % words.size());
    return words[random];
}

std::string howtoplaymenu(){
    std::string howtoplay;
    howtoplay += "===============================\n";
    howtoplay += "          HOW TO PLAY          \n";
    howtoplay += "===============================\n";
    howtoplay += "Guess the Wordle in 6 tries\n\n\n";
    howtoplay += "How To Play:\n";
    howtoplay += "- Each guess must be a valid five letter word\n";
    howtoplay += "- The color of the letters will change to help\nguide you to victory\n\n";
    howtoplay += GREEN "/---\\" RESET "/---\\/---\\/---\\/---\\\n";//this works optimize stuff
    howtoplay += GREEN"| H |" RESET "| E || L || L || O |\n";
    howtoplay += GREEN "\\---/" RESET "\\---/\\---/\\---/\\---/\n";
    howtoplay += BOLD "H " RESET "is in the word and the correct spot\n";
    howtoplay += YELLOW "/---\\" RESET "/---\\/---\\/---\\/---\\\n";
    howtoplay += YELLOW"| W |" RESET "| O || R || L || D |\n";
    howtoplay += YELLOW "\\---/" RESET "\\---/\\---/\\---/\\---/\n";
    howtoplay += BOLD "W " RESET "is in the word but not the correct spot\n";
    howtoplay += GRAY "/---\\" RESET "/---\\/---\\/---\\/---\\\n";
    howtoplay += GRAY "| C |" RESET "| L || O || N || E |\n";
    howtoplay += GRAY "\\---/" RESET "\\---/\\---/\\---/\\---/\n";
    howtoplay += BOLD "C " RESET "is not in the word or the correct spot\n";
    howtoplay += "\n\nPress [enter] to continue";
    return howtoplay;
}

std::string solutiongeneration(){//choose a random word from words.txt
    std::vector<std::string> wordlist;
    std::ifstream file2;
    file2.open("words.txt", std::ios::in);

    if (file2.is_open()){
        std::string word;
        while(file2 >> word){
            wordlist.push_back(word);
        }
        file2.close();
    }

    return chooseRandom(wordlist);//randomly generated solution
}

std::vector<std::string> listgeneration(){//generates valid list from words.txt and allowed.txt
    std::vector<std::string> wordlist;
    std::ifstream file2;
    file2.open("words.txt", std::ios::in);

    if (file2.is_open()){
        std::string word;
        while(file2 >> word){
            wordlist.push_back(word);
        }
        file2.close();
    }

    std::ifstream file;
    file.open("allowed.txt", std::ios::in);

    if (file.is_open()){
        std::string word;
        while(file >> word){
            wordlist.push_back(word);
        }
        file.close();
    }
    
    return wordlist;
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
        result += "/---\\";
        result += RESET;
        answer += result;
    }
    answer += "\n";

    for(int i = 0; i < 5; i++){//loop that puts the letters in string
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
        result += "\\---/";
        result += RESET;
        answer += result;
    }
    return answer;
}

#endif