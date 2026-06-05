# https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

from collections import Counter


def main():
    n = int(input())
    strings = read_lines(n)
    strings_to_counts = Counter(strings)

    n = int(input())
    queries = read_lines(n)

    print(*counts_from(strings_to_counts, queries), sep='\n')


def read_lines(n):
    return (input() for _ in range(n))


# n: length of queries
# max_query_string_length: 20
# T: O(n * max_query_string_length) = O(n * 20) = O(n)
# S: O(1) extra space
def counts_from(freq_map, queries):
    return (freq_map[q] for q in queries)


if __name__ == '__main__':
    main()
