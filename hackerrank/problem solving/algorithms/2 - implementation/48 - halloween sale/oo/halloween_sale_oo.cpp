// Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

#include <iostream>

using namespace std;

int read_a_number();

class Halloween_Sale
{
private:
    int game_default_price, discount, game_minimum_price, budget;
    int games_can_be_bought_quantity {0};

    void calculate_how_many_games_can_be_bought()
    {
        for (int current_game_price {this->game_default_price}, current_budget {this->budget - this->game_default_price}; current_budget >= 0;) {
            this->games_can_be_bought_quantity++;
            current_game_price -= this->discount;
            current_budget -= current_game_price >= this->game_minimum_price ? current_game_price : this->game_minimum_price;
        }
    }

public:
    Halloween_Sale(const int game_default_price, const int discount, const int game_minimum_price, const int budget)
        : game_default_price{game_default_price}, discount{discount}, game_minimum_price{game_minimum_price}, budget{budget}
    {
        calculate_how_many_games_can_be_bought();
    }

    int get_games_can_be_bought_quantity() const
    {
        return this->games_can_be_bought_quantity;
    }
};

int main()
{
    const int game_default_price {read_a_number()};
    const int discount {read_a_number()};
    const int game_minimum_price {read_a_number()};
    const int budget {read_a_number()};

    const Halloween_Sale OBJ {game_default_price, discount, game_minimum_price, budget};
    cout << OBJ.get_games_can_be_bought_quantity() << "\n";

    return 0;
}

    int read_a_number()
    {
        int number;
        cin >> number;
        return number;
    }
