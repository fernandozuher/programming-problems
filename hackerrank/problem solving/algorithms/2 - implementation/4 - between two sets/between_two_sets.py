# https://www.hackerrank.com/challenges/between-two-sets/problem?is_full_screen=true

def main():
    read_int_array()
    set_a = read_int_array()
    set_b = read_int_array()

    set_a.sort()
    set_b.sort()

    obj = BetweenTwoSets(set_a, set_b)
    obj.find_factors()
    print(obj.total_factors())


def read_int_array():
    return list(map(int, input().split()))


class BetweenTwoSets:

    def __init__(self, set_a, set_b):
        self._set_a = set_a
        self._set_b = set_b
        self._potential_factors = []
        self._total_factors = 0

    def find_factors(self):
        self._find_numbers_divisible_by_set_a()
        self._find_factors_of_set_b()
        self._count_factors()

    def _find_numbers_divisible_by_set_a(self):
        last_element_of_set_a = self._set_a[-1]

        for potential_factor in range(last_element_of_set_a, self._set_b[0] + 1, last_element_of_set_a):
            is_a_real_potential_factor = True

            for x in self._set_a:
                if potential_factor % x:
                    is_a_real_potential_factor = False
                    break

            if is_a_real_potential_factor:
                self._potential_factors.append(potential_factor)

    def _find_factors_of_set_b(self):
        for x in self._set_b:
            for i, potential_factor in enumerate(self._potential_factors):
                if potential_factor and x % potential_factor:
                    self._potential_factors[i] = 0

    def _count_factors(self):
        self._total_factors = sum(1 for x in self._potential_factors if x)

    def total_factors(self):
        return self._total_factors


if __name__ == '__main__':
    main()
