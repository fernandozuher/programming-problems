// Source: 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* read_line_as_int_array(const int n);
int compare (const void *a, const void *b);
int get_money_spent(const int budget, const int *keyboard_cost, const int *usb_drive_cost, const int *arrays_size);
    bool is_next_cost_equal_to_current_one(const int *array_cost, const int array_size, const int current_index);

int main() {
    const int *array_size = read_line_as_int_array(3);
    
    const int budget = array_size[0];
    const int n_keyboard_cost = array_size[1];
    const int n_usb_drive_cost = array_size[2];

    int *keyboard_cost = read_line_as_int_array(n_keyboard_cost);
    int *usb_drive_cost = read_line_as_int_array(n_usb_drive_cost);

    qsort(keyboard_cost, n_keyboard_cost, sizeof(int), compare);
    qsort(usb_drive_cost, n_usb_drive_cost, sizeof(int), compare);

    const int arrays_size[] = {n_keyboard_cost, n_usb_drive_cost};

    const int result = get_money_spent(budget, keyboard_cost, usb_drive_cost, arrays_size);
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

    int get_money_spent(const int budget, const int *keyboard_cost, const int *usb_drive_cost, const int *arrays_size) {
        int can_be_spent = 0;

        for (unsigned i = 0, n_keyboard_cost = arrays_size[0]; i < n_keyboard_cost; i++) {
            
            if (is_next_cost_equal_to_current_one(keyboard_cost, n_keyboard_cost, i))
                continue;

            for (unsigned j = 0, n_usb_drive_cost = arrays_size[1]; j < n_usb_drive_cost; j++) {
                
                if (is_next_cost_equal_to_current_one(usb_drive_cost, n_usb_drive_cost, j))
                    continue;

                int sum = keyboard_cost[i] + usb_drive_cost[j];
            
                if (sum <= budget && sum > can_be_spent)
                    can_be_spent = sum;
                else if (sum > budget)
                    break;
            }
        }

        return can_be_spent ? can_be_spent : -1;
    }

        bool is_next_cost_equal_to_current_one(const int *array_cost, const int array_size, const int current_index) {
            return current_index < array_size - 1 && array_cost[current_index] == array_cost[current_index + 1];
        }
