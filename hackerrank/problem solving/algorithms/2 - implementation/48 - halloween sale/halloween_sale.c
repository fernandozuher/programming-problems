// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

#include <stdio.h>

int how_many_games_can_be_bought(const int default_price_game, const int discount,
                                 const int minimum_price_game, const int budget);

int main()
{
    int default_price_game, discount, minimum_price_game, budget;
    scanf("%d %d %d %d", &default_price_game, &discount, &minimum_price_game, &budget);
    printf("%d\n", how_many_games_can_be_bought(default_price_game, discount, minimum_price_game, budget));

    return 0;
}

    int how_many_games_can_be_bought(const int default_price_game, const int discount,
                                     const int minimum_price_game, const int budget)
    {
        int games_can_be_bought_quantity = 0;

        for (int current_price_game = default_price_game, current_budget = budget - default_price_game; current_budget >= 0;) {
            ++games_can_be_bought_quantity;
            current_price_game -= discount;
            current_budget -= current_price_game >= minimum_price_game ? current_price_game : minimum_price_game;
        }

        return games_can_be_bought_quantity;
    }
