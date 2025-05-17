# https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

def main():
    input()
    numbers = read_array()
    print(sum(numbers))


def read_array():
    return list(map(int, input().split()))


if __name__ == '__main__':
    main()
