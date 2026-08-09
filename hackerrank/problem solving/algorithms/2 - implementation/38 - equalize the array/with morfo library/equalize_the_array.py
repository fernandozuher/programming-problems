# https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

from collections import Counter

import morfo


def main():
    morfo.skip_input_ln()
    print(min_deletions_to_equalize(morfo.readln(int, list)))


# n: length of arr, 1 <= n <= 100
# k: number of distinct elements in arr
# k <= n
# T: O(n) = O(100) = O(1)
# S: O(k) = O(n) = O(100) = O(1) extra space
def min_deletions_to_equalize(arr):
    return len(arr) - max(Counter(arr).values())


if __name__ == '__main__':
    main()
