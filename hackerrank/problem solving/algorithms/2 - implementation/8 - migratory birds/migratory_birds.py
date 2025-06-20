# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

from collections import Counter


def main():
    int(input())
    birds = read_numbers()
    print(find_most_spotted_bird(birds))


def read_numbers():
    return list(map(int, input().split()))


def find_most_spotted_bird(birds):
    bird_count = Counter(birds)
    max_count = max(bird_count.values())
    return min(bird for bird, count in bird_count.items() if count == max_count)


if __name__ == '__main__':
    main()
