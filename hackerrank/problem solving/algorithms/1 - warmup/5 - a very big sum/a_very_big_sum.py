# https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

def main():
    input()
    numbers = read_numbers()
    print(a_very_big_sum(numbers))


def read_numbers():
    return list(map(int, input().split()))


def a_very_big_sum(numbers):
    return sum(numbers)


if __name__ == '__main__':
    main()
