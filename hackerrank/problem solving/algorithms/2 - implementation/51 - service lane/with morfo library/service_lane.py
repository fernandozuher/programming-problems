# https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

from itertools import islice

import morfo


def main():
    _, t = morfo.readln(int, list)
    widths = morfo.readln(int, list)
    for _ in range(t):
        print(min_width_in_segment(widths, morfo.readln(int, list)))


# n: length of widths
# T: O(n)
# S: O(1) extra space
def min_width_in_segment(widths, segment):
    start, finish = segment
    return min(islice(widths, start, finish + 1))


if __name__ == '__main__':
    main()
