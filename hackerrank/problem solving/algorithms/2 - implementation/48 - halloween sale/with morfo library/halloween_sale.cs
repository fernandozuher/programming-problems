// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

using Morfo.IO;

var (price, discount, minPrice, budget) = Reader.Read<int, int, int, int>();
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
