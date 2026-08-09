// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

using Morfo.IO;

int price = Reader.Read<int>();
int discount = Reader.Read<int>();
int minPrice = Reader.Read<int>();
int budget = Reader.Read<int>();
Console.WriteLine(HowManyGamesCanBeBought(price, discount, minPrice, budget));

// T: O(budget / minPrice)
// S: O(1) extra space
int HowManyGamesCanBeBought(int price, int discount, int minPrice, int budget)
{
    int count = 0;
    while (budget >= price)
    {
        count++;
        budget -= price;
        price = Math.Max(price - discount, minPrice);
    }
    return count;
}
