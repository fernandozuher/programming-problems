#!/bin/python3

# Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

def main():

    inputLine = readLineAsIntList()
    nTestCases = inputLine[0]
    results = [None] * nTestCases

    for i in range(len(results)):
        angryProfessor = AngryProfessor()
        results[i] = angryProfessor.getCancelledClass()

    for result in results:
        print("YES" if result else "NO")


def readLineAsIntList():

    inputLine = list(map(int, input().split()))
    return inputLine


class AngryProfessor:

    def __init__(self):

        inputLine = readLineAsIntList()
        self.__cancellationThreshold = inputLine[1]
        self.__studentsArrivalTime = readLineAsIntList()

        self.__angryProfessor()


    def __angryProfessor(self):

        self.__cancelledClass = self.__countEarlyArrivalTime() < self.__cancellationThreshold


    def __countEarlyArrivalTime(self):

        earlyArrivalTimeCount = 0

        for studentArrivalTime in self.__studentsArrivalTime:
            if studentArrivalTime <= 0:
                earlyArrivalTimeCount += 1

        return earlyArrivalTimeCount


    def getCancelledClass(self):

        return self.__cancelledClass


if __name__ == "__main__":
    main()
