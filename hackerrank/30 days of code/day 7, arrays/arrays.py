# https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

def main():

    _n = int(input())
    array = list(map(int, input().split()))
    for x in reversed(array):
        print(x, end=' ')


if __name__ == '__main__':
    main()
