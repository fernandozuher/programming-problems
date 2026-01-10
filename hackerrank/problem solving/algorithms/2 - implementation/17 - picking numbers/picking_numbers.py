# https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    print(picking_numbers(counter()))


def counter():
    return Counter(map(int, input().split()))


# n: length of initial input array of numbers
# k: length of map frequency
# T:
#   Without constraining the input values:
#       In the worst case, length of map equals length of initial input array when there is no repeated element: k = n
#       O(n)
#   With input values limited to 1 through 99, as stated in the problem:
#       Max of 99 keys/values at map: O(99) = O(1)
# S: O(1) extra space
def picking_numbers(frequency):
    max_len = 0
    for num in frequency:
        max_len = max(max_len, frequency[num] + frequency.get(num + 1, 0))
    return max_len


if __name__ == '__main__':
    main()
