// Source: https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* read_line_as_int_array(const int n);
int compare (const void *a, const void *b);
int get_money_spent(const int budget, const int *keyboard_costs, const int *usb_drive_costs, const int *arrays_size);
    bool is_next_cost_equal_to_current_one(const int *device_costs, const int device_costs_size, const int current_index);
    bool is_sum_inside_budget(const int sum, const int budget);
    int update_cost(const int sum, const int can_be_spent);

int main() {
    const int *array_size = read_line_as_int_array(3);
    
    const int budget = array_size[0];
    const int n_keyboard_costs = array_size[1];
    const int n_usb_drive_costs = array_size[2];

    int *keyboard_costs = read_line_as_int_array(n_keyboard_costs);
    int *usb_drive_costs = read_line_as_int_array(n_usb_drive_costs);

    qsort(keyboard_costs, n_keyboard_costs, sizeof(int), compare);
    qsort(usb_drive_costs, n_usb_drive_costs, sizeof(int), compare);

    const int arrays_size[] = {n_keyboard_costs, n_usb_drive_costs};

    const int result = get_money_spent(budget, keyboard_costs, usb_drive_costs, arrays_size);
    printf("%d\n", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *inputLine = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &inputLine[i]);
        return inputLine;
    }

    int compare (const void *a, const void *b) {
        return (*(int*) a - *(int*) b);
    }

    int get_money_spent(const int budget, const int *keyboard_costs, const int *usb_drive_costs, const int *arrays_size) {
        int can_be_spent = 0;

        for (unsigned i = 0, n_keyboard_costs = arrays_size[0]; i < n_keyboard_costs; i++) {
            
            if (is_next_cost_equal_to_current_one(keyboard_costs, n_keyboard_costs, i))
                continue;

            for (unsigned j = 0, n_usb_drive_costs = arrays_size[1]; j < n_usb_drive_costs; j++) {
                
                if (is_next_cost_equal_to_current_one(usb_drive_costs, n_usb_drive_costs, j))
                    continue;

                const int sum = keyboard_costs[i] + usb_drive_costs[j];

                if (is_sum_inside_budget(sum, budget))
                    can_be_spent = update_cost(sum, can_be_spent);
                else
                    break;
            }
        }

        return can_be_spent ? can_be_spent : -1;
    }

        bool is_next_cost_equal_to_current_one(const int *device_costs, const int device_costs_size, const int current_index) {
            return current_index < device_costs_size - 1 && device_costs[current_index] == device_costs[current_index + 1];
        }

        bool is_sum_inside_budget(const int sum, const int budget) {
            return sum <= budget;
        }

        int update_cost(const int sum, const int can_be_spent) {
            return sum > can_be_spent ? sum : can_be_spent;
        }
