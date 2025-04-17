# https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

from math import sqrt


def main():
    n_tests = int(input())
    process_prime_tests(n_tests)


def process_prime_tests(n_tests):
    for _ in range(n_tests):
        n = int(input())
        print('Prime' if is_prime(n) else 'Not prime')


def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    limit = int(sqrt(n) + 1)
    for divisor in range(3, limit, 2):
        if n % divisor == 0:
            return False
    return True


if __name__ == '__main__':
    main()
