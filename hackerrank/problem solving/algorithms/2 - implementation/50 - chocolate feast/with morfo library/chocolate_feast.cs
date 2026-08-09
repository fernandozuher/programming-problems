// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

using Morfo.IO;

int n = Reader.Read<int>();
for (int i = 0; i < n; i++)
{
    int[] arr = Reader.ReadLn<int, int[]>();
    int money = arr[0];
    int cost = arr[1];
    int wrappersNeeded = arr[2];
    Console.WriteLine(HowManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
}

// T: O(log(money / cost))
// S: O(1) extra space
int HowManyChocolatesCanBeEaten(int money, int cost, int wrappersNeeded)
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
