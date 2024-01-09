# https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

def main():

    n, item_anna_didnt_consume = read_int_array()
    cost_of_each_meal = read_int_array()
    brian_charged_anna = int(input())

    obj = BillDivision(cost_of_each_meal, item_anna_didnt_consume, brian_charged_anna)
    print_output(obj.brian_overcharged_anna())


def read_int_array():

    return list(map(int, input().split()))


class BillDivision:

    def __init__(self, cost_of_each_meal, item_anna_didnt_consume, brian_charged_anna):

        self._cost_of_each_meal = cost_of_each_meal
        self._item_anna_didnt_consume = item_anna_didnt_consume
        self._brian_charged_anna = brian_charged_anna
        self._brian_overcharged_anna = 0

        self._bon_appetit()


    def _bon_appetit(self):

        anna_cost = self._calculate_anna_cost()
        self._calculate_how_much_brian_overcharged_anna(anna_cost)


    def _calculate_anna_cost(self):

        sum_elements = sum(self._cost_of_each_meal)
        anna_cost = (sum_elements - self._cost_of_each_meal[self._item_anna_didnt_consume]) / 2
        return int(anna_cost)


    def _calculate_how_much_brian_overcharged_anna(self, anna_cost):

        if anna_cost != self._brian_charged_anna:
            self._brian_overcharged_anna = self._brian_charged_anna - anna_cost


    def brian_overcharged_anna(self):

        return self._brian_overcharged_anna


def print_output(charged):

    print(charged if charged else "Bon Appetit")


if __name__ == "__main__":
    main()
