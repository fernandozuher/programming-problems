# Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

def solution(A):

    A.sort()
    unpairedElement = A[0]
    isElementPaired = False

    for i in range(1, len(A)):
        if A[i] == unpairedElement:
            isElementPaired = not isElementPaired
        elif isElementPaired:
            isElementPaired = False
            unpairedElement = A[i]
        else:
            break

    return unpairedElement
