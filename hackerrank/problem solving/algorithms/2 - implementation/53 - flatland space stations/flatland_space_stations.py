# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
# From Python 3.8

import math


def main():
    n_cities, _ = read_int_array()
    cities_with_space_station = sorted(read_int_array())
    print(find_max_distance_from_space_station(n_cities, cities_with_space_station))


def read_int_array():
    return list(map(int, input().split()))


def find_max_distance_from_space_station(n_cities, cities_with_space_station):
    max_distance_from_space_station = previous_city = cities_with_space_station[0]

    for city_with_space_station in cities_with_space_station[1:]:
        distance_between_cities = math.trunc((city_with_space_station - previous_city) / 2)
        max_distance_from_space_station = max(max_distance_from_space_station, distance_between_cities)
        previous_city = city_with_space_station

    if not (has_last_city_space_station := n_cities - 1 == cities_with_space_station[-1]):
        distance_of_last_city = n_cities - 1 - cities_with_space_station[-1]
        max_distance_from_space_station = max(max_distance_from_space_station, distance_of_last_city)

    return max_distance_from_space_station


if __name__ == '__main__':
    main()
