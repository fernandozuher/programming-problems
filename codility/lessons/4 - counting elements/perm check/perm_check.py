# Source: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

def solution(array):

    numbers = set(array)
    return 1 if len(numbers) == len(array) and list(numbers)[-1] == len(array) else 0
