# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

from collections import Counter


def main():
    input()
    bird_counts = counter()
    print(find_most_spotted_bird(bird_counts))


def counter():
    return Counter(map(int, input().split()))


def find_most_spotted_bird(bird_counts):
    max_count = max(bird_counts.values())
    return min(bird for bird, count in bird_counts.items() if count == max_count)


if __name__ == '__main__':
    main()
