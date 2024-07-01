// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n, item_anna_didnt_consume;
    int *cost_of_each_meal;
    int brian_charged_anna;
} input;

int *read_int_array(int n);
int bon_appetit(const input *data);
    int calculate_anna_cost(const input *data);
    int how_much_brian_overcharged_anna(int brian_charged_anna, int anna_cost);
void print_output(int charged);

int main()
{
    int n, item_anna_didnt_consume;
    scanf("%d %d", &n, &item_anna_didnt_consume);
    int *cost_of_each_meal = read_int_array(n);

    int brian_charged_anna;
    scanf("%d", &brian_charged_anna);

    input data = {n, item_anna_didnt_consume, cost_of_each_meal, brian_charged_anna};
    int brian_overcharged_anna = bon_appetit(&data);
    print_output(brian_overcharged_anna);

    free(cost_of_each_meal);

    return 0;
}

    int *read_int_array(const int n)
    {
        auto array = (int*) malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    int bon_appetit(const input *data)
    {
        int anna_cost = calculate_anna_cost(data);
        return how_much_brian_overcharged_anna(data->brian_charged_anna, anna_cost);
    }

        int calculate_anna_cost(const input *data)
        {
            int sum = 0;
            for (int i = 0; i < data->n; ++i)
                sum += data->cost_of_each_meal[i];
            return (sum - data->cost_of_each_meal[data->item_anna_didnt_consume]) / 2;
        }

        int how_much_brian_overcharged_anna(const int brian_charged_anna, const int anna_cost)
        {
            return anna_cost != brian_charged_anna ? brian_charged_anna - anna_cost : 0;
        }

    void print_output(const int charged)
    {
        charged ? printf("%d", charged) : puts("Bon Appetit");
    }
