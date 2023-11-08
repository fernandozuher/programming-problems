# https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

def main():
    n = int(input())
    for i in range(n):
        count, lim = list(map(int, input().split()))
        print(bitwise_and(count, lim))


def bitwise_and(n, k):

    maximum_value_less_than_k = 0

    for i in range(1, n+1):
        for j in range(i+1, n+1):
            operation = i & j

            if operation < k and operation > maximum_value_less_than_k:
                if operation == k-1:
                    return operation
                else:
                    maximum_value_less_than_k = operation

    return maximum_value_less_than_k


if __name__ == '__main__':
    main()
