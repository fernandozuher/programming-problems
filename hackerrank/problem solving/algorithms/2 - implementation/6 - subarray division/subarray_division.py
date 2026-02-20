# https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true


from itertools import islice


def main():
    input()
    chocolate_squares = read_numbers()
    day_month = read_numbers()
    print(birthday(chocolate_squares, day_month))


def read_numbers():
    return list(map(int, input().split()))


# n: length of array chocolate_squares
# 1 <= n <= 100
# T: O(n) = O(100) = O(1) 
# S: O(1) extra space
def birthday(chocolate_squares, day_month):
    day, month = day_month

    if month > len(chocolate_squares):
        return 0

    cur_sum = sum(islice(chocolate_squares, 0, month))
    count = int(cur_sum == day)

    for i in range(month, len(chocolate_squares)):
        cur_sum += chocolate_squares[i] - chocolate_squares[i - month]
        if cur_sum == day:
            count += 1

    return count


if __name__ == '__main__':
    main()
