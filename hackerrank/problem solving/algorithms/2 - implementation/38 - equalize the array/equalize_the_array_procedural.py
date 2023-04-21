# Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

def main():

    _ = int(input())
    ARRAY = readAnArray()

    MINIMUM_NUMBER_OF_DELETIONS_REQUIRED = equalizeArray(ARRAY)
    print(MINIMUM_NUMBER_OF_DELETIONS_REQUIRED)


def readAnArray():

    ARRAY = list(map(int, input().strip().split()))
    return ARRAY


def equalizeArray(array):

    array.sort()
    MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT = findMaximumQuantityOfEqualElement(array)
    MINIMUM_NUMBER_OF_DELETIONS_REQUIRED = len(array) - MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT
    return MINIMUM_NUMBER_OF_DELETIONS_REQUIRED


def findMaximumQuantityOfEqualElement(array):

    maximumQuantityOfEqualElement = 1
    temporaryQuantityEqualElement = 1

    for i in range(1, len(array)):
        if areConsecutiveElementesEqual(array[i-1], array[i]):
            temporaryQuantityEqualElement += 1
            maximumQuantityOfEqualElement = max(temporaryQuantityEqualElement, maximumQuantityOfEqualElement)
        else:
            temporaryQuantityEqualElement = 1

    return maximumQuantityOfEqualElement


def areConsecutiveElementesEqual(element1, element2):

    return element1 == element2


if __name__ == "__main__":
    main()
