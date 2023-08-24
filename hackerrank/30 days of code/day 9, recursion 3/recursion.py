# https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

def main():

    n = int(input())
    print(factorial(n))


def factorial(n):

    return 1 if n == 1 else n * factorial(n - 1)


if __name__ == '__main__':
    main()
