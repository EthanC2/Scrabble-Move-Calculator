# Scrabble-Move-Calculator

This C++ project is designed to calculate every possible move in the game Scrabble given a hand of tiles. This project uses the North American-based standard Scrabble dictionary
TWL06, which can be found at https://www.wordgamedictionary.com/twl06/download/twl06.txt. I used the Linux curl command along with commandline I/O re-direction to create the file 
easily.

The file twl06.txt contains all 178,691 legal words from the North American Scrabble tournament. Each word is written entirely in lowercase and has its own line.

getWords.h contains both the declaration and implementation of a class 'wordType', which contains all the necessary information about a word in Scrabble, that being: \
the word itself, the word's total point value, and <char, int> map of the frequency of each character in the word.

Compilation Instructions: g++ scrabbleMain.cpp
Execution Instructions:   ./a.out <tileset>

Here is the process of the program, step by step:

1.  Validate the arguments from the command line, giving a warning or indicator of fatal error if the amount of arguments are improper (0 == fatal, >1 == warning)

2.  Open the file 'twl06.txt' and load all the words in as wordType objects into a vector called 'wordCatalog'.

3.  Transform the tileset given from the commandline into a wordType object.

4.  Compare each word in the list of all words (wordCatalog vector) to the given tileset to determine which words are playable. If a word is playable, the word and its point
    value will be printed to the console in the format 'value  word'.
    
 
 
 The evaluation of which words are playable is one of the more complex parts of the algorithm, so I would like to document my process here:
 1. Declare two iterators, one to iterate over 
