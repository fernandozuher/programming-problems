# https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

def main():

    n = int(input())
    array = list(map(int, input().split()))
    print(simple_array_sum(array))


def simple_array_sum(arr):

    return sum(arr)


if __name__ == '__main__':
    main()
