#!/bin/python3

# Source: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

def main():

    inputLine = readLineAsIntList()
    n = inputLine[0]

    inputLines = readCatsAndMousePositionsLines(n)

    result = Result(inputLines)


def readLineAsIntList():

    inputLine = list(map(int, input().split()))
    return inputLine


def readCatsAndMousePositionsLines(n):

    catsAndMousePositionsLines = [None] * n

    for i in range(n):
        catsAndMousePositionsLines[i] = readLineAsIntList()

    return catsAndMousePositionsLines


class Result:

    def __init__(self, catsAndMousePositionsLines):
        
        self.__catsAndMousePositionsLines = catsAndMousePositionsLines.copy()
        self.__result = []

        self.__catAndMouse()
        self.printResult()


    def __catAndMouse(self):

        for catsAndMousePositions in self.__catsAndMousePositionsLines:
                self.__findNearestCatOrNot(catsAndMousePositions)


    def __findNearestCatOrNot(self, catsAndMousePositions):

        catAPosition = catsAndMousePositions[0]
        catBPosition = catsAndMousePositions[1]
        mousePosition = catsAndMousePositions[2]

        catAPositionDifference = abs(catAPosition - mousePosition)
        catBPositionDifference = abs(catBPosition - mousePosition)

        self.__setStringResult(catAPositionDifference, catBPositionDifference)


    def __setStringResult(self, catAPositionDifference, catBPositionDifference):

        if catAPositionDifference < catBPositionDifference:
            self.__result.append("Cat A")
        elif catAPositionDifference > catBPositionDifference:
            self.__result.append("Cat B")
        else:
            self.__result.append("Mouse C")


    def printResult(self):
        
        for result in self.__result:
            print(result)


if __name__ == "__main__":
    main()
