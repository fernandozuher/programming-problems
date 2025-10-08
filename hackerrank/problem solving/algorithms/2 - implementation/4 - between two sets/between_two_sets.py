# https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

import math
from functools import reduce


def main():
    input()
    a = read_numbers()
    b = read_numbers()
    print(between_two_sets(a, b))


def read_numbers():
    return list(map(int, input().split()))


def between_two_sets(a, b):
    lcm_of_a = reduce(math.lcm, a)
    gcd_of_b = reduce(math.gcd, b)

    count = 0
    for i in range(lcm_of_a, gcd_of_b + 1, lcm_of_a):
        if gcd_of_b % i == 0:
            count += 1
    return count


if __name__ == "__main__":
    main()
