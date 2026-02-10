// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

int[] arr = ReadNumbers();
int price = arr[0];
int discount = arr[1];
int minPrice = arr[2];
int budget = arr[3];
Console.WriteLine(HowManyGamesCanBeBought(price, discount, minPrice, budget));

int[] ReadNumbers() => Console.ReadLine()!.Split(' ').Select(int.Parse).ToArray();

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
