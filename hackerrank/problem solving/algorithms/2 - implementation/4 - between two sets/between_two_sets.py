# Source: https://www.hackerrank.com/challenges/between-two-sets/problem?is_full_screen=true

from functools import reduce

def main():

    read_int_array()
    set_a = read_int_array()
    set_b = read_int_array()

    set_a.sort()
    set_b.sort()

    result = BetweenTwoSets(set_a, set_b)
    print(result.total_factors())


def read_int_array():

    return list(map(int, input().split()))


class BetweenTwoSets:
    
    _set_a = []
    _set_b = []
    _potential_factors = []
    _total_factors = 0

    def __init__(self, set_a, set_b):

        self._set_a = set_a.copy()
        self._set_b = set_b.copy()

        self._find_factors()


    def _find_factors(self):

        self._find_numbers_divisible_by_set_a()
        self._find_factors_of_set_b()
        self._count_factors()


    def _find_numbers_divisible_by_set_a(self):

        last_element_of_set_a = self._set_a[-1]

        for potential_factor in range(last_element_of_set_a, self._set_b[0] + 1, last_element_of_set_a):
            is_aReal_potential_factor = True

            for element_a in self._set_a:
                if potential_factor % element_a:
                    is_aReal_potential_factor = False
                    break
                
            if is_aReal_potential_factor:
                self._potential_factors.append(potential_factor)
    

    def _find_factors_of_set_b(self):

        for element_b in self._set_b:
            for i, potential_factor in enumerate(self._potential_factors):
                if (potential_factor and element_b % potential_factor):
                    self._potential_factors[i] = 0


    def _count_factors(self):

        self._total_factors = reduce(lambda sum, item: (sum + 1) if item else sum, self._potential_factors, 0)


    def total_factors(self):

        return self._total_factors


if __name__ == "__main__":
    main()
