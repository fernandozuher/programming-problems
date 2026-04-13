// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

int n = int.Parse(Console.ReadLine()!);
for (int i = 0; i < n; i++)
{
    var arr = ReadNumbers();
    int money = arr[0];
    int cost = arr[1];
    int wrappersNeeded = arr[2];
    Console.WriteLine(HowManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
}

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

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
