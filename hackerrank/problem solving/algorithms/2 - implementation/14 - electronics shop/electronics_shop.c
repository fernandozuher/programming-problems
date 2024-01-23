// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* read_int_array(const int n);
int compare(const void* const a, const void* const b);
int calculate_money_spent(const int budget, const int* const keyboard_costs, const int* const usb_drive_costs, const int* const arrays_size);
    bool is_next_cost_equal_to_current_one(const int* const device_costs, const int device_costs_size, const int i);
    bool is_sum_affordable_by_budget(const int sum, const int budget);
    int update_cost(const int sum, const int money_that_can_be_spent);

int main()
{
    int budget, n_keyboard_costs, n_usb_drive_costs;
    scanf("%d %d %d", &budget, &n_keyboard_costs, &n_usb_drive_costs);

    int *keyboard_costs = read_int_array(n_keyboard_costs);
    int *usb_drive_costs = read_int_array(n_usb_drive_costs);

    qsort(keyboard_costs, n_keyboard_costs, sizeof(int), compare);
    qsort(usb_drive_costs, n_usb_drive_costs, sizeof(int), compare);

    int arrays_size[] = {n_keyboard_costs, n_usb_drive_costs};

    printf("%d\n", calculate_money_spent(budget, keyboard_costs, usb_drive_costs, arrays_size));

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int compare(const void* const a, const void* const b)
    {
        return (*(int*) a - * (int*) b);
    }

    int calculate_money_spent(const int budget, const int* const keyboard_costs, const int* const usb_drive_costs, const int* const arrays_size)
    {
        int money_that_can_be_spent = 0;

        for (int i = 0, n_keyboard_costs = arrays_size[0]; i < n_keyboard_costs; ++i) {

            if (is_next_cost_equal_to_current_one(keyboard_costs, n_keyboard_costs, i))
                continue;

            for (int j = 0, n_usb_drive_costs = arrays_size[1]; j < n_usb_drive_costs; ++j) {

                if (is_next_cost_equal_to_current_one(usb_drive_costs, n_usb_drive_costs, j))
                    continue;

                int sum = keyboard_costs[i] + usb_drive_costs[j];

                if (is_sum_affordable_by_budget(sum, budget))
                    money_that_can_be_spent = update_cost(sum, money_that_can_be_spent);
                else
                    break;
            }
        }

        return money_that_can_be_spent ? money_that_can_be_spent : -1;
    }

        bool is_next_cost_equal_to_current_one(const int* const device_costs, const int device_costs_size, const int i)
        {
            return i < device_costs_size - 1 && device_costs[i] == device_costs[i + 1];
        }

        bool is_sum_affordable_by_budget(const int sum, const int budget)
        {
            return sum <= budget;
        }

        int update_cost(const int sum, const int money_that_can_be_spent)
        {
            return sum > money_that_can_be_spent ? sum : money_that_can_be_spent;
        }
