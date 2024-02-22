# https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import math

def main():

    n = int(input())
    output = [None] * n

    for i in range(n):
        begin, end = read_int_array()
        obj = SherlockAndSquares(begin, end)
        output[i] = obj.square_integers()

    print(*output, sep='\n')


def read_int_array():

    return list(map(int, input().split()))


class SherlockAndSquares:
    
    def __init__(self, begin, end):

        self._begin = begin
        self._end = end
        self._square_integers = 0
        self._calculate_quantity_of_square_integers_in_range()


    def _calculate_quantity_of_square_integers_in_range(self):

        number = self._find_first_square_integer()
        while self._is_power_of_2_less_than_or_equal_to_limit(number):
            self._square_integers += 1
            number += 1


    def _find_first_square_integer(self):

        square_root = math.sqrt(self._begin)
        integer_part = math.trunc(square_root)
        return integer_part if square_root == integer_part else integer_part + 1


    def _is_power_of_2_less_than_or_equal_to_limit(self, x):

        return math.pow(x, 2) <= self._end


    def square_integers(self):

        return self._square_integers


if __name__ == '__main__':
    main()
