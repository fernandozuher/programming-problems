# Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

def main():

    INITIAL_STRING = input()
    FINAL_STRING = input()
    NUMBER_OF_OPERATIONS = int(input())

    OBJ = AppendAndDelete(INITIAL_STRING, FINAL_STRING, NUMBER_OF_OPERATIONS)
    RESPONSE = OBJ.getResponse()
    printOutput(RESPONSE)


def printOutput(response):

    print("Yes" if response else "No")


class AppendAndDelete:

    def __init__(self, initialString, finalString, numberOfOperations):

        self.__initialString = initialString
        self.__finalString = finalString
        self.__numberOfOperations = numberOfOperations

        self.__commonPrefixSizeBetweenStrings = 0
        self.__areOperationsSuitableToReplacement = False

        self.__appendAndDelete()


    def __appendAndDelete(self):

        self.__commonPrefixSizeBetweenStrings = self.__findCommonPrefixSizeBetweenStrings()

        SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING = len(self.__initialString) - self.__commonPrefixSizeBetweenStrings
        SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING = len(self.__finalString) - self.__commonPrefixSizeBetweenStrings

        MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING = SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING
        
        self.__numberOfOperations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING
        self.__areOperationsSuitableToReplacement = self.__areOperationsSuitableToReplaceString()


    def __findCommonPrefixSizeBetweenStrings(self):

        size = 0
        while size != len(self.__initialString) and size != len(self.__finalString) \
            and self.__initialString[size] == self.__finalString[size]:
            size += 1
        return size


    def __areOperationsSuitableToReplaceString(self):

        if self.__numberOfOperations < 0 or \
            (self.__areOperationsBiggerThanZeroAndOdd() and self.__areNotOperationsEnoughToRemoveAndReplaceCommonPrefix()):
            return False
        return True


    def __areOperationsBiggerThanZeroAndOdd(self):

        return self.__numberOfOperations > 0 and self.__numberOfOperations%2 == 1


    def __areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(self):

        return self.__numberOfOperations < self.__commonPrefixSizeBetweenStrings*2


    def getResponse(self):

        return self.__areOperationsSuitableToReplacement


if __name__ == "__main__":
    main()
