# Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

def solution(A):

    A.sort()
    unpaired_element = A[0]
    is_element_paired = False

    for i in range(1, len(A)):
        if A[i] == unpaired_element:
            is_element_paired = not is_element_paired
        elif is_element_paired:
            is_element_paired = False
            unpaired_element = A[i]
        else:
            break

    return unpaired_element
