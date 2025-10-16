// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine()!);
        for (int i = 0; i < n; i++)
        {
            var list = ReadNumbers();
            int money = list[0];
            int cost = list[1];
            int wrappersNeeded = list[2];
            Console.WriteLine(HowManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
        }
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int HowManyChocolatesCanBeEaten(int money, int cost, int wrappersNeeded)
    {
        int chocolates = money / cost;

        for (int wrappers = chocolates; wrappers >= wrappersNeeded;)
        {
            int freeChocolates = wrappers / wrappersNeeded;
            wrappers = wrappers % wrappersNeeded + freeChocolates;
            chocolates += freeChocolates;
        }

        return chocolates;
    }
}
