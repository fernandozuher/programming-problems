# https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

import morfo


def main():
    morfo.skip_input_ln()
    candles = morfo.readln(int, list)
    print(birthday_cake_candles(candles))


# n: length of candles
# T: O(2n) => O(n)
# S: O(1) extra space
def birthday_cake_candles(candles):
    return candles.count(max(candles))


if __name__ == '__main__':
    main()
