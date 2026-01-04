# https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

from dataclasses import dataclass


@dataclass
class Input:
    item_not_eaten: int
    meal_costs: list[int]
    amount_charged: int


def main():
    data = read_input()
    if charged := bon_appetit(data):
        print(charged)
    else:
        print("Bon Appetit")


def read_input():
    _, item_not_eaten = read_numbers()
    meal_costs = read_numbers()
    amount_charged = int(input())
    return Input(item_not_eaten, meal_costs, amount_charged)


def read_numbers():
    return list(map(int, input().split()))


# n: length of array data.meal_costs
# T: O(n)
# S: O(1) extra space
def bon_appetit(data):
    total_shared_cost = sum(data.meal_costs) - data.meal_costs[data.item_not_eaten]
    total_shared_cost //= 2
    return data.amount_charged - total_shared_cost


if __name__ == '__main__':
    main()
