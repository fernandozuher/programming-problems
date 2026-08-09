# https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

from itertools import islice

import morfo


def main():
    morfo.skip_input_ln()
    chocolate_squares = morfo.readln(int, list)
    day_month = morfo.readln(int, list)
    print(birthday(chocolate_squares, day_month))


# n: length of chocolate_squares
# 1 <= n <= 100
# T: O(n) = O(100) = O(1)
# S: O(1) extra space
def birthday(chocolate_squares, day_month):
    day, month = day_month

    if month > len(chocolate_squares):
        return 0

    cur_sum = sum(islice(chocolate_squares, 0, month))
    count = int(cur_sum == day)

    for i in range(month, len(chocolate_squares)):
        cur_sum += chocolate_squares[i] - chocolate_squares[i - month]
        if cur_sum == day:
            count += 1

    return count


if __name__ == '__main__':
    main()
