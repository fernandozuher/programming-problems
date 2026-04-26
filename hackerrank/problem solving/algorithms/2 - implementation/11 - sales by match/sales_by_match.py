# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    socks_to_counts = Counter(read_numbers())
    print(sock_merchant(socks_to_counts))


def read_numbers():
    return list(map(int, input().split()))


# k: length of entries in socks_to_counts
# T: O(k)
# S: O(1) extra space
def sock_merchant(socks_to_counts):
    return sum(x // 2 for x in socks_to_counts.values())


if __name__ == '__main__':
    main()
