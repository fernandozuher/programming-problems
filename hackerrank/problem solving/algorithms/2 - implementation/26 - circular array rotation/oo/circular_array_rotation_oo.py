# Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main():

    INPUT = readInput()
    OBJ = CircularArrayRotation(INPUT)
    OBJ.printRotatedArrayElementsAccordingToQueries()


def readInput():

    [ARRAY_SIZE, ROTATION_COUNT, QUERIES_SIZE] = readLineAsIntList()
    ARRAY = readLineAsIntList()
    QUERIES = readQueries(QUERIES_SIZE)
    INPUT = [ARRAY, ARRAY_SIZE, ROTATION_COUNT, QUERIES, QUERIES_SIZE]
    return INPUT


def readLineAsIntList():

    ARRAY = list(map(int, input().split()))
    return ARRAY


def readQueries(size):

    ARRAY = [int(input()) for _ in range(size)]
    return ARRAY


class CircularArrayRotation:

    def __init__(self, input):

        self.__array = input[0]
        self.__arraySize = input[1]
        self.__rotationCount = input[2]
        self.__queries = input[3]
        self.__querySize = input[4]

        self.__reduceInputRotations()
        self.__rotateInputArray()


    def __reduceInputRotations(self):

        if (self.__arraySize > 1):
            self.__rotationCount = self.__rotationCount % self.__arraySize if self.__rotationCount >= self.__arraySize else self.__rotationCount
        else:
            self.__rotationCount = 0


    def __rotateInputArray(self):

        FIRST_PART_NEW_ARRAY = self.__array[self.__arraySize - self.__rotationCount:]
        SECOND_PART_NEW_ARRAY = self.__array[:self.__arraySize - self.__rotationCount]
        NEW_ARRAY = FIRST_PART_NEW_ARRAY + SECOND_PART_NEW_ARRAY

        self.__array = NEW_ARRAY


    def printRotatedArrayElementsAccordingToQueries(self):

        [print(self.__array[query]) for query in self.__queries]


if __name__ == "__main__":
    main()
