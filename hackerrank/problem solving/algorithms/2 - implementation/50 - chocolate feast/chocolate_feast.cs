// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int n = int.Parse(ReadLine());
        var output = new List<int>(new int[n]).Select(_ =>
        {
            var list = ReadLine().Split().Select(int.Parse).ToList();
            int amountOfMoney = list.First();
            int chocolateBarCost = list[1];
            int nWrappersToTurnInBar = list.Last();
            return HowManyChocolatesCanBeEaten(amountOfMoney, chocolateBarCost, nWrappersToTurnInBar);
        }).ToList();

        output.ForEach(WriteLine);
    }

        static int HowManyChocolatesCanBeEaten(int amountOfMoney, int chocolateBarCost, int nWrappersToTurnInBar)
        {
            int eatenChocolates = amountOfMoney / chocolateBarCost;

            for (int availableWrappers = eatenChocolates; availableWrappers >= nWrappersToTurnInBar;)
            {
                int chocolatesForFree = availableWrappers / nWrappersToTurnInBar;
                availableWrappers = availableWrappers - (chocolatesForFree * nWrappersToTurnInBar) + chocolatesForFree;
                eatenChocolates += chocolatesForFree;
            }

            return eatenChocolates;
        }
}
