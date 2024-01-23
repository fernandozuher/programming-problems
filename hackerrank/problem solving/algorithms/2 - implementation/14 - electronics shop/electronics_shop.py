# https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

def main():

    budget, n_keyboard_costs, n_usb_drive_costs = read_int_array()
    keyboard_costs = read_int_array()
    usb_drive_costs = read_int_array()

    keyboard_costs.sort()
    usb_drive_costs.sort()

    obj = ElectronicsShop(keyboard_costs, usb_drive_costs, budget)
    print(obj.money_that_can_be_spent())


def read_int_array():

    return list(map(int, input().split()))


class ElectronicsShop:

    def __init__(self, keyboard_costs, usb_drive_costs, budget):

        self._keyboard_costs = keyboard_costs
        self._usb_drive_costs = usb_drive_costs
        self._budget = budget
        self._money_that_can_be_spent = 0
        self._calculate_money_spent()


    def _calculate_money_spent(self):

        for i in range(len(self._keyboard_costs)):

            if self._is_next_cost_equal_to_current_one(self._keyboard_costs, i):
                continue

            for j in range(len(self._usb_drive_costs)):

                if self._is_next_cost_equal_to_current_one(self._usb_drive_costs, j):
                    continue

                sum = self._keyboard_costs[i] + self._usb_drive_costs[j]

                if self._is_sum_affordable_by_budget(sum):
                    self._money_that_can_be_spent = self._update_cost(sum)
                else:
                    break

        self._money_that_can_be_spent = self._money_that_can_be_spent if self._money_that_can_be_spent else -1


    def _is_next_cost_equal_to_current_one(self, device_costs, i):

        return i < len(device_costs) - 1 and device_costs[i] == device_costs[i + 1]


    def _is_sum_affordable_by_budget(self, sum):

        return sum <= self._budget


    def _update_cost(self, sum):

        return max(sum, self._money_that_can_be_spent)


    def money_that_can_be_spent(self):

        return self._money_that_can_be_spent


if __name__ == "__main__":
    main()
