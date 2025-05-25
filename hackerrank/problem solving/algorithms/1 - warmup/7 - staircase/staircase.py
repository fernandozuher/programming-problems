# https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

def main():
    n = int(input())
    staircase(n)


def staircase(n):
    for i in range(1, n + 1):
        spaces = ' ' * (n - i)
        hashes = '#' * i
        print(spaces + hashes)


if __name__ == '__main__':
    main()
