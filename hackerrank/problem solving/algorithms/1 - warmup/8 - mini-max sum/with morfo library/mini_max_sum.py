# https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

from itertools import islice
import morfo


def main():
    arr = morfo.readln(int, list)
    min_sum, max_sum = calc_min_max_sum(arr)
    print(min_sum, max_sum)


# n: length of arr
# T: O(n)
# S: O(1) extra space
def calc_min_max_sum(arr):
    total = min_value = max_value = arr[0]

    for x in islice(arr, 1, None):
        total += x
        min_value = min(x, min_value)
        max_value = max(x, max_value)

    return total - max_value, total - min_value


if __name__ == '__main__':
    main()
