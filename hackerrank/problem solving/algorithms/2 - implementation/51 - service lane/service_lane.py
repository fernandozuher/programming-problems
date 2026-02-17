# https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

from itertools import islice


def main():
    _, t = read_numbers()
    widths = read_numbers()
    for _ in range(t):
        print(min_width_in_segment(widths, read_numbers()))


def read_numbers():
    return list(map(int, input().split()))


# n: length of array widths
# T: O(n)
# S: O(1) extra space
def min_width_in_segment(widths, segment):
    start, finish = segment
    return min(islice(widths, start, finish + 1))


if __name__ == '__main__':
    main()
