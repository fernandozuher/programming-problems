# https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

def main():
    n = int(input())
    print(factorial(n))


def factorial(n):
    res = 1
    for i in range(2, n + 1):
        res *= i
    return res


if __name__ == '__main__':
    main()
