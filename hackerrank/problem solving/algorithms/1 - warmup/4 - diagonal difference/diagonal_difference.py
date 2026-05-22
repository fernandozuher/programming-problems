# https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

def main():
    n = int(input())
    print(diagonal_difference(n))


# T: O(n^2)
# S: O(n) extra space
def diagonal_difference(n):
    primary_sum, secondary_sum = 0, 0

    for i in range(n):
        arr = read_numbers()
        primary_sum += arr[i]
        secondary_sum += arr[-i - 1]

    return abs(primary_sum - secondary_sum)


def read_numbers():
    return list(map(int, input().split()))


if __name__ == '__main__':
    main()
