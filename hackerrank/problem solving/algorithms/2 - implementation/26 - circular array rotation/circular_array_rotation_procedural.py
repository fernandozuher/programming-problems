# Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main():

    input = readInput()
    input = reduceInputRotations(input)
    input = rotateInputArray(input)
    printRotatedArrayElementsAccordingToQueries(input)


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


def reduceInputRotations(input):

    ARRAY_SIZE = input[1]
    rotationCount = input[2]

    if (ARRAY_SIZE > 1):
        input[2] = rotationCount = rotationCount % ARRAY_SIZE if rotationCount >= ARRAY_SIZE else rotationCount
    else:
        input[2] = rotationCount = 0

    return input


def rotateInputArray(input):

    ARRAY = input[0]
    ARRAY_SIZE = input[1]
    ROTATION_COUNT = input[2]

    FIRST_PART_NEW_ARRAY = ARRAY[ARRAY_SIZE - ROTATION_COUNT:]
    SECOND_PART_NEW_ARRAY = ARRAY[:ARRAY_SIZE - ROTATION_COUNT]
    NEW_ARRAY = FIRST_PART_NEW_ARRAY + SECOND_PART_NEW_ARRAY

    input[0] = NEW_ARRAY
    return input


def printRotatedArrayElementsAccordingToQueries(input):

    ARRAY = input[0]
    QUERIES = input[3]
    [print(ARRAY[query]) for query in QUERIES]


if __name__ == "__main__":
    main()
