# https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import math

import morfo


def main():
    n = morfo.read(int)
    for _ in range(n):
        a = morfo.read(int)
        b = morfo.read(int)
        print(squares(a, b))


# T: O(1)
# S: O(1) extra space
def squares(start_num, end_num):
    max_square = int(math.floor(math.sqrt(end_num)))
    min_square = int(math.ceil(math.sqrt(start_num)))
    return max_square - min_square + 1


if __name__ == '__main__':
    main()
