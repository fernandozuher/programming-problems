# https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

def main():
    lower_limit = int(input())
    upper_limit = int(input())
    valid_range = False

    for number in range(lower_limit, upper_limit + 1):
        if is_number_kaprekar(number):
            print(number, end=' ')
            valid_range = True

    if not valid_range:
        print("INVALID RANGE")


def is_number_kaprekar(number):
    square_number = number ** 2
    divisor = 10 ** number_digits(number)
    left_number, right_number = divmod(square_number, divisor)
    return number == left_number + right_number


def number_digits(n):
    if n < 10: return 1
    if n < 100: return 2
    if n < 1000: return 3
    if n < 10000: return 4
    if n < 100000: return 5
    if n < 1000000: return 6
    if n < 10000000: return 7
    return 8


if __name__ == '__main__':
    main()
