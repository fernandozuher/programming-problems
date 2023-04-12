# Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

def main():

    _SIZE = int(input())
    ARRAY = readAnArray()
    ARRAY.sort()

    OBJ = CutTheSticks(ARRAY)
    RESULT = OBJ.getRemainingSticksLengthArray()
    printArray(RESULT)


def readAnArray():

    return list(map(int, input().split()))


def printArray(array):

    print(*array, sep="\n")


class CutTheSticks:

    def __init__(self, array):

        self.__sticksLengthArray = array
        self.__SIZE_STICKS_LENGTH_ARRAY = len(array)
        self.__remainingSticksLengthArray = self.__initializeRemainingSticksLengthArray()
        self.__cutTheSticks()


    def __initializeRemainingSticksLengthArray(self):

        return [self.__SIZE_STICKS_LENGTH_ARRAY]


    def __cutTheSticks(self):

        i = 0
        while i < self.__SIZE_STICKS_LENGTH_ARRAY:
            SHORTEST_STICK_LENGTH = self.__sticksLengthArray[i]

            i = self.__findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i)
            CURRENT_ITERATION_SIZE = self.__SIZE_STICKS_LENGTH_ARRAY - i
            if i == self.__SIZE_STICKS_LENGTH_ARRAY:
                break

            self.__remainingSticksLengthArray.append(CURRENT_ITERATION_SIZE)
            self.__decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, SHORTEST_STICK_LENGTH)


    def __findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(self, index):

        SHORTEST_STICK_LENGTH = self.__sticksLengthArray[index]
        while index < self.__SIZE_STICKS_LENGTH_ARRAY and self.__sticksLengthArray[index] == SHORTEST_STICK_LENGTH:
            index += 1
        return index


    def __decreaseSticksLengthsHigherThanCurrentShortestStickLength(self, index, shortestStickLength):

        for i in range(index, self.__SIZE_STICKS_LENGTH_ARRAY):
            self.__sticksLengthArray[i] -= shortestStickLength


    def getRemainingSticksLengthArray(self):

        return self.__remainingSticksLengthArray


if __name__ == "__main__":
    main()
