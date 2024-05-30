# https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

def main():
    n = int(input())
    print(diagonal_difference(n))


def diagonal_difference(n):
    primary_diagonal, secondary_diagonal = 0, 0
    primary_diagonal_range = range(n)
    secondary_diagonal_range = range(n - 1, -1, -1)

    for i, j in zip(primary_diagonal_range, secondary_diagonal_range):
        line = list(map(int, input().split()))
        primary_diagonal += line[i]
        secondary_diagonal += line[j]

    return abs(primary_diagonal - secondary_diagonal)


if __name__ == '__main__':
    main()
