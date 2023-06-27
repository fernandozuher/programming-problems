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

        FIRST_CITY = 0
        self._max_distance_from_space_station = self._cities_with_space_station[0] - FIRST_CITY
        previous_city = self._cities_with_space_station[0]

        for city_with_space_station in self._cities_with_space_station[1:]:
            DISTANCE = self._calculate_distance_between_cities(city_with_space_station, previous_city)
            self._max_distance_from_space_station = max(self._max_distance_from_space_station, DISTANCE)
            previous_city = city_with_space_station

        if not self._has_last_city_space_station():
            DISTANCE = self._calculate_distance_of_last_city()
            self._max_distance_from_space_station = max(self._max_distance_from_space_station, DISTANCE)


    def _calculate_distance_between_cities(self, city_with_space_station, previous_city):

        return math.trunc((city_with_space_station - previous_city) / 2)


    def _has_last_city_space_station(self):

        return self._n_cities-1 == self._cities_with_space_station[-1]


    def _calculate_distance_of_last_city(self):

        return self._n_cities-1 - self._cities_with_space_station[-1]


    def get_max_distance_from_space_station(self):

        return self._max_distance_from_space_station


if __name__ == "__main__":
    main()
