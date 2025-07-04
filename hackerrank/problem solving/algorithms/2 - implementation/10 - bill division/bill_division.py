# https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

from dataclasses import dataclass


def main():
    data = read_input()
    print_output(BillDivision(data).bon_appetit())


def read_input():
    _, item_not_eaten = read_numbers()
    meal_costs = read_numbers()
    amount_charged = int(input())
    return Input(item_not_eaten, meal_costs, amount_charged)


def read_numbers():
    return list(map(int, input().split()))


@dataclass
class Input:
    item_not_eaten: int
    meal_costs: list[int]
    amount_charged: int


class BillDivision:

    def __init__(self, data):
        self.__item_not_eaten = data.item_not_eaten
        self.__meal_costs = data.meal_costs
        self.__amount_charged = data.amount_charged

    def bon_appetit(self):
        return self.__amount_charged - self.__compute_actual_share()

    def __compute_actual_share(self):
        total_shared_cost = sum(self.__meal_costs) - self.__meal_costs[self.__item_not_eaten]
        return int(total_shared_cost / 2)


def print_output(charged):
    print(charged if charged else "Bon Appetit")


if __name__ == '__main__':
    main()
