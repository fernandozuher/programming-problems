#!/bin/python3

# Source: https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

def main():

    inputLine = readLineAsIntList()
    budget = inputLine[0]
    keyboardCosts = readLineAsIntList()
    usbDriveCosts = readLineAsIntList()

    keyboardCosts.sort()
    usbDriveCosts.sort()

    result = Result(keyboardCosts, usbDriveCosts, budget)


def readLineAsIntList():

    inputLine = list(map(int, input().split()))
    return inputLine


class Result:

    def __init__(self, keyboardCosts, usbDriveCosts, budget):

        self.__keyboardCosts = keyboardCosts.copy()
        self.__usbDriveCosts = usbDriveCosts.copy()
        self.__budget = budget
        self.__canBeSpent = 0

        self.__getMoneySpent()
        self.printResult()


    def __getMoneySpent(self):

        for i in range(len(self.__keyboardCosts)):

            if self.__isNextCostEqualToCurrentOne(self.__keyboardCosts, i):
                continue

            for j in range(len(self.__usbDriveCosts)):

                if self.__isNextCostEqualToCurrentOne(self.__usbDriveCosts, j):
                    continue

                sum = self.__keyboardCosts[i] + self.__usbDriveCosts[j]

                if self.__isSumInsideBudget(sum):
                    self.__canBeSpent = self.__updateCost(sum)
                else:
                    break

        self.__canBeSpent = self.__canBeSpent if self.__canBeSpent else -1


    def __isNextCostEqualToCurrentOne(self, deviceCosts, currentIndex):

        return currentIndex < len(deviceCosts) - 1 and deviceCosts[currentIndex] == deviceCosts[currentIndex + 1]


    def __isSumInsideBudget(self, sum):

        return sum <= self.__budget


    def __updateCost(self, sum):

        return max(sum, self.__canBeSpent)


    def printResult(self):

        print(self.__canBeSpent)


if __name__ == "__main__":
    main()
