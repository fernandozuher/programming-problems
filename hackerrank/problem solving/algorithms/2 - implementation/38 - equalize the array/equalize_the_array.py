# https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    print(equalize_array(read_numbers()))


def read_numbers():
    return list(map(int, input().split()))


def equalize_array(arr):
    counter = Counter(arr)
    max_frequency = max(counter.values())
    return len(arr) - max_frequency


if __name__ == '__main__':
    main()
