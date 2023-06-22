// Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

using System;

public class ChocolateFeast
{
    public static void Main()
    {
        int nTestCases = int.Parse(Console.ReadLine());
        List<int> output = _solveTestCases(nTestCases);
        output.ForEach(Console.WriteLine);
    }

        private static List<int> _solveTestCases(int nTestCases)
        {
            List<int> output = new List<int>(new int [nTestCases]);

            for (int i = 0; i < nTestCases; i++)
            {
                List<int> testCase = Console.ReadLine().Split().Select(int.Parse).ToList();
                int amountOfMoney = testCase.First();
                int chocolateBarCost = testCase[1];
                int nWrappersToTurnInBar = testCase.Last();
                output[i] = _howManyChocolatesCanBeEaten(amountOfMoney, chocolateBarCost, nWrappersToTurnInBar);
            }

            return output;
        }

            private static int _howManyChocolatesCanBeEaten(int amountOfMoney, int chocolateBarCost, int nWrappersToTurnInBar)
            {
                int eatenChocolates = amountOfMoney / chocolateBarCost;

                for (int availableWrappers = eatenChocolates; availableWrappers >= nWrappersToTurnInBar; )
                {
                    int chocolatesForFree = availableWrappers / nWrappersToTurnInBar;
                    availableWrappers = availableWrappers - (chocolatesForFree * nWrappersToTurnInBar) + chocolatesForFree;
                    eatenChocolates += chocolatesForFree;
                }

                return eatenChocolates;
            }
}
