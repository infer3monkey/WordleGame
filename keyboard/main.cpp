#include <iostream>
#include "keyboard.h"
#include <unistd.h> //for sleep function
using namespace std;
int main(int argc, char* argv[]) {
    while(true){
        sleep(1);//sleeps for 1 second
        updatekeyboard();
    }
    return 0;
}