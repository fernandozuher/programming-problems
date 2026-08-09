# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

from itertools import pairwise

import morfo


def main():
    n_cities, _ = morfo.readln(int, list)
    last_city = n_cities - 1
    cities_with_space_station = morfo.readln(int, list)
    cities_with_space_station.sort()
    print(max_distance_from_space_station(last_city, cities_with_space_station))


# n: length of stations
# T: O(n)
# S: O(1) extra space
def max_distance_from_space_station(last_city, stations):
    max_dist = 0
    if len(stations) > 1:
        max_dist = max((curr - prev) // 2 for prev, curr in pairwise(stations))
    return max(max_dist, stations[0], last_city - stations[-1])


if __name__ == '__main__':
    main()
