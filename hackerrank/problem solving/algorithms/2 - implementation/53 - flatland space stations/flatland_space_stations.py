# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

def main():
    n_cities, _ = read_numbers()
    cities_with_space_station = sorted(read_numbers())
    print(max_distance_from_space_station(n_cities, cities_with_space_station))


def read_numbers():
    return list(map(int, input().split()))


def max_distance_from_space_station(n_cities, stations):
    max_dist = stations[0]

    for prev, curr in zip(stations, stations[1:]):
        gap = (curr - prev) // 2
        max_dist = max(max_dist, gap)

    last_city = n_cities - 1
    return max(max_dist, last_city - stations[-1])


if __name__ == '__main__':
    main()
