# Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import math

def main():

    N_TEST_CASES = int(input())
    output = [None] * N_TEST_CASES

    for i in range(N_TEST_CASES):
        BEGIN, END = readAnArray()
        output[i] = calculateNumberOfSquareIntegersInRange(BEGIN, END)

    printArray(output)


def readAnArray():

    ARRAY = list(map(int, input().split()))
    return ARRAY


def calculateNumberOfSquareIntegersInRange(begin, end):

    squares = 0
    number = findFirstSquareIntegerFromNumber(begin)
    while isPowerOf2OfNumberLessThanOrEqualToLimit(number, end):
        squares += 1
        number += 1
    return squares


def findFirstSquareIntegerFromNumber(number):

    SQUARE_ROOT_NUMBER = math.sqrt(number)
    SQUARE_INTEGER = getSquareIntegerFromNumber(SQUARE_ROOT_NUMBER)
    return SQUARE_INTEGER


def getSquareIntegerFromNumber(number):

    INTEGER_PART = math.trunc(number)
    return INTEGER_PART if number == INTEGER_PART else INTEGER_PART + 1


def isPowerOf2OfNumberLessThanOrEqualToLimit(number, limit):

    return math.pow(number, 2) <= limit


def printArray(array):

    print(*array, sep="\n")


if __name__ == "__main__":
    main()
