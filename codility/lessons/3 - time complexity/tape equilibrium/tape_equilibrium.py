# Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

def solution(array):

    first_part = array[0]
    second_part = sum(array) - first_part
    minimum_difference_between_parts = abs(first_part - second_part)

    for element in array[1:-1]:
        first_part += element
        second_part -= element
        CURRENT_MINIMUM = abs(first_part - second_part)
        minimum_difference_between_parts = min(minimum_difference_between_parts, CURRENT_MINIMUM)

    return minimum_difference_between_parts
