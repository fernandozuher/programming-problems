# https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

def main():
    n = int(input())
    staircase(n)


def staircase(n):
    for i in range(1, n + 1):
        for _ in range(n - i):
            print(' ', end='')
        for _ in range(i):
            print('#', end='')
        print('')


if __name__ == '__main__':
    main()
