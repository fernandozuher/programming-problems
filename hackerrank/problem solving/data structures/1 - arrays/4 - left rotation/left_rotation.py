# https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

def main():

    n, rotate_by = read_int_array()
    array = read_int_array()

    if rotate_by > n - 1:
        rotate_by %= n

    array = rotate(array, rotate_by)
    print(*array, sep= ' ')


def read_int_array():

    return list(map(int, input().split()))


def rotate(array, n):

    return array[n:] + array[:n]


if __name__ == '__main__':
    main()
