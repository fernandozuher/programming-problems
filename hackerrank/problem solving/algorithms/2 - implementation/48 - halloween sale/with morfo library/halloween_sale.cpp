// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int how_many_games_can_be_bought(int price, int discount, int min_price, int budget);

int main()
{
    auto [price, discount, min_price, budget] = morfo::read<int, int, int, int>();
    cout << how_many_games_can_be_bought(price, discount, min_price, budget);
    return 0;
}

// T: O(budget / min_price)
// S: O(1) extra space
int how_many_games_can_be_bought(int price, int discount, int min_price, int budget)
{
    int count{};
    while (budget >= price) {
        ++count;
        budget -= price;
        price = max(price - discount, min_price);
    }
    return count;
}
