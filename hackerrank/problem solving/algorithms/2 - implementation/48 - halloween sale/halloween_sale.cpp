// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

#include <iostream>

using namespace std;

int how_many_games_can_be_bought(int default_price_game, int discount, int minimum_price_game, int budget);

int main()
{
    int default_price_game, discount, minimum_price_game, budget;
    cin >> default_price_game >> discount >> minimum_price_game >> budget;
    cout << how_many_games_can_be_bought(default_price_game, discount, minimum_price_game, budget);

    return 0;
}

    int how_many_games_can_be_bought(const int default_price_game, const int discount,
                                     const int minimum_price_game, const int budget)
    {
        int games_can_be_bought_quantity{};

        for (int current_price_game{default_price_game}, current_budget{budget - default_price_game}; current_budget >= 0;) {
            ++games_can_be_bought_quantity;
            current_price_game -= discount;
            current_budget -= max(current_price_game, minimum_price_game);
        }

        return games_can_be_bought_quantity;
    }
