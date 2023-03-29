# Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

def main():

    SIZE = readANumber()
    ARRAY = readAnArray()

    OBJ = SequenceEquation(ARRAY)
    OBJ.printPermutatedArray()


def readANumber():

    return int(input())


def readAnArray():

    ARRAY = list(map(int, input().split()))
    return ARRAY


class SequenceEquation:

    def __init__(self, array):

        self.__inputArray = array
        self.__elementsPositionsArray = self.__generateElementsPositionsArray()
        self.__permutatedArray = self.__generatePermutatedArray()


    def __generateElementsPositionsArray(self):

        elementsPositionsArray = [None] * len(self.__inputArray)
        for i, element in enumerate(self.__inputArray):
            elementsPositionsArray[element-1] = i
        return elementsPositionsArray


    def __generatePermutatedArray(self):

        permutatedArray = [None] * len(self.__elementsPositionsArray)
        for i, element in enumerate(self.__elementsPositionsArray):
            permutatedArray[i] = self.__elementsPositionsArray[element] + 1
        return permutatedArray


    def printPermutatedArray(self):

        print(*self.__permutatedArray, sep="\n")


if __name__ == "__main__":
    main()
