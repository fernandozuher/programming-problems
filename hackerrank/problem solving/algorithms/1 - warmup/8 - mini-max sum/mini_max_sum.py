# https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

def main():
    numbers = read_numbers()
    min_sum, max_sum = calc_min_max_sum(numbers)
    print(f"{min_sum} {max_sum}")


def read_numbers():
    return list(map(int, input().split()))


def calc_min_max_sum(numbers):
    total_sum = min_value = max_value = numbers[0]

    for x in numbers[1:]:
        total_sum += x
        min_value = min(x, min_value)
        max_value = max(x, max_value)

    return total_sum - max_value, total_sum - min_value


if __name__ == '__main__':
    main()
