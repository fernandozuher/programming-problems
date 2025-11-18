# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main():
    _, n_rotation, n_queries = read_numbers()
    arr = read_numbers()
    print_queries(arr, n_rotation, n_queries)


def read_numbers():
    return list(map(int, input().split()))


def print_queries(arr, n_rotation, n_queries):
    r = n_rotation % len(arr)
    for _ in range(n_queries):
        query = int(input())
        print(arr[query - r])


if __name__ == '__main__':
    main()
