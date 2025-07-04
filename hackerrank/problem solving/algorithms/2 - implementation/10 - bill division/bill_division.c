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
int calculate_overcharge(int amount_charged, int individual_share);
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
    auto array = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);
    return array;
}

int bon_appetit(const input *data)
{
    int individual_share = compute_actual_share(data);
    return calculate_overcharge(data->amount_charged, individual_share);
}

int compute_actual_share(const input *data)
{
    int sum = 0;
    for (int i = 0; i < data->n; ++i)
        sum += data->meal_costs[i];
    int splitting_cost_between_two_people = (sum - data->meal_costs[data->item_not_eaten]) / 2;
    return splitting_cost_between_two_people;
}

int calculate_overcharge(int amount_charged, int individual_share)
{
    return individual_share != amount_charged ? amount_charged - individual_share : 0;
}

void print_output(int charged)
{
    charged ? printf("%d\n", charged) : puts("Bon Appetit");
}
