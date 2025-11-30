# https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

from functools import reduce
import operator


def main():
    n = int(input())
    print(factorial(n))


def factorial(n):
    return reduce(operator.mul, range(1, n + 1))


if __name__ == '__main__':
    main()
