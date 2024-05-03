# https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

import sys

NO_INDEX = -1

def main():

    _ = input()
    ARRAY = read_an_int_array()
    print(find_minimum_distance(ARRAY))


def read_an_int_array():

    return list(map(int, input().split()))


def find_minimum_distance(array):

    minimum_distance = sys.maxsize
    first_indexes_of_elements = {}

    for i, element in enumerate(array):
        if element in first_indexes_of_elements:
            first_index, second_index = first_indexes_of_elements[element]

            if second_index == NO_INDEX:
                second_index = i
                first_indexes_of_elements[element] = (first_index, second_index)
                MINIMUM_DISTANCE_OF_CURRENT_ELEMENT = second_index - first_index
                minimum_distance = min(minimum_distance, MINIMUM_DISTANCE_OF_CURRENT_ELEMENT)
        else:
            first_indexes_of_elements[element] = (i, NO_INDEX)
    
    return minimum_distance_or_no_index(minimum_distance)


def minimum_distance_or_no_index(minimum_distance):

    return minimum_distance if minimum_distance != sys.maxsize else NO_INDEX


if __name__ == "__main__":
    main()
