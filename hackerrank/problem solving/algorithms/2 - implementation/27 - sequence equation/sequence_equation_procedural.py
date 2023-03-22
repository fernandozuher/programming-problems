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

    ARRAY_ELEMENTS_POSITIONS = generateArrayOfElementsPositions(array)
    PERMUTATED_ARRAY = generatePermutatedArray(ARRAY_ELEMENTS_POSITIONS)
    return PERMUTATED_ARRAY


def generateArrayOfElementsPositions(array):

    arrayElementsPositions = [None] * len(array)
    for i, element in enumerate(array):
        arrayElementsPositions[element-1] = i
    return arrayElementsPositions


def generatePermutatedArray(array):

    permutatedArray = [None] * len(array)
    for i, element in enumerate(array):
        permutatedArray[i] = array[element] + 1
    return permutatedArray


def printArray(array):

    print(*array, sep="\n")


if __name__ == "__main__":
    main()
