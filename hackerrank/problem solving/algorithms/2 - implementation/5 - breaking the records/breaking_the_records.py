#!/bin/python3

# Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

class Result:
    
    __scores = []
    __breakingMostPointsRecords = 0
    __breakingLeastPointsRecords = 0

    def __init__(self, setA):

        self.__scores = setA.copy()
        self.__breakingMostPointsRecords = 0
        self.__breakingLeastPointsRecords = 0
        self.__breakingRecords()
        self.printResult()


    def __breakingRecords(self):

        mostPoints = self.__scores[0]
        leastPoints = self.__scores[0]

        for score in self.__scores:
            if score > mostPoints:
                mostPoints = score
                self.__breakingMostPointsRecords += 1
            elif score < leastPoints:
                leastPoints = score
                self.__breakingLeastPointsRecords += 1


    def printResult(self):
        print(f"{self.__breakingMostPointsRecords} {self.__breakingLeastPointsRecords}")


def readLineAsIntList():
    numbers = list(map(int, input().split()))
    return numbers


def main():
    readLineAsIntList()
    setA = readLineAsIntList()

    result = Result(setA)

if __name__ == "__main__":
    main()
