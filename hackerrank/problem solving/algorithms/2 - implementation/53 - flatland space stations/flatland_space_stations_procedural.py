# Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

import math
import sys

def main():

    N_CITIES, _ = read_an_int_array()
    CITIES_WITH_SPACE_STATION = read_an_int_array()
    print(find_max_distance_from_space_station(N_CITIES, CITIES_WITH_SPACE_STATION))


def read_an_int_array():

    return list(map(int, input().split()))


def find_max_distance_from_space_station(n_cities, cities_with_space_station):

    max_distance = 0

    cities_with_space_station.sort()

    for city_i in range(n_cities):
        DISTANCE = find_min_distance_between_current_city_and_nearest_space_station(city_i, cities_with_space_station)
        if max_distance < DISTANCE:
            max_distance = DISTANCE

    return max_distance


def find_min_distance_between_current_city_and_nearest_space_station(city_i, cities_with_space_station):

    ELEMENT = find_element_or_nearest(city_i, cities_with_space_station)
    MIN_DISTANCE_BETWEEN_CITY_AND_NEAREST_SPACE_STATION = abs(city_i - ELEMENT)
    return MIN_DISTANCE_BETWEEN_CITY_AND_NEAREST_SPACE_STATION


def find_element_or_nearest(n, array):

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


if __name__ == "__main__":
    main()
