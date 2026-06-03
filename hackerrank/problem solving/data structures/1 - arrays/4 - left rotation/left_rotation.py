# https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

def main():
    n, rotate_by = read_numbers()
    arr = read_numbers()
    arr = rotate(arr, rotate_by)
    print(*arr, sep=' ')


def read_numbers():
    return list(map(int, input().split()))


# n: length of arr
# T: O(n)
# S: O(n) extra space
def rotate(arr, rotate_by):
    if rotate_by >= len(arr):
        rotate_by %= len(arr)
    return arr[rotate_by:] + arr[:rotate_by]


if __name__ == '__main__':
    main()
