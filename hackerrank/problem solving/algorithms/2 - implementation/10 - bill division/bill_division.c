// Source: https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_line_as_int_array(const int n);
char* bon_appetit(const int *cost_of_each_meal, const int n, const int item_anna_didnt_consume, const int brian_charged_anna);
    int calculate_anna_cost(const int *cost_of_each_meal, const int n, const int item_anna_didnt_consume);
    char* check_if_brian_overcharged_anna(const int brian_charged_anna, const int anna_cost);
    char *convert_int_to_string(const int number);

int main() {
    const int *input1 = read_line_as_int_array(2);
    const int n = input1[0];
    const int item_anna_didnt_consume = input1[1];

    const int *cost_of_each_meal = read_line_as_int_array(n);
    const int *brian_charged_anna = read_line_as_int_array(1);

    const char *result = bon_appetit(cost_of_each_meal, n, item_anna_didnt_consume, brian_charged_anna[0]);
    printf("%s\n", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        return array;
    }

    char* bon_appetit(const int *cost_of_each_meal, const int n, const int item_anna_didnt_consume, const int brian_charged_anna) {
        const int anna_cost = calculate_anna_cost(cost_of_each_meal, n, item_anna_didnt_consume);
        const char *result = check_if_brian_overcharged_anna(brian_charged_anna, anna_cost);
        return result;
    }

        int calculate_anna_cost(const int *cost_of_each_meal, const int n, const int item_anna_didnt_consume) {
            int sum = 0;
            for (int i = 0; i < n; sum += cost_of_each_meal[i++]);
            int anna_cost = (sum - cost_of_each_meal[item_anna_didnt_consume]) / 2;
            return anna_cost;
        }

        char* check_if_brian_overcharged_anna(const int brian_charged_anna, const int anna_cost) {
            if (anna_cost == brian_charged_anna)
                return "Bon Appetit";
            else {
                const int brian_overcharged_ana = brian_charged_anna - anna_cost;
                return convert_int_to_string(brian_overcharged_ana);
            }
        }

            char *convert_int_to_string(const int number) {
                char *number_string = (char*) calloc(5, sizeof(char));
                sprintf(number_string, "%d", number);
                return number_string;
            }
