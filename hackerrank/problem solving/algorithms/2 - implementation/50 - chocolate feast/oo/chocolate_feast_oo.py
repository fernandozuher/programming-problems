# Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

import math

def main():

    N_TEST_CASES = int(input())
    OUTPUT = solve_test_cases(N_TEST_CASES)
    print(*OUTPUT, sep="\n")


def solve_test_cases(n_test_cases):

    output = [0] * n_test_cases

    for i in range(n_test_cases):
        AMOUNT_OF_MONEY, CHOCOLATE_BAR_COST, N_WRAPPERS_TO_TURN_IN_BAR = list(map(int, input().split()))
        OBJ = ChocolateFeast(AMOUNT_OF_MONEY, CHOCOLATE_BAR_COST, N_WRAPPERS_TO_TURN_IN_BAR)
        output[i] = OBJ.get_eaten_chocolates()

    return output


class ChocolateFeast:

    def __init__(self, amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar):

        self._amount_of_money = amount_of_money
        self._chocolate_bar_cost = chocolate_bar_cost
        self._n_wrappers_to_turn_in_bar = n_wrappers_to_turn_in_bar
        self._eaten_chocolates = 0

        self._calculate_how_many_chocolates_can_be_eaten()


    def _calculate_how_many_chocolates_can_be_eaten(self):

        self._eaten_chocolates = math.trunc(self._amount_of_money / self._chocolate_bar_cost)
        available_wrappers = self._eaten_chocolates

        while available_wrappers >= self._n_wrappers_to_turn_in_bar:
            CHOCOLATES_FOR_FREE = math.trunc(available_wrappers / self._n_wrappers_to_turn_in_bar)
            available_wrappers = available_wrappers - (CHOCOLATES_FOR_FREE * self._n_wrappers_to_turn_in_bar) + CHOCOLATES_FOR_FREE
            self._eaten_chocolates += CHOCOLATES_FOR_FREE


    def get_eaten_chocolates(self):
        
        return self._eaten_chocolates


if __name__ == "__main__":
    main()
