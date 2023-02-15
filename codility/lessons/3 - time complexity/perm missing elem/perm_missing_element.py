# Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

def solution(array):

    array.sort()
    MISSING_ELEMENT = findMissingElement(array)
    return MISSING_ELEMENT


def findMissingElement(array):

    i = 0

    for i, element in enumerate(array):
        if element != i + 1:
            break

    return i + 1
