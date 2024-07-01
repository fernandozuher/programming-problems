# https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

def main():
    data = Input
    _, data.item_anna_didnt_consume = read_int_array()
    data.cost_of_each_meal = read_int_array()
    data.brian_charged_anna = int(input())

    obj = BillDivision(data)
    obj.bon_appetit()
    print_output(obj.brian_overcharged_anna())


class Input:
    item_anna_didnt_consume: int
    cost_of_each_meal: [int]
    brian_charged_anna: int


def read_int_array():
    return list(map(int, input().split()))


def print_output(charged):
    print(charged if charged else "Bon Appetit")


class BillDivision:

    def __init__(self, data):
        self._item_anna_didnt_consume = data.item_anna_didnt_consume
        self._cost_of_each_meal = data.cost_of_each_meal
        self._brian_charged_anna = data.brian_charged_anna
        self._brian_overcharged_anna = 0

    def bon_appetit(self):
        anna_cost = self._calculate_anna_cost()
        self._how_much_brian_overcharged_anna(anna_cost)

    def _calculate_anna_cost(self):
        sum_elements = sum(self._cost_of_each_meal)
        return int((sum_elements - self._cost_of_each_meal[self._item_anna_didnt_consume]) / 2)

    def _how_much_brian_overcharged_anna(self, anna_cost):
        if anna_cost != self._brian_charged_anna:
            self._brian_overcharged_anna = self._brian_charged_anna - anna_cost

    def brian_overcharged_anna(self):
        return self._brian_overcharged_anna


if __name__ == '__main__':
    main()
