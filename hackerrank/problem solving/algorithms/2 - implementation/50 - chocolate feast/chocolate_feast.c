// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

#include <stdio.h>

int how_many_chocolates_can_be_eaten(int amount_of_money, int chocolate_bar_cost, int n_wrappers_to_turn_in_bar);

int main() {
    int n;
    scanf("%d", &n);
    int output[n];

    for (int i = 0; i < n; ++i) {
        int amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar;
        scanf("%d %d %d", &amount_of_money, &chocolate_bar_cost, &n_wrappers_to_turn_in_bar);
        output[i] = how_many_chocolates_can_be_eaten(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar);
    }

    for (int i = 0; i < n; ++i)
        printf("%d\n", output[i]);

    return 0;
}

    int how_many_chocolates_can_be_eaten(const int amount_of_money, const int chocolate_bar_cost,
                                         const int n_wrappers_to_turn_in_bar) {
        int eaten_chocolates = amount_of_money / chocolate_bar_cost;

        for (int available_wrappers = eaten_chocolates; available_wrappers >= n_wrappers_to_turn_in_bar;) {
            int chocolates_for_free = available_wrappers / n_wrappers_to_turn_in_bar;
            available_wrappers = available_wrappers - (chocolates_for_free * n_wrappers_to_turn_in_bar) +
                                 chocolates_for_free;
            eaten_chocolates += chocolates_for_free;
        }

        return eaten_chocolates;
    }
