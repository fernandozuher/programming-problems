# https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import math


def main():
    n = int(input())
    for _ in range(n):
        print(squares(read_numbers()))


def read_numbers():
    return list(map(int, input().split()))


def squares(data):
    start_num, end_num = data
    max_square = int(math.floor(math.sqrt(end_num)))
    min_square = int(math.ceil(math.sqrt(start_num)))
    return max_square - min_square + 1


if __name__ == '__main__':
    main()
