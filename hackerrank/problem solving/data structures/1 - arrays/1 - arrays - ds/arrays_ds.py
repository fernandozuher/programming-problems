# https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

def main():

    n = int(input())
    array = list(map(int, input().split()))
    array = reverse_array(array)
    print(*array, sep=' ')


def reverse_array(array):

    array.reverse()
    return array


if __name__ == '__main__':
    main()
