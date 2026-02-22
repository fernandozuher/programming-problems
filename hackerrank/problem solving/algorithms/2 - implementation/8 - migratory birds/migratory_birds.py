# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    birds_to_counts = counter()
    print(find_most_spotted_bird(birds_to_counts))


# n: length of input
# k: length of distinct numbers
# T: O(n)
# S:
#   O(n) = input().split() temporary list
#   O(k) = O(n) for the counter
#   O(n + n) = O(n) extra space
def counter():
    return Counter(map(int, input().split()))


# n: length of input
# k: length of hash birds_to_counts
# T: O(k) = O(n)
# S: O(1) extra space
def find_most_spotted_bird(birds_to_counts):
    return max(birds_to_counts.items(), key=lambda x: (x[1], -x[0]))[0]


if __name__ == '__main__':
    main()
