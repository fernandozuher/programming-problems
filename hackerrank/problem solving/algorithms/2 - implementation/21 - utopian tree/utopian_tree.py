#!/bin/python3

# Source: https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true


def main():

    nTestCases = readLineAsInt()
    nTestCasesCycles = readCycles(nTestCases)
    result = Result(nTestCasesCycles)


def readLineAsInt():

    number = int(input())
    return number


def readCycles(nTestCases):

    nTestCasesCycles = [readLineAsInt() for _ in range(nTestCases)]
    return nTestCasesCycles


class Result:

    def __init__(self, nTestCasesCycles):

        self.__nTestCasesCycles = nTestCasesCycles.copy()
        self.__treesHeights = [None] * len(nTestCasesCycles)

        self.__utopianTree()
        self.printTreesHeights()


    def __utopianTree(self):

        for i in range(len(self.__treesHeights)):
            self.__treesHeights[i] = self.__calculateHeight(self.__nTestCasesCycles[i])


    def __calculateHeight(self, cycles):

        height = 1

        for cycle in range(1, cycles+1):
            height = height * 2 if self.__isCycleHappeningDuringSpring(cycle) else height + 1

        return height


    def __isCycleHappeningDuringSpring(self, cycle):

        return cycle & 1


    def printTreesHeights(self):

        for height in self.__treesHeights:
            print(height)


if __name__ == "__main__":
    main()
