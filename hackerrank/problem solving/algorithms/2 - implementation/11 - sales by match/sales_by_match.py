# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    sock_counts = counter()
    print(sock_merchant(sock_counts))


def counter():
    return Counter(map(int, input().split()))


# n: quantity of entries in sock_counts
# T: O(n)
# S: O(1) extra space
def sock_merchant(sock_counts):
    return sum(count // 2 for count in sock_counts.values())


if __name__ == '__main__':
    main()
