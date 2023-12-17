# Summary

This is a project I made for school

The project is a wordle clone, a popular game that can be run in the browser made by New York Times.

In order to run the program you need to have two separate terminals open. type in `cd/keyboard'` in one and `cd/wordlegame` in the other

Then type `./app` in both of them to run it

The keyboard file will run infinitely unless stopped by using `ctrl + c` to force quit it

Once the wordlegame program is ran it will enter the main menu where it will give you 5 different options.

Option one lets you play the game, option two lets you read about how to play the game

Option three lets you see your statistics, Option four lets you reset your statistics, and Option five lets you exit

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