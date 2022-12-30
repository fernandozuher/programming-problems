#!/bin/python3

# Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

def main():

    readLineAsIntList()
    chocolateSquares = readLineAsIntList()
    dayMonth = readLineAsIntList()

    result = Result(chocolateSquares, dayMonth)


def readLineAsIntList():

    numbers = list(map(int, input().split()))
    return numbers


class Result:

    def __init__(self, chocolateSquares, dayMonth):
        
        self.__chocolateSquares = chocolateSquares.copy()
        self.__day = dayMonth[0]
        self.__month = dayMonth[1]
        self.__waysBarCanBeDivided = 0

        self.__birthday()
        self.printResult()


    def __birthday(self):

        for i in range (0, len(self.__chocolateSquares) - self.__month + 1):
            sum = 0
            for j in range(i, i + self.__month):
                sum += self.__chocolateSquares[j]
            if sum == self.__day:
                self.__waysBarCanBeDivided += 1


    def printResult(self):
        
        print(self.__waysBarCanBeDivided)


if __name__ == "__main__":
    main()
