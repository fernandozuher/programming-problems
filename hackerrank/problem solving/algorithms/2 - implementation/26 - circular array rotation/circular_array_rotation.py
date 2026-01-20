# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main():
    _, n_rotation, n_queries = read_numbers()
    arr = read_numbers()
    print_queries(arr, n_rotation, n_queries)


def read_numbers():
    return list(map(int, input().split()))


# T: O(n_queries)
# S: O(1) extra space
def print_queries(arr, n_rotation, n_queries):
    offset = n_rotation % len(arr)
    for _ in range(n_queries):
        query = int(input())
        print(arr[query - offset])


if __name__ == '__main__':
    main()
