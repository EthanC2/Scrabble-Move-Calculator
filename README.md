# Scrabble-Move-Calculator

This C++ project is designed to calculate every possible move in the game Scrabble given a hand of tiles. This project uses the North American-based standard Scrabble dictionary
TWL06, which can be found at https://www.wordgamedictionary.com/twl06/download/twl06.txt. I used the Linux curl command along with commandline I/O re-direction to create the file easily. If you have any questions regarding this project, please contact me at ecox@highpoint.edu.

The file twl06.txt contains all 178,691 legal words from the North American Scrabble tournament. Each word is written entirely in lowercase and has its own line.

getWords.h contains both the declaration and implementation of a class 'wordType', which contains all the necessary information about a word in Scrabble, that being: \
the word itself, the word's total point value, and <char, int> map of the frequency of each character in the word.

Compilation Instructions: g++ scrabbleMain.cpp
Execution Instructions:   ./a.out <tileset>



Here is the process of the program, step by step:

1.  Validate the arguments from the command line, giving a warning or indicator of fatal error if the amount of arguments are improper 
    (0 == fatal, >1 == warning)

2.  Open the file 'twl06.txt' and load all the words in as wordType objects into a vector called 'wordCatalog'.

3.  Transform the tileset given from the commandline into a wordType object.

4.  Compare each word in the list of all words (wordCatalog vector) to the given tileset to determine which words are playable. If a word is playable, the word and its point
    value will be printed to the console in the format 'value  word'.
    
 
 
 The evaluation of which words are playable is one of the more complex parts of the algorithm, so I would like to document my process here:
 
 1. Declare two iterators, one to iterate over the map of the class and the other to iterate over the map of the given hand (tileset)
 
 2. Return false for any word that has a larger map than that of the given hand. Though unintuitive, this makes the algorithm much more efficient as each key is a unique
    character. Thus, if the potential word has more unique characters than there are unique characters in the hand, then there is some letter such that that letter exists
    in the word and not in the hand. This shortcut increases the efficiency of the algorithm by avoiding many unnecessary calculations.
 
 3. Iterate over each character in the potential word. If there is any character in the potential word that is not in the tileset, then the word is not playable. 
    If the character is in the tileset, but the amount of that character in the potential word is more than in the tileset, then the word is not playable; however,
    if the character in the potential word is in the tileset and the amount of that tile is less than or equal to the amount in the tileset, then the word is playable.
 
 4. Print all playable words to console in the format 'point_value  word', followed by an endline.


Best regards,
Ethan Cox
