from domain import Sentence 
import random
import copy
class ServiceError(Exception):
    pass

class Service(object):
    """description of class"""
    def __init__(self):
        self._originalSentence = []
        self._sentence = []
        self._stack =[]
        self._undoAvaillable = False

    def getPrintableSentence(self):
        string =''
        for word in self._sentence:
            wordString = ''.join(word)
            string += str(wordString)+' '
        return string

    def _read_random_sentence(self,file):
        '''reads a rando msentence from the input file 'file'
        and converts it into a list of words eaxh word a list of chars'''
        with open(file,"r") as readFile:
            lines = readFile.readlines()
            number = random.randint(0,len(lines)-1)
            lines[number]=lines[number].strip()
            self._originalSentence = self._sentence = lines[number].split()
            for i in range(len(self._sentence)):
                self._sentence[i]=list(self._sentence[i])

            #print(self._sentence)
            self._originalSentence = copy.deepcopy(self._sentence)

            
    def _compute_score(self):
        '''computes the number of letters in all words'''
        score = 0
        for word in self._sentence:
            score += len(word)
        return score

    def _won(self):
        '''checks if the original unshuffled sentence is equal to the
        current sentence'''
        for i in range(len(self._sentence)):
            if self._sentence[i] != self._originalSentence[i]:
                return False
        #print("WWWWWWWWWWWWWWWWWWWWWWWW")
        return True

        
    def _shuffle_letters(self):
        '''shuflle the letters  from which word with one another'''
        for i in range(len(self._sentence)):
            for j in range(len(self._sentence[i])//2):
                listLetterPos = list(range(1,len(self._sentence[i])-1))
                randomLetter1 = random.choice(listLetterPos)
                randomLetter2 = random.choice(listLetterPos)
               # word = list(word)
                aux= self._sentence[i][randomLetter1]
                self._sentence[i][randomLetter1] = self._sentence[i][randomLetter2]
                self._sentence[i][randomLetter2] = aux
                
            

    def _swap_letters(self,word1,letterPos1,word2,letterPos2):
        '''swaps two letters from the words on pos word1 and word2 at the pos
        letterPos1 respectively letterPos2
        also reenbles a n undo action '''
        try:
            aux=self._sentence[word1][letterPos1]
            self._sentence[word1][letterPos1] = self._sentence[word2][letterPos2]
            self._sentence[word2][letterPos2] = aux
            self._stack.append([word1,letterPos1, word2, letterPos2])
            self._undoAvaillable = True
        except Exception as ex:
            raise ServiceError("Invalid positions!")

    def _undo_last_swap(self):
        '''reverses the last swap action vy swapping again if possible
        otherwise throws exception'''
        if self._undoAvaillable == False:
            raise ServiceError("Undo not available")
        arguments = self._stack.pop()
        self._swap_letters(arguments[2], arguments[3], arguments[0], arguments[1])

        self._undoAvaillable = False
