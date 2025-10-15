// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int[] arr = ReadNumbers();
        int price = arr[0];
        int discount = arr[1];
        int minPrice = arr[2];
        int budget = arr[3];
        Console.WriteLine(HowManyGamesCanBeBought(price, discount, minPrice, budget));
    }

    private static int[] ReadNumbers()
    {
        return Array.ConvertAll(Console.ReadLine()!.Split(' '), int.Parse);
    }

    private static int HowManyGamesCanBeBought(int price, int discount, int minPrice, int budget)
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
}
