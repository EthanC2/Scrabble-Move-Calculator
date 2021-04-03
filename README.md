# Scrabble-Move-Calculator

This C++ project is designed to calculate every possible move in the game Scrabble given a hand of tiles. This project uses the North American-based standard Scrabble dictionary TWL06. 

The file twl06.txt contains all 178,691 legal words from the North American Scrabble tournament. Each word is written entirely in lowercase and has its own line.

getWords.h takes each line (word) from twl06.txt and formats it, converting it to type 'wordType' before adding it to the list of words. The 'wordType' class holds a word and its point value in Scrabble, along with a constructor, a method to determine the point value, and a print function. The print function prints the object in the format of 
"[point value]  [word]" -- this is so the words can be sorted by point value with the Linux 'sort -n' command.

scrabbleCalculator.py takes the wordlist (the list of wordType objects) and determines whether or not they are playable given a hand of tiles, which is provided as a command line argument. Playability is determined by whether or not you have all the letters necessary to play the word. If the word is playable, then it is output to console along with the point value in front of it using the wordType print() method.

Currently, there is a problem with scrabbleCalculator.py's method of assessing playability, as it does not check whether or not you have enough of each letter to play the word, which would be to assume that you have an infinite amount of each tile. Though that would be useful in other contexts, it is detrimental here. attemptFix.py hopes to correct this issue by creating a modifiable copy of your hand and removing a letter from the copy each time you use said letter. This way, you do not use more letters than you have. In its current state, attemptedFix.py does not fix this error, as it does not print out anything at all. It seems that function playableWord() always returns false, even though there clearly are playable words.

Thanks for looking over this - I appreciate it :)
