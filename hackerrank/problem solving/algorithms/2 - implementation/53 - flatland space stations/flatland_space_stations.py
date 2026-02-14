# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

from itertools import pairwise


def main():
    n_cities, _ = read_numbers()
    last_city = n_cities - 1
    cities_with_space_station = sorted(read_numbers())
    print(max_distance_from_space_station(last_city, cities_with_space_station))


def read_numbers():
    return list(map(int, input().split()))


def max_distance_from_space_station(last_city, stations):
    max_dist = stations[0]

    for prev, curr in pairwise(stations):
        gap = (curr - prev) // 2
        max_dist = max(max_dist, gap)

    return max(max_dist, last_city - stations[-1])


if __name__ == '__main__':
    main()
