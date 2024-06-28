# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main():
    n, k = read_int_array()
    array = read_int_array()
    array.sort()
    print(divisible_sum_pairs(array, k))


def read_int_array():
    return list(map(int, input().split()))


def divisible_sum_pairs(array, k):
    n_divisible_sum_pairs = 0

    for i, num1 in enumerate(array[:-1]):
        for num2 in array[i + 1:]:
            if num1 <= num2 and (num1 + num2) % k == 0:
                n_divisible_sum_pairs += 1

    return n_divisible_sum_pairs


if __name__ == '__main__':
    main()
