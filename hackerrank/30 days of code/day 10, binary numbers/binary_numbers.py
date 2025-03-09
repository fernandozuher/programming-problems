# https://www.hackerrank.com/challenges/30-binary-numbers/problem?is_full_screen=true


def main():
    n = int(input())
    binary = bin(n)[2:]
    print(find_max_length_of_ones(binary))


def find_max_length_of_ones(binary):
    return max(len(segment) for segment in binary.split('0'))


if __name__ == '__main__':
    main()
