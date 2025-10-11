# https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

from typing import NamedTuple


class Gifts(NamedTuple):
    n_black_gifts: int
    n_white_gifts: int
    black_gift_cost: int
    white_gift_cost: int
    cost_to_convert_between_gifts: int


def main():
    n = int(input())
    for _ in range(n):
        test_case = read_test_case()
        print(min_cost_of_buying_gifts(test_case))


def read_test_case():
    array = read_numbers()
    array.extend(read_numbers())
    return Gifts(*array)


def read_numbers():
    return list(map(int, input().split()))


def min_cost_of_buying_gifts(gifts):
    black_cost = min(gifts.black_gift_cost, gifts.white_gift_cost + gifts.cost_to_convert_between_gifts)
    white_cost = min(gifts.white_gift_cost, gifts.black_gift_cost + gifts.cost_to_convert_between_gifts)
    return gifts.n_black_gifts * black_cost + gifts.n_white_gifts * white_cost


if __name__ == '__main__':
    main()
