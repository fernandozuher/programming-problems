// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

#include <iostream>

using namespace std;

int how_many_games_can_be_bought(int price, int discount, int min_price, int budget);

int main()
{
    int price, discount, min_price, budget;
    cin >> price >> discount >> min_price >> budget;
    cout << how_many_games_can_be_bought(price, discount, min_price, budget);
    return 0;
}

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
