# https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

import operator
import morfo


def main():
    arr = morfo.readln(int, list)
    min_sum, max_sum = calc_min_max_sum(arr)
    print(min_sum, max_sum)


# n: length of arr
# T: O(n)
# S: O(1) extra space
def calc_min_max_sum(arr):
    total, min_value, max_value = morfo.reduce_many(
        arr,
        operator.add, 0,
        min, arr[0],
        max, arr[0]
    )

    return total - max_value, total - min_value


if __name__ == '__main__':
    main()
