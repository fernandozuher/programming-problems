# https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

import morfo


def main():
    morfo.skip_input_ln()
    arr = morfo.readln(int, list)
    ratios = plus_minus(arr)
    print_ratios(ratios)


# n: length of arr
# T: O(n)
# S: O(1) extra space
def plus_minus(arr):
    positive, negative, zero = 0, 0, 0

    for number in arr:
        if number > 0:
            positive += 1
        elif number < 0:
            negative += 1
        else:
            zero += 1

    n = len(arr)
    return float(positive / n), float(negative / n), float(zero / n)


def print_ratios(ratios):
    for ratio in ratios:
        print(f"{ratio:.6f}")


if __name__ == '__main__':
    main()
