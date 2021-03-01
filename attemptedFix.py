import getWords 
import sys      

letters = [char for char in sys.argv[1]]    

def playableWord(word, letters):
    remainingLetters = letters      #Edit - create a modifiable copy of the hand   
    
    for char in word.word:        
        if char not in remainingLetters:   #Edit - if the character is not in the remaining hand, return false
            return False
        else:
            remainingLetters.remove(char)  #Edit - remove any used characters from remainingLetters

    return True


for word in getWords.wordlist:        
    if playableWord(word, letters):  
        word.print()
