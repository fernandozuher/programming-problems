# https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

def main():
    input()
    candles = read_numbers()
    print(birthday_cake_candles(candles))


def read_numbers():
    return list(map(int, input().split()))


def birthday_cake_candles(candles):
    return candles.count(max(candles))


if __name__ == '__main__':
    main()
