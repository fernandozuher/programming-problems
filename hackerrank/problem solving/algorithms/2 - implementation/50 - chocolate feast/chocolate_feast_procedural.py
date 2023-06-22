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
        output[i] = how_many_chocolates_can_be_eaten(AMOUNT_OF_MONEY, CHOCOLATE_BAR_COST, N_WRAPPERS_TO_TURN_IN_BAR)

    return output


def how_many_chocolates_can_be_eaten(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar):

    eaten_chocolates = math.trunc(amount_of_money / chocolate_bar_cost)
    available_wrappers = eaten_chocolates

    while available_wrappers >= n_wrappers_to_turn_in_bar:
        CHOCOLATES_FOR_FREE = math.trunc(available_wrappers / n_wrappers_to_turn_in_bar)
        available_wrappers = available_wrappers - (CHOCOLATES_FOR_FREE * n_wrappers_to_turn_in_bar) + CHOCOLATES_FOR_FREE
        eaten_chocolates += CHOCOLATES_FOR_FREE

    return eaten_chocolates


if __name__ == "__main__":
    main()
