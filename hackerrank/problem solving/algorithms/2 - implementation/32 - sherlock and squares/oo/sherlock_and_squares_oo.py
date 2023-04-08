# Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import math

def main():

    N_TEST_CASES = int(input())
    output = [None] * N_TEST_CASES

    for i in range(N_TEST_CASES):
        BEGIN, END = readAnArray()
        OBJ = SherlockAndSquares(BEGIN, END)
        output[i] = OBJ.getQuantityOfSquareIntegers()

    printArray(output)


def readAnArray():

    ARRAY = list(map(int, input().split()))
    return ARRAY


def printArray(array):

    print(*array, sep="\n")


class SherlockAndSquares:
    
    def __init__(self, begin, end):

        self.__begin = begin
        self.__end = end
        self.__quantityOfSquareIntegers = 0

        self.__calculateNumberOfSquareIntegersInRange()


    def __calculateNumberOfSquareIntegersInRange(self):

        number = self.__findFirstSquareIntegerFromBeginNumber()
        while self.__isPowerOf2OfNumberLessThanOrEqualToEndNumber(number):
            self.__quantityOfSquareIntegers += 1
            number += 1


    def __findFirstSquareIntegerFromBeginNumber(self):

        SQUARE_ROOT_NUMBER = math.sqrt(self.__begin)
        SQUARE_INTEGER = self.__getSquareIntegerFromNumber(SQUARE_ROOT_NUMBER)
        return SQUARE_INTEGER


    def __getSquareIntegerFromNumber(self, number):

        INTEGER_PART = math.trunc(number)
        return INTEGER_PART if number == INTEGER_PART else INTEGER_PART + 1


    def __isPowerOf2OfNumberLessThanOrEqualToEndNumber(self, number):

        return math.pow(number, 2) <= self.__end


    def getQuantityOfSquareIntegers(self):

        return self.__quantityOfSquareIntegers


if __name__ == "__main__":
    main()
