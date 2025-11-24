# https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

def main():
    n = int(input())
    for _ in range(n):
        print(find_digits(int(input())))


def find_digits(n):
    return sum(d != 0 and n % d == 0 for d in map(int, str(n)))


if __name__ == '__main__':
    main()
