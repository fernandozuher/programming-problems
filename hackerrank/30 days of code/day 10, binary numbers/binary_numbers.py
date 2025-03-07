# https://www.hackerrank.com/challenges/30-binary-numbers/problem?is_full_screen=true


def main():
    n = int(input())
    binary = format(n, "b")
    print(max_consecutive_ones_from(binary))


def max_consecutive_ones_from(binary):
    max_1_bits = 0
    i = 0
    while i < len(binary):
        if binary[i] == '1':
            n_bits = size_of_next_range_of_bits_1(binary, i)
            max_1_bits = max(n_bits, max_1_bits)
            i += n_bits
        i += 1
    return max_1_bits


def size_of_next_range_of_bits_1(binary, begin_index):
    next_after_last_index = find_next_after_last_index_of_consecutive_1s(binary, begin_index)
    return next_after_last_index - begin_index


def find_next_after_last_index_of_consecutive_1s(binary, begin_index):
    next_after_last_index = binary[begin_index:].find('0')
    if next_after_last_index == -1:
        return len(binary)
    # + begin_index because index was found from that, not from index 0
    return next_after_last_index + begin_index


if __name__ == '__main__':
    main()
