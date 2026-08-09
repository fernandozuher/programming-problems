# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

from collections import Counter

import morfo


def main():
    birds_to_counts = read_input()
    print(find_most_spotted_bird(birds_to_counts))


# n: length of input
# T: O(n)
# S: O(n) extra space
def read_input():
    morfo.skip_input_ln()
    return Counter(morfo.readln(int, list))


# n: length of birds_to_counts
# T: O(n)
# S: O(1) extra space
def find_most_spotted_bird(birds_to_counts):
    bird_id, _ = max(birds_to_counts.items(), key=lambda x: (x[1], -x[0]))
    return bird_id


if __name__ == '__main__':
    main()
