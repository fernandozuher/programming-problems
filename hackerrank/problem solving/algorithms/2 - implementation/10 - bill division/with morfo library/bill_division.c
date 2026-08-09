// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

typedef struct {
    int n, item_not_eaten;
    int *meal_costs;
    int amount_charged;
} input;

input read_input();
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
    int n = morfo_read(int);
    int item_not_eaten = morfo_read(int);
    int *meal_costs = morfo_read_n_alloc(int, n);
    int amount_charged = morfo_read(int);
    return (input){n, item_not_eaten, meal_costs, amount_charged};
}

// n: length of data->meal_costs
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
