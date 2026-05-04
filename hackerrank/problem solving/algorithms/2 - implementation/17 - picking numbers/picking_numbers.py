# https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    freq_map = Counter(read_numbers())
    print(picking_numbers(freq_map))


def read_numbers():
    return list(map(int, input().split()))


# k: length of freq_map
# 1 <= k <= 99
# T: O(k) = O(99) = O(1)
# S: O(1) extra space
def picking_numbers(freq_map):
    max_len = 0
    for num in freq_map:
        max_len = max(max_len, freq_map[num] + freq_map.get(num + 1, 0))
    return max_len


if __name__ == '__main__':
    main()
