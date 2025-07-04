// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n, item_not_eaten;
    int *meal_costs;
    int amount_charged;
} input;

input read_input();
int *read_numbers(int n);
int bon_appetit(const input *data);
int compute_actual_share(const input *data);
void print_output(int charged);

int main()
{
    input data = read_input();
    print_output(bon_appetit(&data));
    free(data.meal_costs);
    return 0;
}

input read_input()
{
    int n, item_not_eaten;
    scanf("%d %d", &n, &item_not_eaten);
    int *meal_costs = read_numbers(n);
    int amount_charged;
    scanf("%d", &amount_charged);
    return (input){n, item_not_eaten, meal_costs, amount_charged};
}

int *read_numbers(int n)
{
    auto numbers = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
    return numbers;
}

int bon_appetit(const input *data)
{
    return data->amount_charged - compute_actual_share(data);
}

int compute_actual_share(const input *data)
{
    int total_cost = 0;
    for (int i = 0; i < data->n; ++i)
        total_cost += data->meal_costs[i];
    int total_shared_cost = total_cost - data->meal_costs[data->item_not_eaten];
    return total_shared_cost / 2;
}

void print_output(int charged)
{
    charged ? printf("%d\n", charged) : puts("Bon Appetit");
}
