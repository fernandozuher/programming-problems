# https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

import morfo


def main():
    n = morfo.read(int)
    for _ in range(n):
        num = morfo.read(int)
        print(find_digits(num))


# k: quantity of digits of num = log num
# 0 < num < 10^9
# T: O(k) = O(9) = O(1)
# S: O(k) = O(9) = O(1) extra space
def find_digits(num):
    digits = map(int, str(num))
    return sum(d and num % d == 0 for d in digits)


if __name__ == '__main__':
    main()
