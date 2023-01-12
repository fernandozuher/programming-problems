#!/bin/python3

# Source: https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

def main():

    readLineAsIntList()

    numbers = readLineAsIntList()
    numbers.sort()

    result = Result(numbers)


def readLineAsIntList():

    inputLine = list(map(int, input().split()))
    return inputLine


class Result:

    def __init__(self, numbers):

        self.__numbers = numbers.copy()
        self.__subarrayBiggestSize = 1

        self.__pickingNumbers()
        self.printResult()


    def __pickingNumbers(self):

        firstReferenceNumberIndex = 0
        secondReferenceNumberIndex = 0
        subarrayCurrentSize = 1

        for i in range(1, len(self.__numbers)):
            difference = self.__numbers[i] - self.__numbers[firstReferenceNumberIndex]

            match difference:
                case 0:
                    subarrayCurrentSize += 1

                case 1:
                    subarrayCurrentSize += 1
                    if self.__numbers[secondReferenceNumberIndex] != self.__numbers[i]:
                        secondReferenceNumberIndex = i

                case _:
                    self.__subarrayBiggestSize = self.__updateSubarrayBiggestSize(subarrayCurrentSize)
                    update = self.__updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i, secondReferenceNumberIndex)

                    firstReferenceNumberIndex = update[0]
                    secondReferenceNumberIndex = i
                    subarrayCurrentSize = update[1]

        self.__subarrayBiggestSize = self.__updateSubarrayBiggestSize(subarrayCurrentSize)


    def __updateSubarrayBiggestSize(self, subarrayCurrentSize):

        return max(subarrayCurrentSize, self.__subarrayBiggestSize)


    def __updateFirstReferenceNumberIndexAndSubarrayCurrentSize(self, i, secondReferenceNumberIndex):

        firstReferenceNumberIndex, subarrayCurrentSize = 0, 0

        if self.__numbers[i] - self.__numbers[secondReferenceNumberIndex] == 1:
            firstReferenceNumberIndex = secondReferenceNumberIndex
            subarrayCurrentSize = i - secondReferenceNumberIndex + 1
        else:
            firstReferenceNumberIndex = i
            subarrayCurrentSize = 1

        result = [firstReferenceNumberIndex, subarrayCurrentSize]
        return result


    def printResult(self):

        print(self.__subarrayBiggestSize)


if __name__ == "__main__":
    main()
