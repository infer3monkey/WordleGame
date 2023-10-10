# Summary
This is a project I'm making for school that has some creative flexibility.
The project is a wordle clone, a popular game that can be run in the browser made by New York Times.
In order to run the program you need to type `make` into the terminal when inside the folder and run it
by typing `./app` into the terminal
Once the program is ran it will enter the main menu where it will give you 5 different options.
option one lets you play the game, option two lets you read about how to play the game, and option 5 lets you exit the program.
option three and four will be added soon.
Thank you for looking at my project and hope you enjoy!

# Summary

This is a project I'm making for school that has some creative flexibility.

The project is a wordle clone, a popular game that can be run in the browser made by New York Times.

In order to run the program you need to type `make` into the terminal when inside the folder and run it by typing `./app` into the terminal.

Once the program is ran it will enter the main menu where it will give you 5 different options.

Option one lets you play the game, option two lets you read about how to play the game, and option 5 lets you exit the program. The Option three and four will be added soon.

Thank you for looking at my project and hope you enjoy!

# Troubleshooting

If you run into the following error:

```
error: non-aggregate type 'std::vector<int>' cannot be initialized with an initializer list
```

One way to fix it is by compiling using the `c++11` option as in:

```
g++ -std=c++11 main.cpp -g -I. -o app
```