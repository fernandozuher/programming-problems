# https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

def main():
    start_day, end_day, divisor = read_numbers()
    print(beautiful_days(start_day, end_day, divisor))


def read_numbers():
    return map(int, input().split())


# n: range (end_day - start_day + 1)
# d: number of digits of the largest day
# T: O(n * d)
# S: O(d) extra space
def beautiful_days(start_day, end_day, divisor):
    return sum(is_day_beautiful(day, divisor) for day in range(start_day, end_day + 1))


def is_day_beautiful(day, divisor):
    return (day - reverse_number(day)) % divisor == 0


def reverse_number(number):
    return int(str(number)[::-1])


if __name__ == '__main__':
    main()
