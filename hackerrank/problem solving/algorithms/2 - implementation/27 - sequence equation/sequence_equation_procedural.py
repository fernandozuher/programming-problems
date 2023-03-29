# Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

def main():

    SIZE = readANumber()
    ARRAY = readAnArray()

    PERMUTATED_ARRAY = permutationEquation(ARRAY)
    printArray(PERMUTATED_ARRAY)


def readANumber():

    return int(input())


def readAnArray():

    ARRAY = list(map(int, input().split()))
    return ARRAY


def permutationEquation(array):

    ELEMENTS_POSITIONS_ARRAY = generateElementsPositionsArray(array)
    PERMUTATED_ARRAY = generatePermutatedArray(ELEMENTS_POSITIONS_ARRAY)
    return PERMUTATED_ARRAY


def generateElementsPositionsArray(array):

    elementsPositionsArray = [None] * len(array)
    for i, element in enumerate(array):
        elementsPositionsArray[element-1] = i
    return elementsPositionsArray


def generatePermutatedArray(array):

    permutatedArray = [None] * len(array)
    for i, element in enumerate(array):
        permutatedArray[i] = array[element] + 1
    return permutatedArray


def printArray(array):

    print(*array, sep="\n")


if __name__ == "__main__":
    main()
