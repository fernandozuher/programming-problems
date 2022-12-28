#!/bin/python3

from functools import reduce

class Result:
    
    __setA = []
    __setB = []
    __potentialFactors = []
    __totalFactors = 0

    def __init__(self, setA, setB):

        self.__setA = setA.copy()
        self.__setB = setB.copy()

        self.__findFactors()
        self.printResult()


    def __findFactors(self):

        self.__findNumbersDivisibleBySetA()
        self.__findFactorsOfSetB()
        self.__countFactors()

    
    def __findNumbersDivisibleBySetA(self):

        lastElementOfSetA = self.__setA[-1]

        for potentialFactor in range(lastElementOfSetA, self.__setB[0] + 1, lastElementOfSetA):
            isARealPotentialFactor = True
            for elementA in self.__setA:
                if potentialFactor % elementA:
                    isARealPotentialFactor = False
                    break
                
            if isARealPotentialFactor:
                self.__potentialFactors.append(potentialFactor)
    

    def __findFactorsOfSetB(self):

        for elementB in self.__setB:
            for i, potentialFactor in enumerate(self.__potentialFactors):
                if (potentialFactor and elementB % potentialFactor):
                    self.__potentialFactors[i] = 0


    def __countFactors(self):
        self.__totalFactors = reduce(lambda previousResult, item: (previousResult + 1) if item else previousResult, self.__potentialFactors, 0)


    def printResult(self):
        print(self.__totalFactors)


def readLineAsIntList():
    numbers = list(map(int, input().split()))
    return numbers


def main():
    readLineAsIntList()
    setA = readLineAsIntList()
    setB = readLineAsIntList()

    sort(setA)
    sort(setB)

    result = Result(setA, setB)

if __name__ == "__main__":
    main()