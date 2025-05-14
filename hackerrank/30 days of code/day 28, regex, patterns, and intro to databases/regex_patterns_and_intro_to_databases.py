# https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

def main():
    test_cases = int(input())
    for _ in range(test_cases):
        n, k = list(map(int, input().split()))
        print(bitwise_and(n, k))


def bitwise_and(n, k):
    if (k - 1 | k) <= n:
        return k - 1
    return k - 2


if __name__ == '__main__':
    main()
