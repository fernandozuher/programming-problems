# https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    print(min_deletions_to_equalize(read_numbers()))


def read_numbers():
    return list(map(int, input().split()))


# n: length of arr, 1 <= n <= 100
# T: O(n) = O(100) = O(1)
# S: O(n) = O(100) = O(1) extra space
def min_deletions_to_equalize(arr):
    return len(arr) - max(Counter(arr).values())


if __name__ == '__main__':
    main()
