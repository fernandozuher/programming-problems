# https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

from itertools import islice


def main():
    string = input()
    n_chars = int(input())
    letter = 'a'
    print(count_in_repeated_string(string, letter, n_chars))


# n: length of string
# T: O(n)
# S: O(1) extra space
def count_in_repeated_string(string, letter, n_chars):
    full_repeats, n_substring = divmod(n_chars, len(string))

    count = string.count(letter)
    count *= full_repeats
    substring_count = sum(c == letter for c in islice(string, n_substring))
    return count + substring_count


if __name__ == '__main__':
    main()
