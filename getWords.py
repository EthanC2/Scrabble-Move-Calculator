# Author: Ethan Cox
# Date: 2/28/2021
# Language/Version: Python 3.9
# Filename: getWords.py

# Function: this file creates a list of wordType objects (an object with a word and the point value of the word according to Scrabble's scoring system)
# from a the official TWLO6 Scrabble tournament official wordlist (all 178,691 words), which are then used in scrabbleCalculator.py to calculate all the possible playable words
# given a certain set of tiles. In addition to printing every playable word to console, it also list the point value in front of it. 

# Print format: [point value] [word]

# Class wordType
class wordType(object):
    
    # Method 'findPointValue' iterates of the characters in a word and determines its point value, returning the total to __init__, which assigns it to self.points
    def findPointValue(self, word):

        pointValue = 0    #initial point value

        # Dictionary of letter-to-point values in Scrabble
        pointValueDictionary = { 'a':1, 'e':1, 'i':1, 'l':1, 'n':1, 'o':1, 'r':1, 's':1, 't':1, 'u':1, 'd':2, 'g':2, 'b':3, 'c':3, 'm':3, 'p':3, 'f':4, 'h':4, 'v':4, 'w':4, 'y':4, 'k':5, 'j':8, 'x':8, 'q':10, 'z':10 }

        # Iterate over each character in a word, adding that letter's individual value to the total
        for char in word:
            pointValue += pointValueDictionary[char]
        return pointValue           #Return the total amount of points to the constructor

    # Method 'print' prints out the object's word and its point value on the same line
    # Format: [point value] [word]
    def print(self):
        print(self.points, self.word, sep=" ")

    # Constructor  __init__ assigns the word to the data member 'word' and calculates the amount of points it is worth, storing it in data member 'points'
    def __init__(self, word):
        self.word = word
        self.points = self.findPointValue(word)

# Open file 'twl06' in read mode, which contains the full list of legal words in Scrabble for the North American tournaments
# File format: every line contains only one word, which is written entirely in lowercase
f = open("test.txt", "r")
#f = open("twl06.txt", "r")

# Make an empty list
wordlist = list()

# For every line in the file, take the word on that line and convert it into a wordType object, then appending it to the list of total words, 'wordlist'
for line in f:
    line = line.strip()       #Strip whitespace and the newline character
    wordlist.append(wordType(line))   #Append the stripped word to the list as a wordType object

# Close the twl06.txt
f.close()
