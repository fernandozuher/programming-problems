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
    output = [0] * n

    for i in range(n):
        obj = TaumAndBday(read_test_case())
        obj.calculate_minimum_cost_of_buying_gifts()
        output[i] = obj.minimum_cost_of_buying_gifts()

    print(*output, sep='\n')


def read_test_case():
    array = read_int_array()
    array += read_int_array()
    return Gifts(*array)


def read_int_array():
    return list(map(int, input().split()))


class TaumAndBday:
    def __init__(self, gifts):
        self._gifts = gifts
        self._cost_to_convert_from_black_to_white = (self._gifts.black_gift_cost +
                                                     self._gifts.cost_to_convert_between_gifts)
        self._cost_to_convert_from_white_to_black = (self._gifts.white_gift_cost +
                                                     self._gifts.cost_to_convert_between_gifts)
        self._minimum_cost_of_buying_gifts = 0

    def calculate_minimum_cost_of_buying_gifts(self):
        self._minimum_cost_of_buying_gifts = self._calculate_minimum_standard_cost() if \
            self._are_original_costs_cheaper_or_equal_than_conversion_between_gifts() else \
            self._calculate_minimum_cost_in_converting_gifts()

    def _are_original_costs_cheaper_or_equal_than_conversion_between_gifts(self):
        return self._gifts.white_gift_cost <= self._cost_to_convert_from_black_to_white and \
            self._gifts.black_gift_cost <= self._cost_to_convert_from_white_to_black

    def _calculate_minimum_standard_cost(self):
        return self._gifts.n_black_gifts * self._gifts.black_gift_cost + \
            self._gifts.n_white_gifts * self._gifts.white_gift_cost

    def _calculate_minimum_cost_in_converting_gifts(self):
        total_gifts = self._gifts.n_black_gifts + self._gifts.n_white_gifts

        if self._gifts.white_gift_cost > self._cost_to_convert_from_black_to_white:
            return total_gifts * self._gifts.black_gift_cost + \
                self._gifts.n_white_gifts * self._gifts.cost_to_convert_between_gifts

        return total_gifts * self._gifts.white_gift_cost + \
            self._gifts.n_black_gifts * self._gifts.cost_to_convert_between_gifts

    def minimum_cost_of_buying_gifts(self):
        return self._minimum_cost_of_buying_gifts


if __name__ == '__main__':
    main()
