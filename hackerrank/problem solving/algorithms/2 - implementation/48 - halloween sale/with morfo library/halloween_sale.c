// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

#include <stdio.h>
#include "morfo/io.h"

int how_many_games_can_be_bought(int price, int discount, int min_price, int budget);

int main()
{
    int price = morfo_read(int);
    int discount = morfo_read(int);
    int min_price = morfo_read(int);
    int budget = morfo_read(int);
    printf("%d\n", how_many_games_can_be_bought(price, discount, min_price, budget));
    return 0;
}

// T: O(budget / min_price)
// S: O(1) extra space
int how_many_games_can_be_bought(int price, int discount, int min_price, int budget)
{
    int count = 0;
    while (budget >= price) {
        ++count;
        budget -= price;
        price = price - discount > min_price ? price - discount : min_price;
    }
    return count;
}
