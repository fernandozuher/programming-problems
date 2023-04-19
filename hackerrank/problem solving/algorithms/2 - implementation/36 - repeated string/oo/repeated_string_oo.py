# Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

import math

def main():

    INPUT_STRING = input()
    N_CHARACTERS = int(input())

    OBJ = RepeatedString(INPUT_STRING, N_CHARACTERS)
    QUANTITY_OF_A = OBJ.getQuantityOfA()
    print(QUANTITY_OF_A)


class RepeatedString:

    def __init__(self, inputString, nCharacters):

        self.__inputString = inputString
        self.__nCharacters = nCharacters
        self.__quantityOfA = 0

        self.__findQuantityOfAInRepeatedString()


    def __findQuantityOfAInRepeatedString(self):

        self.__quantityOfA = self.__findQuantityOfAInString(self.__inputString)
        self.__quantityOfA *= self.__findQuantityOfRepeatedEntireString()
        self.__quantityOfA += self.__findQuantityOfRemainingA()


    def __findQuantityOfAInString(self, inputString):

        quantityOfA = 0

        for character in inputString:
            if character == 'a':
                quantityOfA += 1

        return quantityOfA


    def __findQuantityOfRepeatedEntireString(self):

        N_STRINGS = math.trunc(self.__nCharacters / len(self.__inputString))
        return N_STRINGS


    def __findQuantityOfRemainingA(self):

        N_REMAINING_CHARACTERS_OF_STRING = self.__nCharacters % len(self.__inputString)

        if N_REMAINING_CHARACTERS_OF_STRING == 0:
            return 0

        SUB_STRING = self.__inputString[:N_REMAINING_CHARACTERS_OF_STRING]
        return self.__findQuantityOfAInString(SUB_STRING)


    def getQuantityOfA(self):

        return self.__quantityOfA


if __name__ == "__main__":
    main()
