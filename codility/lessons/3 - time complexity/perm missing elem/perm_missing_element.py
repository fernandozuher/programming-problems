# Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

def solution(array):

    array.sort()
    return find_missing_element(array)


def find_missing_element(array):

    index = -1
    for i, element in enumerate(array):
        if element != i + 1:
            index = i + 1
            break
    
    return len(array) + 1 if index == -1 else index
