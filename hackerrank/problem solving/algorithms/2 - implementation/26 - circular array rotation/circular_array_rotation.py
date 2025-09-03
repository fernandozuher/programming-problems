# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main():
    n, n_rotation, n_queries = read_numbers()
    arr = read_numbers()
    queries = [int(input()) for _ in range(n_queries)]

    r = n_rotation % n
    for q in queries:
        print(arr[q - r])


def read_numbers():
    return list(map(int, input().split()))


if __name__ == '__main__':
    main()
