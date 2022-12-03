#!/bin/python3

import math

if __name__ == "__main__":

    n = int(input().strip())
    max_ones, ones = 0, 0

    while n > 0:
        if n % 2:
            ones += 1
        else:
            if ones > max_ones:
                max_ones = ones
            ones = 0
        n = math.floor(n / 2)

    print(ones if ones > max_ones else max_ones)
