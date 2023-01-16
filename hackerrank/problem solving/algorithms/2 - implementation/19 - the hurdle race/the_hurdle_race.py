#!/bin/python3

# Source: https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

def main():

    inputLine = readLineAsIntList()
    maximumHeightCanJump = inputLine[1]

    hurdlesHeights = readLineAsIntList()

    result = Result(hurdlesHeights, maximumHeightCanJump)


def readLineAsIntList():

    inputLine = list(map(int, input().split()))
    return inputLine


class Result:

    def __init__(self, hurdlesHeights, maximumHeightCanJump):

        self.__hurdlesHeights = hurdlesHeights.copy()
        self.__maximumHeightCanJump = maximumHeightCanJump
        self.__doses = 0

        self.__hurdleRace()
        self.printResult()


    def __hurdleRace(self):

        highestHurdle = max(self.__hurdlesHeights)
        self.__doses = highestHurdle - self.__maximumHeightCanJump if highestHurdle > self.__maximumHeightCanJump else 0


    def printResult(self):

        print(self.__doses)


if __name__ == "__main__":
    main()
