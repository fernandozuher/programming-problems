# Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

def main():

    _ = int(input())
    ARRAY = readAnArray()

    OBJ = EqualizeTheArray(ARRAY)
    MINIMUM_NUMBER_OF_DELETIONS_REQUIRED = OBJ.getMinimumNumberOfDeletionsRequired()
    print(MINIMUM_NUMBER_OF_DELETIONS_REQUIRED)


def readAnArray():

    ARRAY = list(map(int, input().strip().split()))
    return ARRAY


class EqualizeTheArray:

    def __init__(self, array):
    
        array.sort()
        self.__array = array
        self.__minimumNumberOfDeletionsRequired = 0
        self.__equalizeArray()


    def __equalizeArray(self):

        MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT = self.__findMaximumQuantityOfEqualElement()
        self.__minimumNumberOfDeletionsRequired = len(self.__array) - MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT


    def __findMaximumQuantityOfEqualElement(self):

        maximumQuantityOfEqualElement = 1
        temporaryQuantityEqualElement = 1

        for i in range(1, len(self.__array)):
            if self.__areConsecutiveElementesEqual(self.__array[i-1], self.__array[i]):
                temporaryQuantityEqualElement += 1
                maximumQuantityOfEqualElement = max(temporaryQuantityEqualElement, maximumQuantityOfEqualElement)
            else:
                temporaryQuantityEqualElement = 1

        return maximumQuantityOfEqualElement


    def __areConsecutiveElementesEqual(self, element1, element2):

        return element1 == element2


    def getMinimumNumberOfDeletionsRequired(self):

        return self.__minimumNumberOfDeletionsRequired


if __name__ == "__main__":
    main()
