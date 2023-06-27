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

    cities_with_space_station.sort()
    FIRST_CITY = 0
    max_distance = cities_with_space_station[0] - FIRST_CITY
    previous_city = cities_with_space_station[0]

    for city_with_space_station in cities_with_space_station[1:]:
        DISTANCE = calculate_distance_between_cities(city_with_space_station, previous_city)
        max_distance = max(max_distance, DISTANCE)
        previous_city = city_with_space_station

    LAST_CITY = n_cities-1
    LAST_CITY_WITH_SPACE_STATION = cities_with_space_station[-1]
    if not has_last_city_space_station(LAST_CITY, LAST_CITY_WITH_SPACE_STATION):
        DISTANCE = calculate_distance_of_last_city(LAST_CITY, LAST_CITY_WITH_SPACE_STATION)
        max_distance = max(max_distance, DISTANCE)

    return max_distance


def calculate_distance_between_cities(city_with_space_station, previous_city):

    return math.trunc((city_with_space_station - previous_city) / 2)


def has_last_city_space_station(last_city, last_city_with_space_station):

    return last_city == last_city_with_space_station


def calculate_distance_of_last_city(last_city, last_city_with_space_station):

    return last_city - last_city_with_space_station


if __name__ == "__main__":
    main()
