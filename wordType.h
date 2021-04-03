/*
Author: Ethan Cox

Date: 4/2/2021

This program is free software, and can be modified or re-distributed by anyone. It is publicly available at: https://github.com/EthanC2/Scrabble-Move-Calculator/

Program Summary: This header file serves as both the declaration and implementation file for a class 'wordType', which
                 contains all the necessary information about a word in Scrabble, that being: the word itself, the word's
                 total point value, and <char, int> map of the frequency of each character 
                 Please see the main program (scrabbleMain.cpp) for the driver code and a fuller description of the project.

*/

#ifndef WORD_TYPE          //Prevent multiple declarations
#define WORD_TYPE

#include <iostream>                 
#include <string>        
#include <map>            
#include <iterator>
using namespace std;

//map of all character's point values is in main -- including an identical it in ALL 179k word objects would take up too much memory and is pointless.
extern map<char, int> pointDict;

//template <class Type>
class wordType
{
    private:
         //Data members
        //=============
        string word;                //The word itself
        int value;                 //The point value of the word
        map<char, int> reqChar;   //req(uired) char(acters) -- a map of the frequency of each character in the word -- used to determine if the word is playable

          //Methods
         //========

        //findPointValue()
        void findPointValue(string word)            //finds the point value of a word using the pointDict(ionary) listed in the main program (scrabbleMain.cpp)
        {
            for(int i = 0; i < word.length(); ++i)        //iterate over the string
            {
                value += pointDict[word[i]];            //adding the point value of each character
            } 
        }

         //getCharFreq()
        //This code was adopted from a GeeksForGeeks article by hrishikeshkonderu: https://www.geeksforgeeks.org/frequency-of-each-character-in-a-string-using-unordered_map-in-c
        void getCharFreq() 
        {
            //For every character in the string 'word'
            for(int index=0; index < word.size(); index++)
            {   
                //If the character is not in the map
                if(reqChar.find(word[index]) == reqChar.end())
                {
                    reqChar.insert(pair<char, int>(word[index], 1));   //create an instance of that character in the map and set its value to 1
                }
                else  //otherwise
                {
                    reqChar[word[index]]++;    //increment the counter for that character
                }
            }
        }


    public:
        wordType();                                   //Default constructor -- needed to create a vector of objects
        wordType(string str);                        //Parameterized constructor -- for actually creating objects
        string getWord() const;                     //Returns the word
        int getValue() const;                      //Returns the point value
        map<char, int> getMap() const;            //Return a the map to main
        void print() const;                      //Prints '<value> <word>'
        void printMap();   //for debugging.
        bool isPlayable(const wordType);  //Compares the characters in the given hand to the wordType object
};


//Default constructor
wordType::wordType()
{
    word = "";
    value = 0;
}

//Parameterized Constructor
wordType::wordType(string str)
{
    word = str;                 //Record the word
    value = 0;                 //Declare a base point value
    findPointValue(str);      //Determine the point value of the word
    getCharFreq();           //Determine the frequency of each character in the word
}

//getWord()
string wordType::getWord() const
{
    return word;
}

//getValue
int wordType::getValue() const
{
    return value;
}

//getMap()
map<char, int> wordType::getMap() const            //Return a the map to main
{
    return reqChar;
}

//print()
void wordType::print() const
{
    cout << value << " " << word;
}

 //isPlayable()
//Method isPlayable() determines if a word is playable by evaluating comparing the two words' maps
bool wordType::isPlayable(const wordType playerWordObj)
{
    //Iterators for the comparision of values
    map<char, int>::iterator itrOne;
    map<char, int>::iterator itrTwo;
    map<char, int> playerHandMap = playerWordObj.getMap();    //Cannot call methods on playerHand.getMap() directly as it results in a seg. fault.

    //If not equal, return false
    if(reqChar.size() > playerHandMap.size())          //since no two keys can be the same, if the size of the lists are not equal, then it
        return false;                                         //is necessarily true that there is at least one item in the list that is not in the other

    //Compare the frequency of each character in the player's hand to the potentially playable word
    for(itrOne = reqChar.begin(), itrTwo = playerHandMap.begin(); itrOne != reqChar.end(), itrTwo != playerHandMap.end(); itrOne++, itrTwo++)
    {//                        initialization              ^                test expression                   ^  update statement
        
        //If the key from the required characters is not in the player's hand, return false
        if(playerHandMap.find(itrOne->first) == playerHandMap.end())
        {
            return false;
        }
        else
        {   //If the amount of characters needed to spell the word is more than in the player's hand, return false
            if(reqChar[itrOne->first] > playerHandMap[itrOne->first]) 
            {
                return false;
            }
        }
        //cout << '\t' << itrOne->first << '\t' << itrOne->second << "\t\t" << itrTwo->first << '\t' << itrTwo->second << '\n';
    }

    //If all conditions are met, return true
    return true;
}



//printMap()
void wordType::printMap() 
{   
    map<char, int>::iterator itr;   //declare an iterator
    
    cout << "\tKEY\tELEMENT\n";   //header
    for(itr = reqChar.begin(); itr != reqChar.end(); itr++)   //loop over the map, printing 'key    value'
    {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
}

#endif
