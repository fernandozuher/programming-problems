// Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

#include <stdio.h>

int read_a_number();
int how_many_games_can_be_bought(const int game_default_price, const int discount, const int game_minimum_price, const int budget);

int main()
{
    const int game_default_price = read_a_number();
    const int discount = read_a_number();
    const int game_minimum_price = read_a_number();
    const int budget = read_a_number();

    printf("%d\n", how_many_games_can_be_bought(game_default_price, discount, game_minimum_price, budget));

    return 0;
}

    int read_a_number()
    {
        int number;
        scanf("%d", &number);
        return number;
    }

    int how_many_games_can_be_bought(const int game_default_price, const int discount, const int game_minimum_price, const int budget)
    {
        int games_can_be_bought_quantity = 0;

        for (int current_game_price = game_default_price, current_budget = budget - game_default_price; current_budget >= 0;) {
            games_can_be_bought_quantity++;
            current_game_price -= discount;
            current_budget -= current_game_price >= game_minimum_price ? current_game_price : game_minimum_price;
        }

        return games_can_be_bought_quantity;
    }
