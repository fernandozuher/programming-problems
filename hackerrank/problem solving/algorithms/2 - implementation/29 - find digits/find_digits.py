# https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

def main():
    n = int(input())
    for _ in range(n):
        num = int(input())
        print(find_digits(num))


# k: quantity of digits of num = log num
# 0 < num < 10^9
# T: O(k) = O(9) = O(1)
# S: O(k) = O(9) = O(1) extra space
def find_digits(num):
    digits = map(int, str(num))
    return sum(d != 0 and num % d == 0 for d in digits)


if __name__ == '__main__':
    main()
