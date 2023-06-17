# Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

import sys

def main():

    _ = input()
    ARRAY = read_an_int_array()
    print(find_minimum_distance(ARRAY))


def read_an_int_array():

    return list(map(int, input().split()))


def find_minimum_distance(array):

    minimum_distance = sys.maxsize
    elements = {}

    for i, element in enumerate(array):
        if element in elements:
            first_index, second_index = elements[element]

            if second_index == -1:
                second_index = i
                elements[element] = (first_index, second_index)
                MINIMUM_DISTANCE_OF_CURRENT_ELEMENT = second_index - first_index
                minimum_distance = min(minimum_distance, MINIMUM_DISTANCE_OF_CURRENT_ELEMENT)
        else:
            elements[element] = (i, -1)
    
    return minimum_distance if minimum_distance != sys.maxsize else -1


if __name__ == "__main__":
    main()
