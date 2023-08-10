# https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

def main():

    N = int(input())
    print(factorial(N))


def factorial(n):

    return 1 if n == 1 else n * factorial(n - 1)


if __name__ == "__main__":
    main()
