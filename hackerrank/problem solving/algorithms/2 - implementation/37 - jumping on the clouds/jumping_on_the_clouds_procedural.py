# Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

def main():

    _ = int(input())
    CLOUD_ARRAY = readAnArray()
    MINIMUM_NUMBER_OF_JUMPS = calculateMinimumNumberOfJumps(CLOUD_ARRAY)
    print(MINIMUM_NUMBER_OF_JUMPS)


def readAnArray():

    ARRAY = list(map(int, input().split()))
    return ARRAY


def calculateMinimumNumberOfJumps(array):

    i = 0
    size = len(array) - 1
    jumps = 0

    while i < size:
        i = getIndexOfNextJump(i, array)
        jumps += 1

    return jumps


def getIndexOfNextJump(index, array):

    if isNextSecondIndexInsideRange(index + 2, len(array)):
        index += 2 if isNextSecondCloudCumulus(array[index + 2]) else 1
    else:
        index += 1
    return index


def isNextSecondIndexInsideRange(index, size):

    return index < size


def isNextSecondCloudCumulus(typeOfCloud):

    return typeOfCloud == 0


if __name__ == "__main__":
    main()