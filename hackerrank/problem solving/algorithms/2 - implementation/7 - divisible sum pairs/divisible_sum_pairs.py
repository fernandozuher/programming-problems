# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main():
    _, k = read_numbers()
    numbers = read_numbers()
    print(divisible_sum_pairs(numbers, k))


def read_numbers():
    return list(map(int, input().split()))


# n: length of array numbers
# k: length of array frequency
# T: O(n + k)
# S: O(k) extra space
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
    return sum(frequency[i] * frequency[-i] for i in range(1, (len(frequency) + 1) // 2))


def count_pairs_with_remainder_k_half(frequency):
    n = len(frequency)
    return pair_count(frequency[n // 2]) if n % 2 == 0 else 0


if __name__ == '__main__':
    main()
