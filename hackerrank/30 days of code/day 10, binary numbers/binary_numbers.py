# https://www.hackerrank.com/challenges/30-binary-numbers/problem?is_full_screen=true


def main():
    n = int(input())
    binary = int_to_binary(n)
    print(find_size_widest_range_bits_1_from(binary))


def int_to_binary(n):
    return bin(n)[2:]


def find_size_widest_range_bits_1_from(binary):
    size_widest_range = 0
    i = 0
    while i < len(binary):
        if binary[i] == '1':
            binary_from_i = binary[i:]
            size_range = find_size_next_range_bits_1_from(binary_from_i)
            size_widest_range = max(size_range, size_widest_range)
            i += size_range
        i += 1
    return size_widest_range


def find_size_next_range_bits_1_from(binary):
    index = binary.find('0')
    return index if index != -1 else len(binary)


if __name__ == '__main__':
    main()
