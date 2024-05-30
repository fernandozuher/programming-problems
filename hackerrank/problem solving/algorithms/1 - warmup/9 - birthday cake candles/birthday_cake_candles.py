# https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

def main():
    _ = int(input())
    array = read_int_array()
    print(birthday_cake_candles(array))


def read_int_array():
    return list(map(int, input().split()))


def birthday_cake_candles(candles):
    return candles.count(max(candles))


if __name__ == '__main__':
    main()
