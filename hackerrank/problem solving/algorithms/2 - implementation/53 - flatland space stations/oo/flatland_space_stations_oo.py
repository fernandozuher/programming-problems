# Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

import math
import sys

def main():

    N_CITIES, _ = read_an_int_array()
    CITIES_WITH_SPACE_STATION = read_an_int_array()
    OBJ = FlatlandSpaceStations(N_CITIES, CITIES_WITH_SPACE_STATION)
    print(OBJ.get_max_distance_from_space_station())


def read_an_int_array():

    return list(map(int, input().split()))


class FlatlandSpaceStations:

    def __init__(self, n_cities, cities_with_space_station):

        self._n_cities = n_cities
        self._cities_with_space_station = cities_with_space_station
        self._max_distance_from_space_station = 0

        self._cities_with_space_station.sort()
        self._find_max_distance_from_space_station()


    def _find_max_distance_from_space_station(self):

        for city_i in range(self._n_cities):
            DISTANCE = self._find_min_distance_between_current_city_and_nearest_space_station(city_i)
            self._max_distance_from_space_station = max(self._max_distance_from_space_station, DISTANCE)


    def _find_min_distance_between_current_city_and_nearest_space_station(self, city_i):

        ELEMENT = self._find_element_or_nearest(city_i, self._cities_with_space_station)
        MIN_DISTANCE_BETWEEN_CITY_AND_NEAREST_SPACE_STATION = abs(city_i - ELEMENT)
        return MIN_DISTANCE_BETWEEN_CITY_AND_NEAREST_SPACE_STATION


    def _find_element_or_nearest(self, n, array):

        max = len(array) - 1
        min = 0

        min_distance = sys.maxsize
        nearest_element = n

        while min <= max:
            MID = math.trunc((min + max) / 2)

            DISTANCE = abs(array[MID] - n)
            if DISTANCE < min_distance:
                nearest_element = array[MID]
                min_distance = DISTANCE

            if array[MID] == n:
                return n
            elif array[MID] > n:
                max = MID - 1
            else:
                min = MID + 1

        return nearest_element


    def get_max_distance_from_space_station(self):

        return self._max_distance_from_space_station


if __name__ == "__main__":
    main()
