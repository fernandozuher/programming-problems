# Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

def main():

    _SIZE = int(input())
    ARRAY = readAnArray()
    ARRAY.sort()

    RESULT = cutTheSticks(ARRAY)
    printArray(RESULT)


def readAnArray():

    return list(map(int, input().split()))


def cutTheSticks(array):

    SIZE = len(array)
    REMAINING_STICKS_OF_EACH_ITERATION = initializeResult(SIZE)

    i = 0
    while i < SIZE:
        SHORTEST_STICK_LENGTH = array[i]

        i = findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, array)
        CURRENT_ITERATION_SIZE = SIZE - i
        if i == SIZE:
            break

        REMAINING_STICKS_OF_EACH_ITERATION.append(CURRENT_ITERATION_SIZE)
        decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, array, SHORTEST_STICK_LENGTH)

    return REMAINING_STICKS_OF_EACH_ITERATION


def initializeResult(size):

    REMAINING_STICKS_OF_EACH_ITERATION = [size]
    return REMAINING_STICKS_OF_EACH_ITERATION


def findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(index, array):

    SIZE = len(array)
    SHORTEST_STICK_LENGTH = array[index]
    while index < SIZE and array[index] == SHORTEST_STICK_LENGTH:
        index += 1
    return index


def decreaseSticksLengthsHigherThanCurrentShortestStickLength(index, array, shortestStickLength):

    for i in range(index, len(array)):
        array[i] -= shortestStickLength


def printArray(array):

    print(*array, sep="\n")


if __name__ == "__main__":
    main()
