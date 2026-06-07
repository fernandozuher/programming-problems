# https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

from itertools import accumulate


def main():
    n, n_queries = read_numbers()
    print(array_manipulation(n, n_queries))


def read_numbers():
    return list(map(int, input().split()))


# T: O(n + n_queries)
# S: O(n) extra space
def array_manipulation(n, n_queries):
    arr = populate_arr(n, n_queries)
    return max(accumulate(arr))


def populate_arr(n, n_queries):
    arr = [0] * (n + 2)  # +2 = 1-indexed array + range-end
    for _ in range(n_queries):
        b, e, summand = read_numbers()
        arr[b] += summand
        arr[e + 1] -= summand
    return arr


if __name__ == '__main__':
    main()
