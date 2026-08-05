# https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

import morfo


def main():
    n = morfo.read(int)
    print(diagonal_difference(n))


# T: O(n^2)
# S: O(n) extra space
def diagonal_difference(n):
    primary_sum, secondary_sum = 0, 0

    for i in range(n):
        arr = morfo.readln(int, list)
        primary_sum += arr[i]
        secondary_sum += arr[-i - 1]

    return abs(primary_sum - secondary_sum)


if __name__ == '__main__':
    main()
