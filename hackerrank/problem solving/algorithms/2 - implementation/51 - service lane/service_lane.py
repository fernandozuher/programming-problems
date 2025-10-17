# https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

def main():
    _, n = read_numbers()
    widths = read_numbers()
    for _ in range(n):
        print(max_affordable_width_vehicle_in_range(widths, read_numbers()))


def read_numbers():
    return list(map(int, input().split()))


def max_affordable_width_vehicle_in_range(widths, point):
    start, finish = point
    return min(widths[start:finish + 1])


if __name__ == '__main__':
    main()
