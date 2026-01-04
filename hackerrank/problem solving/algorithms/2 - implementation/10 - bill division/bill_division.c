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

int main()
{
    input data = read_input();
    int charged = bon_appetit(&data);
    charged ? printf("%d\n", charged) : puts("Bon Appetit");
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
    auto arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    return arr;
}

// n: length of array data->meal_costs
// T: O(n)
// S: O(1) extra space
int bon_appetit(const input *data)
{
    int total_cost = 0;
    for (int i = 0; i < data->n; ++i)
        total_cost += data->meal_costs[i];

    int total_shared_cost = total_cost - data->meal_costs[data->item_not_eaten];
    total_shared_cost /= 2;
    return data->amount_charged - total_shared_cost;
}
