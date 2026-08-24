# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

import morfo


def main():
    n, n_rotation, n_queries = morfo.read(int, 3)
    arr = morfo.read(int, n)
    print(*queries(arr, n_rotation, n_queries), sep='\n')


# T: O(n_queries)
# S: O(1) extra space
def queries(arr, n_rotation, n_queries):
    offset = n_rotation % len(arr)
    for _ in range(n_queries):
        query = morfo.read(int)
        yield arr[query - offset]


if __name__ == '__main__':
    main()
