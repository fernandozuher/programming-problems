// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int bon_appetit(const int* const cost_of_each_meal, const int n, const int item_anna_didnt_consume, const int brian_charged_anna);
    int calculate_anna_cost(const int* const cost_of_each_meal, const int n, const int item_anna_didnt_consume);
    int calculate_how_much_brian_overcharged_anna(const int brian_charged_anna, const int anna_cost);
        char* convert_int_to_string(const int number);
void print_output(const int charged);

int main()
{
    int n, item_anna_didnt_consume;
    scanf("%d %d", &n, &item_anna_didnt_consume);
    int *cost_of_each_meal = read_int_array(n);

    int brian_charged_anna;
    scanf("%d", &brian_charged_anna);

    int brian_overcharged_anna = bon_appetit(cost_of_each_meal, n, item_anna_didnt_consume, brian_charged_anna);
    print_output(brian_overcharged_anna);

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int bon_appetit(const int* const cost_of_each_meal, const int n, const int item_anna_didnt_consume, const int brian_charged_anna)
    {
        int anna_cost = calculate_anna_cost(cost_of_each_meal, n, item_anna_didnt_consume);
        return calculate_how_much_brian_overcharged_anna(brian_charged_anna, anna_cost);
    }

        int calculate_anna_cost(const int* const cost_of_each_meal, const int n, const int item_anna_didnt_consume)
        {
            int sum = 0;
            for (int i = 0; i < n; sum += cost_of_each_meal[i++]);
            int anna_cost = (sum - cost_of_each_meal[item_anna_didnt_consume]) / 2;
            return anna_cost;
        }

        int calculate_how_much_brian_overcharged_anna(int brian_charged_anna, const int anna_cost)
        {
            return anna_cost != brian_charged_anna ? brian_charged_anna - anna_cost : 0;
        }

            char* convert_int_to_string(const int number)
            {
                char *number_string = (char*) calloc(5, sizeof(char));
                sprintf(number_string, "%d", number);
                return number_string;
            }

    void print_output(const int charged)
    {
        charged ? printf("%d", charged) : puts("Bon Appetit");
    }
