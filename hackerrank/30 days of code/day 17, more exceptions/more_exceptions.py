# https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

def main():
    n_tests = int(input())
    for _ in range(n_tests):
        n, p = map(int, input().split())
        power(n, p)


def power(n, p):
    try:
        print(Calculator.power(n, p))
    except ValueError as e:
        print(e)


class Calculator:
    @staticmethod
    def power(n, p):
        if n < 0 or p < 0:
            raise ValueError('n and p should be non-negative')
        return pow(n, p)


if __name__ == '__main__':
    main()
