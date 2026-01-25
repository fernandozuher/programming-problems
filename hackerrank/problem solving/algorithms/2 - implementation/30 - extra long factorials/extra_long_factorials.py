# https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

from functools import reduce
import operator


def main():
    n = int(input())
    print(factorial(n))


# T: O(n)
# S: O(1) extra space (excluding the size of the resulting integer)
def factorial(n):
    return reduce(operator.mul, range(1, n + 1))


if __name__ == '__main__':
    main()
