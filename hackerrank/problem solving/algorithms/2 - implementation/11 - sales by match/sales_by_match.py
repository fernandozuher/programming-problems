# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    sock_counts = read_numbers_into_map()
    print(sock_merchant(sock_counts))


def read_numbers_into_map():
    return Counter(map(int, input().split()))


def sock_merchant(sock_counts):
    return sum(count // 2 for count in sock_counts.values())


if __name__ == '__main__':
    main()
