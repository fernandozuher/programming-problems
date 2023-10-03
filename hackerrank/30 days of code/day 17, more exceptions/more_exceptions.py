# https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

def main():

    calc = Calculator()
    n_tests = int(input())

    for _ in range(n_tests):
        n, p = map(int, input().split())

        try:
            print(calc.power(n, p))
        except Exception as e:
            print(e)


class Calculator:

    def power(self, n, p):

        if n < 0 or p < 0:
            raise Exception('n and p should be non-negative')
        return pow(n, p)


if __name__ == '__main__':
    main()
