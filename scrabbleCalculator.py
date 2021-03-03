# Author: Ethan Cox
# Date: 2/28/2021
# Language/Version: Python 3.9
# Filename: scrabbleCalculator.py

# Function: this program uses the wordType object list from file 'getWords.py' to print every possible playable word given a set of tiles, which are provided
# as an argument from console when running the program.

# !!!

# Current Problem: the program assumes that you have an infinite amount of each tile, leading to it outputting words which are clearly not
# playable considering the finite tile set.

# Theoretical Solution: For every word in getWords.wordlist, the program iterates over every character in the word to determine whether or not it is playable.
# If there are any characters that are not in the given hand OR the amount of characters needed exceed the amount of said tile that are in the hand,
# then the word is unplayable. Conversely, if all the characters in the word are in the current hand AND there are enough of each character to play the word,
# then the word is considered playable.

# Attempted Implementation: 

# !!!

# Print format: [point value] [word]

import getWords   # File 'getWords' contains the list of wordType objects
import sys        # sys contains the module for command line arguments

# Use list comprehention to create a list from each character in the provided hand (which is a string)
letters = [char for char in sys.argv[1]]    

# Determine if a given word is playable by comparing every letter in it 
# to the given hand
def playableWord(word, letters):
    for char in word.word:        # For every character in the word
        if char not in letters:   # If the current character is not in the hand, return false
            return False
    return True                   # If all the character are in the hand, return true

def main():
    # Print all words that can be made with the given string
    for word in getWords.wordlist:        # For every word in the wordlist
        if playableWord(word, letters):   # Print the word to console if it is playable
            word.print()

if __name__ == '__main__':
    main()
