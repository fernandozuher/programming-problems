# Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

def main():

    array = read_int_array()
    print(kangaroo(array))


def read_int_array():

    return list(map(int, input().split()))


def kangaroo(array):

    x1, v1, x2, v2 = array

    if v2 >= v1:
        return 'NO'

    while x1 < x2:
        x1 += v1
        x2 += v2

    return 'YES' if x1 == x2 else 'NO'


if __name__ == '__main__':
    main()
