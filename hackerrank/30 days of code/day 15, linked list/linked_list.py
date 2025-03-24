# https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

from collections import deque


def main():
    n = int(input())
    list = initialize_list(n)
    display_list(list)


def initialize_list(n):
    return deque(int(input()) for _ in range(n))


def display_list(list):
    print(*list)


if __name__ == '__main__':
    main()
