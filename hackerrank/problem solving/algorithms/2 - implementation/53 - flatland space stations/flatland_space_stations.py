# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

from itertools import pairwise


def main():
    n_cities, _ = read_numbers()
    last_city = n_cities - 1
    cities_with_space_station = read_numbers()
    cities_with_space_station.sort()
    print(max_distance_from_space_station(last_city, cities_with_space_station))


def read_numbers():
    return list(map(int, input().split()))


# n: length of array stations
# T: O(n)
# S: O(1) extra space
def max_distance_from_space_station(last_city, stations):
    max_dist = max((curr - prev) // 2 for prev, curr in pairwise(stations)) if len(stations) > 1 else 0
    return max(max_dist, stations[0], last_city - stations[-1])


if __name__ == '__main__':
    main()
