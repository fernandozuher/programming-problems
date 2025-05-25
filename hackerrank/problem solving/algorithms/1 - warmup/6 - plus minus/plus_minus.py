# https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

def main():
    input()
    numbers = read_numbers()
    ratios = plus_minus(numbers)
    print_ratios(ratios)


def read_numbers():
    return list(map(int, input().split()))


def plus_minus(numbers):
    positive, negative, zero = 0, 0, 0

    for number in numbers:
        if number > 0:
            positive += 1
        elif number < 0:
            negative += 1
        else:
            zero += 1

    n = len(numbers)
    return float(positive / n), float(negative / n), float(zero / n)


def print_ratios(ratios):
    for ratio in ratios:
        print(f"{ratio:.6f}")


if __name__ == '__main__':
    main()
