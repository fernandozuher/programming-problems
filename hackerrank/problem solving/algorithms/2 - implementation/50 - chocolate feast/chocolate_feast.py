# https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

import math


def main():
    n = int(input())
    output = [0] * n
    for i, _ in enumerate(output):
        amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar = list(map(int, input().split()))
        output[i] = how_many_chocolates_can_be_eaten(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar)
    print(*output, sep='\n')


def how_many_chocolates_can_be_eaten(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar):
    eaten_chocolates = math.trunc(amount_of_money / chocolate_bar_cost)
    available_wrappers = eaten_chocolates

    while available_wrappers >= n_wrappers_to_turn_in_bar:
        chocolates_for_free = math.trunc(available_wrappers / n_wrappers_to_turn_in_bar)
        available_wrappers = available_wrappers - chocolates_for_free * n_wrappers_to_turn_in_bar + chocolates_for_free
        eaten_chocolates += chocolates_for_free

    return eaten_chocolates


if __name__ == '__main__':
    main()
