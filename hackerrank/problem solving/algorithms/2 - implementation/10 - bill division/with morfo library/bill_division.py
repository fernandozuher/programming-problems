# https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

from dataclasses import dataclass

import morfo


@dataclass
class Input:
    item_not_eaten: int
    meal_costs: list[int]
    amount_charged: int


def main():
    data = read_input()
    charged = bon_appetit(data)
    print(morfo.or_if_falsy(charged, "Bon Appetit"))


def read_input():
    n = morfo.read(int)
    return Input(item_not_eaten=morfo.read(int), meal_costs=morfo.read(int, n), amount_charged=morfo.read(int))


# n: length of data.meal_costs
# T: O(n)
# S: O(1) extra space
def bon_appetit(data):
    total_shared_cost = sum(data.meal_costs) - data.meal_costs[data.item_not_eaten]
    total_shared_cost //= 2
    return data.amount_charged - total_shared_cost


if __name__ == '__main__':
    main()
