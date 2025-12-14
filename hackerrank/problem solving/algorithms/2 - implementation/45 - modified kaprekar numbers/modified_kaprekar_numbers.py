# https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

def main():
    lower = int(input())
    upper = int(input())
    valid_range = False

    for num in range(lower, upper + 1):
        if is_number_kaprekar(num):
            print(num, end=' ')
            valid_range = True

    if not valid_range:
        print("INVALID RANGE")


def is_number_kaprekar(n):
    square_number = n ** 2
    divisor = 10 ** number_digits(n)
    left_number, right_number = divmod(square_number, divisor)
    return n == left_number + right_number


def number_digits(n):
    return len(str(n))


if __name__ == '__main__':
    main()
