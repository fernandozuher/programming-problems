# https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

def main():

    n = int(input())
    array = list(map(int, input().split()))
    print(a_very_big_sum(array))


def a_very_big_sum(array):

    return sum(array)


if __name__ == '__main__':
    main()
