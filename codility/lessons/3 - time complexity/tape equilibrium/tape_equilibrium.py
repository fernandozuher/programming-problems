# Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

def solution(array):

    MINIMUM_DIFFERENCE_BETWEEN_PARTS = findMinimumDifferenceBetweenTwoPartsArray(array)
    return MINIMUM_DIFFERENCE_BETWEEN_PARTS


def findMinimumDifferenceBetweenTwoPartsArray(array):

    firstPart = array[0]
    secondPart = sum(array) - firstPart
    minimumDifferenceBetweenParts = abs(firstPart - secondPart)

    for i in range(1, len(array) - 1):
        firstPart += array[i]
        secondPart -= array[i]
        CURRENT_MINIMUM = abs(firstPart - secondPart)

        if minimumDifferenceBetweenParts > CURRENT_MINIMUM:
            minimumDifferenceBetweenParts = CURRENT_MINIMUM

    return minimumDifferenceBetweenParts
