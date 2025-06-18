# https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

def main():
    input()
    chocolate_squares = read_numbers()
    day_month = read_numbers()
    print(birthday(chocolate_squares, day_month))


def read_numbers():
    return list(map(int, input().split()))


def birthday(chocolate_squares, day_month):
    day, month = day_month

    if month > len(chocolate_squares):
        return 0

    current_sum = sum(chocolate_squares[:month])
    ways_bar_can_be_divided = int(current_sum == day)

    for i in range(month, len(chocolate_squares)):
        current_sum += chocolate_squares[i] - chocolate_squares[i - month]
        if current_sum == day:
            ways_bar_can_be_divided += 1

    return ways_bar_can_be_divided


if __name__ == '__main__':
    main()
