// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

#include <stdio.h>

int how_many_games_can_be_bought(int price, int discount, int min_price, int budget);

int main()
{
    int price, discount, min_price, budget;
    scanf("%d %d %d %d", &price, &discount, &min_price, &budget);
    printf("%d\n", how_many_games_can_be_bought(price, discount, min_price, budget));
    return 0;
}

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
