# https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

def main():
    input()
    chocolate_squares = read_int_array()
    day_month = read_int_array()
    print(birthday(chocolate_squares, day_month))


def read_int_array():
    return list(map(int, input().split()))


def birthday(chocolate_squares, day_month):
    ways_bar_can_be_divided = 0
    day, month = day_month

    for i in range(0, len(chocolate_squares) - month + 1):
        if sum(chocolate_squares[i:i + month]) == day:
            ways_bar_can_be_divided += 1

    return ways_bar_can_be_divided


if __name__ == '__main__':
    main()
