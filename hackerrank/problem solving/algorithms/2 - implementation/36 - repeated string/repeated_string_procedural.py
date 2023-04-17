# Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

import math

def main():

    INPUT_STRING = input()
    N_CHARACTERS = int(input())

    QUANTITY_OF_A = findQuantityOfAInRepeatedString(INPUT_STRING, N_CHARACTERS)
    print(QUANTITY_OF_A)


def findQuantityOfAInRepeatedString(inputString, nCharacters):

    quantityOfA = findQuantityOfAInString(inputString)
    quantityOfA *= findQuantityOfRepeatedEntireString(nCharacters, len(inputString))
    quantityOfA += findQuantityOfRemainingA(nCharacters, inputString)

    return quantityOfA


def findQuantityOfAInString(inputString):

    quantityOfA = 0

    for character in inputString:
        if character == 'a':
            quantityOfA += 1

    return quantityOfA


def findQuantityOfRepeatedEntireString(nCharacters, sizeString):

    N_STRINGS = math.trunc(nCharacters / sizeString)
    return N_STRINGS


def findQuantityOfRemainingA(nCharacters, inputString):

    N_REMAINING_CHARACTERS_OF_STRING = nCharacters % len(inputString)

    if N_REMAINING_CHARACTERS_OF_STRING == 0:
        return 0

    SUB_STRING = inputString[:N_REMAINING_CHARACTERS_OF_STRING]
    return findQuantityOfAInString(SUB_STRING)


if __name__ == "__main__":
    main()
