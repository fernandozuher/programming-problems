#!/bin/python3

# Source: https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

def main():

    readLineAsIntList()
    birdSightings = readLineAsIntList()

    birdSightings.sort()

    result = Result(birdSightings)


def readLineAsIntList():

    numbers = list(map(int, input().split()))
    return numbers


class Result:

    def __init__(self, birdSightings):
    
        self.__birdSightings = birdSightings.copy()
        self.__mostSpottedBird = None

        self.__migratoryBirds()
        self.printResult()


    def __migratoryBirds(self):
    
            self.__mostSpottedBird = self.__birdSightings[0]
            countMostSpottedBird = 1
            tempCountMostSpottedBird = 1

            n = len(self.__birdSightings)
            for i in range(1, n):

                if self.__birdSightings[i] == self.__birdSightings[i - 1]:
                    tempCountMostSpottedBird += 1
                
                elif tempCountMostSpottedBird > countMostSpottedBird:
                    self.__mostSpottedBird = self.__birdSightings[i - 1]
                    countMostSpottedBird = tempCountMostSpottedBird
                    tempCountMostSpottedBird = 1
                
            if tempCountMostSpottedBird > countMostSpottedBird:
                self.__mostSpottedBird = self.__birdSightings[n - 1]
        

    def printResult(self):
        
        print(self.__mostSpottedBird)


if __name__ == "__main__":
    main()
