# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main():
    _, k = read_numbers()
    numbers = read_numbers()
    print(divisible_sum_pairs(numbers, k))


def read_numbers():
    return list(map(int, input().split()))


# n: length of numbers
# k: length of freq
# T: O(n + k)
# S: O(k) extra space
def divisible_sum_pairs(numbers, k):
    freq = init_remainder_frequency(numbers, k)
    return (count_pairs_with_remainder_0(freq) +
            count_complementary_remainder_pairs(freq) +
            count_pairs_with_remainder_k_half(freq))


def init_remainder_frequency(numbers, k):
    freq = [0] * k
    for x in numbers:
        freq[x % k] += 1
    return freq


def count_pairs_with_remainder_0(freq):
    return pair_count(freq[0])


def pair_count(n):
    return n * (n - 1) // 2


def count_complementary_remainder_pairs(freq):
    return sum(freq[i] * freq[-i] for i in range(1, (len(freq) + 1) // 2))


def count_pairs_with_remainder_k_half(freq):
    n = len(freq)
    return pair_count(freq[n // 2]) if n % 2 == 0 else 0


if __name__ == '__main__':
    main()
