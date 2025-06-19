# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true
from functools import reduce


def main():
    n, k = read_numbers()
    numbers = read_numbers()
    print(divisible_sum_pairs(numbers, k))


def read_numbers():
    return list(map(int, input().split()))


def divisible_sum_pairs(numbers, k):
    frequency = init_remainder_frequency(numbers, k)
    return count_pairs_with_remainder_0(frequency) + count_complementary_remainder_pairs(
        frequency) + count_pairs_with_remainder_k_half(frequency)


def init_remainder_frequency(numbers, k):
    frequency = [0] * k
    for x in numbers:
        frequency[x % k] += 1
    return frequency


def count_pairs_with_remainder_0(frequency):
    return pair_count(frequency[0])


def pair_count(n):
    return n * (n - 1) // 2


def count_complementary_remainder_pairs(frequency):
    count = 0
    k = len(frequency)
    for i in range(1, (k + 1) // 2):
        count += frequency[i] * frequency[k - i]
    return count


def count_pairs_with_remainder_k_half(frequency):
    k = len(frequency)
    return pair_count(frequency[k // 2]) if k % 2 == 0 else 0


if __name__ == '__main__':
    main()
