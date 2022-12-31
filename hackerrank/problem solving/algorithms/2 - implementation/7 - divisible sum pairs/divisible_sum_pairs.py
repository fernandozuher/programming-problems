#!/bin/python3

# Source: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main():

    input1 = readLineAsIntList()
    k = input1[1]
    numbers = readLineAsIntList()

    numbers.sort()    

    result = Result(numbers, k)


def readLineAsIntList():

    numbers = list(map(int, input().split()))
    return numbers


class Result:

    def __init__(self, numbers, k):
        
        self.__numbers = numbers.copy()
        self.__k = k
        self.__nDivisibleSumPairs = 0

        self.__divisibleSumPairs()
        self.printResult()


    def __divisibleSumPairs(self):

        for i in range(0, len(self.__numbers) - 1):
            for j in range(i + 1, len(self.__numbers)):
                if self.__numbers[i] <= self.__numbers[j] and (self.__numbers[i] + self.__numbers[j]) % self.__k == 0:
                    self.__nDivisibleSumPairs += 1


    def printResult(self):
        
        print(self.__nDivisibleSumPairs)


if __name__ == "__main__":
    main()
