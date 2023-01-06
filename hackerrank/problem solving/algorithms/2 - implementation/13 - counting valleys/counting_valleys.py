#!/bin/python3

# Source: https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

def main():

    readLineAsIntList()
    steps = readLineAsString()

    result = Result(steps)


def readLineAsIntList():

    inputLine = list(map(int, input().split()))
    return inputLine


def readLineAsString():

    inputLine = input()
    return inputLine


class Result:

    def __init__(self, steps):
        
        self.__steps = steps
        self.__traversedValleys = 0

        self.__countingValleys()
        self.printResult()


    def __countingValleys(self):

        currentAltitude = 0

        for step in self.__steps:
            wasTravessingAValley = currentAltitude < 0
            currentAltitude += -1 if step == 'D' else 1
            
            if self.__isInSeaLevelFromValley(wasTravessingAValley, currentAltitude):
                self.__traversedValleys += 1


    def __isInSeaLevelFromValley(self, wasTravessingAValley, currentAltitude):
        
        return wasTravessingAValley and not currentAltitude


    def printResult(self):
        
        print(self.__traversedValleys)


if __name__ == "__main__":
    main()
