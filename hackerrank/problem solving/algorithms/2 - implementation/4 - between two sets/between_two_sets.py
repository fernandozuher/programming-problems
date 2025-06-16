# https://www.hackerrank.com/challenges/between-two-sets/problem?is_full_screen=true

import math
from functools import reduce


def main():
    input()
    numbers_a = read_numbers()
    numbers_b = read_numbers()
    print(between_two_sets(numbers_a, numbers_b))


def read_numbers():
    return list(map(int, input().split()))


def between_two_sets(a, b):
    lcm_of_a = lcm_array(a)
    gcd_of_b = gcd_array(b)

    count = 0
    for i in range(lcm_of_a, gcd_of_b + 1, lcm_of_a):
        if gcd_of_b % i == 0:
            count += 1
    return count


def lcm_array(numbers):
    return reduce(math.lcm, numbers[1:], numbers[0])


def gcd_array(numbers):
    return reduce(math.gcd, numbers[1:], numbers[0])


if __name__ == "__main__":
    main()
