# https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

from dataclasses import dataclass

import morfo


@dataclass(frozen=True)
class Gifts:
    n_black_gifts: int
    n_white_gifts: int
    black_gift_cost: int
    white_gift_cost: int
    cost_to_convert_between_gifts: int


def main():
    n = morfo.read(int)
    for _ in range(n):
        print(min_cost_of_buying_gifts(read_test_case()))


def read_test_case():
    return Gifts(*morfo.read(int, 5))


# T: O(1)
# S: O(1) extra space
def min_cost_of_buying_gifts(x):
    black_cost = min(x.black_gift_cost, x.white_gift_cost + x.cost_to_convert_between_gifts)
    white_cost = min(x.white_gift_cost, x.black_gift_cost + x.cost_to_convert_between_gifts)
    return x.n_black_gifts * black_cost + x.n_white_gifts * white_cost


if __name__ == '__main__':
    main()
