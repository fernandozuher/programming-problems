# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main():
    n, n_rotation, n_queries = read_numbers()
    arr = read_numbers()
    queries = [int(input()) for _ in range(n_queries)]
    print_queries(arr, queries, n_rotation)


def read_numbers():
    return list(map(int, input().split()))


def print_queries(arr, queries, n_rotation):
    r = n_rotation % len(arr)
    for q in queries:
        print(arr[q - r])


if __name__ == '__main__':
    main()
