#!/bin/python3

# Source: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

def main():

    inputLine1 = readLineAsIntList()
    inputLine2 = readLineAsString()

    result = Result(inputLine1, inputLine2)


def readLineAsIntList():

    inputLine = list(map(int, input().split()))
    return inputLine


def readLineAsString():

    inputLine = input()
    return inputLine


class Result:

    def __init__(self, lettersHeights, word):

        self.__lettersHeights = lettersHeights.copy()
        self.__word = word
        self.__area = 0

        self.__designerPdfViewer()
        self.printResult()


    def __designerPdfViewer(self):

        maxHeight = 0

        for letter in self.__word:
            letterIndex = ord(letter) - ord("a")
            letterHeight = self.__lettersHeights[letterIndex]

            if maxHeight < letterHeight:
                maxHeight = letterHeight

        self.__area = maxHeight * len(self.__word)


    def printResult(self):

        print(self.__area)


if __name__ == "__main__":
    main()
