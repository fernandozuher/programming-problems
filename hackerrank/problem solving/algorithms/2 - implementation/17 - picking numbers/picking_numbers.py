# https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    print(picking_numbers(read_numbers()))


def read_numbers():
    return list(map(int, input().split()))


def picking_numbers(numbers):
    counter = Counter(numbers)
    max_len = 0
    for num in counter:
        max_len = max(max_len, counter[num] + counter.get(num + 1, 0))
    return max_len


if __name__ == '__main__':
    main()
