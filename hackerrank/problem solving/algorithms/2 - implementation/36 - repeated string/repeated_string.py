# https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

from itertools import islice


def main():
    string = input()
    n_characters = int(input())
    letter = 'a'
    print(count_in_repeated_string(string, letter, n_characters))


# n: length of string
# T: O(n)
# S: O(1) extra space
def count_in_repeated_string(string, letter, n_characters):
    full_repeats, n_substring = divmod(n_characters, len(string))

    count = string.count(letter)
    count *= full_repeats
    substring_count = sum(ch == letter for ch in islice(string, n_substring))
    return count + substring_count


if __name__ == '__main__':
    main()
