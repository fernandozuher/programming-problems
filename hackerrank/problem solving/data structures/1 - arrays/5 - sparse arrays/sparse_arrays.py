# https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

from collections import Counter


def main():
    n = int(input())
    strings = read_lines(n)
    freq_map = Counter(strings)

    n = int(input())
    queries = read_lines(n)

    print(*count_matches(freq_map, queries), sep='\n')


def read_lines(n):
    return (input() for _ in range(n))


# n: length of queries
# T: O(n)
# S: O(1) extra space
def count_matches(freq_map, queries):
    return (freq_map[q] for q in queries)


if __name__ == '__main__':
    main()
