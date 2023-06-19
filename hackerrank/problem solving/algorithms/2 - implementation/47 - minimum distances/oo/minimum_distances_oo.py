# Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

import sys

NO_INDEX = -1

def main():

    _ = input()
    ARRAY = read_an_int_array()
    OBJ = MinimumDistances(ARRAY)
    print(OBJ.get_minimum_distance())


def read_an_int_array():

    return list(map(int, input().split()))


class MinimumDistances:

    def __init__(self, array):

        self._array = array
        self._minimum_distance = sys.maxsize
        self._find_minimum_distance()


    def _find_minimum_distance(self):

        first_indexes_of_elements = {}

        for i, element in enumerate(self._array):
            if element in first_indexes_of_elements:
                first_index, second_index = first_indexes_of_elements[element]

                if second_index == NO_INDEX:
                    second_index = i
                    first_indexes_of_elements[element] = (first_index, second_index)
                    MINIMUM_DISTANCE_OF_CURRENT_ELEMENT = second_index - first_index
                    self._minimum_distance = min(self._minimum_distance, MINIMUM_DISTANCE_OF_CURRENT_ELEMENT)
            else:
                first_indexes_of_elements[element] = (i, NO_INDEX)
        
        self._minimum_distance = self._minimum_distance_or_no_index()


    def _minimum_distance_or_no_index(self):

        return self._minimum_distance if self._minimum_distance != sys.maxsize else NO_INDEX


    def get_minimum_distance(self):

        return self._minimum_distance


if __name__ == "__main__":
    main()
