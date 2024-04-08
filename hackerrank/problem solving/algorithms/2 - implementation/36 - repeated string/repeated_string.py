# https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

def main():

    string = input()
    n_characters = int(input())
    letter = 'a'
    print(count_in_repeated_string(string, letter, n_characters))


def count_in_repeated_string(string, letter, n_characters):

    repeated_entire_string, n_substring = divmod(n_characters, len(string))
    substring = string[:n_substring]

    quantity = string.count(letter)
    quantity *= repeated_entire_string
    quantity += substring.count(letter)

    return quantity


if __name__ == '__main__':
    main()
