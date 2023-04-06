# Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

def main():

    INITIAL_STRING = input()
    FINAL_STRING = input()
    NUMBER_OF_OPERATIONS = int(input())

    RESPONSE = appendAndDelete(INITIAL_STRING, FINAL_STRING, NUMBER_OF_OPERATIONS)
    printOutput(RESPONSE)


def appendAndDelete(initialString, finalString, numberOfOperations):

    COMMON_PREFIX_SIZE_BETWEEN_STRINGS = findCommonPrefixSizeBetweenStrings(initialString, finalString)

    SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING = len(initialString) - COMMON_PREFIX_SIZE_BETWEEN_STRINGS
    SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING = len(finalString) - COMMON_PREFIX_SIZE_BETWEEN_STRINGS

    MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING = SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING
    numberOfOperations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING

    return areOperationsSuitableToReplaceString(numberOfOperations, COMMON_PREFIX_SIZE_BETWEEN_STRINGS)


def findCommonPrefixSizeBetweenStrings(initialString, finalString):

    size = 0
    while size != len(initialString) and size != len(finalString) and initialString[size] == finalString[size]:
        size += 1
    return size


def areOperationsSuitableToReplaceString(numberOfOperations, commonPrefixSizeBetweenStrings):

    if numberOfOperations < 0 or \
        (areOperationsBiggerThanZeroAndOdd(numberOfOperations) and
            areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations, commonPrefixSizeBetweenStrings)):
        return False

    return True


def areOperationsBiggerThanZeroAndOdd(numberOfOperations):

    return numberOfOperations > 0 and numberOfOperations%2 == 1


def areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations, commonPrefixSizeBetweenStrings):

    return numberOfOperations < commonPrefixSizeBetweenStrings*2


def printOutput(response):

    print("Yes" if response else "No")


if __name__ == "__main__":
    main()
