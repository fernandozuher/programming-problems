# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    socks_to_counts = counter()
    print(sock_merchant(socks_to_counts))


# n: length of user input
# k: length of distinct numbers in user input
# T: O(n)
# S: O(n) extra space
def counter():
    return Counter(map(int, input().split()))


# n: length of initial user input
# k: length of entries in socks_to_counts
# k <= n
# T: O(k)
# S: O(1) extra space
def sock_merchant(socks_to_counts):
    return sum(x // 2 for x in socks_to_counts.values())


if __name__ == '__main__':
    main()
