/*
Author: Ethan Cox

Date: 4/2/2021

This program is free software, and can be modified or re-distributed by anyone. It is publicly available at: https://github.com/EthanC2/Scrabble-Move-Calculator/

Program Summary: This program, which consists of three files: a main file, a header file, and a text file, is designed to calculate all the possible plays that
                 you could make in Scrabble given a certain hand, which is provided as a commandline argument. This program is primarily designed as an exercise
                 in maps and iterators. Thus, some non-modern programming practices have been used, such as using iterators instead of ranged-based for loops.
                 If you have any questions or would like to contribute to this project, please contact me at ecox@highpoint.edu.

                 Best regards,
                 Ethan
                 
Compilation Instructions: g++ scrabbleMain.cpp
Execution Instructions:   ./a.out <tileset>

Future plans: In the future, I am planning on adding further input validation, wildcards, and more.

*/
#include <iostream>                                    //for I/O operators
#include <iomanip>                                    //for I/O Manipulation
#include <fstream>                                   //for file operations (reading twl06.txt)
#include <vector>                                   //for creating a vector of wordType objects
#include <map>                                     //for creating a <char, int> mapping of the characters and point values in Scrabble
#include <iterator>                               //in case the map needs to be iterated over
#include "wordType.h"                                  //Custom class 'wordType' describes a class which contains a string (a word) and its point value in Scrabble as an integer
using namespace std;

//Function Prototypes
void validateCmdArgs(const int);           //validates the amount of command line arguments - none is fatal, any more is tolerable
void loadWords(vector<wordType>&);
void displayPlayableWords(wordType);


//Global array 'wordBank' holds all the words from the twl06 wordlist as a 'wordType' object
vector<wordType> wordCatalog;

//Global map that holds the point value in Scrabble for each possible letter
map<char, int> pointDict = { {'a', 1}, {'e', 1}, {'i', 1}, {'l', 1}, {'n', 1}, {'o', 1}, {'r', 1}, {'s', 1}, {'t', 1}, {'u', 1},        //1 point letters
                             {'d', 2}, {'g', 2},                                                                                       //2 point letters
                             {'b', 3}, {'c', 3}, {'m', 3}, {'p', 3},                                                                  //3 point letters
                             {'f', 4}, {'h', 4}, {'v', 4}, {'w', 4}, {'y', 4},                                                       //4 point letters
                             {'k', 5},                                                                                              //5 point letters
                             {'j', 8}, {'x', 8},                                                                                   //8 point letters
                             {'q', 10}, {'z', 10},                                                                                //10 point letters
                             {'?', 0} };                                                                                         //The '?' represents a blank tile, with no point value
                             //end of letter-point map...                                                                               ^ To be implemented in the future...




//Driver code
int main(int argc, char **argv)
{
    //Validate the given input + display warnings/errors
    validateCmdArgs(argc);

    //Load all the wordType objects into the wordCatalog vector
    loadWords(wordCatalog);

    //Create a wordType object from the given hand at the commandline
    wordType yourWord(argv[1]);

    //Iterate over the vector and output playable words and their point value to console
    displayPlayableWords(yourWord);
    
    return 0;
}


//validateCmdArgs()
void validateCmdArgs(const int args)
{
    //Args should equal 2. argv[0] is the executable's name and argv[1] is the first commandline argument
    if(args == 1) {             //Fatal error
        cerr << "Error: no arguments provided. Exiting with status 1." << endl;
        exit(1);
    }
    else if(args > 2) {      //Non-fatal error -- give warning
        cout << "Warning: more than one argument provided -- only the first will be recognized.\n\n";
    }
}

//loadWords()
void loadWords(vector<wordType>& wordCatalog)
{
    //Declare variables
    ifstream inFile;         //read-only file      
    string line;            //string to store the contents

    //Open the input file
    inFile.open("twl06.txt");

    //For every word in the twl06 wordlist, insert it into the array
    while(getline(inFile, line))
    {
        wordCatalog.push_back( wordType(line) );    //insert a 'wordType' object into the array
    }

    //Close the input file
    inFile.close();
}

//displayPlayableWords()
void displayPlayableWords(wordType hand)
{
    //For every word in the vector 'wordCatalog'
    for(int index=0; index < wordCatalog.size(); index++)
    {   
        //Test if the word is playable - if so, print it.
        if( (wordCatalog.at(index)).isPlayable(hand) )
        {
            (wordCatalog.at(index)).print();
            cout << endl;
        }
    }
}
