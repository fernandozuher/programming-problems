// Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

using System;

public class Solution
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

                ChocolateFeast obj = new ChocolateFeast(amountOfMoney, chocolateBarCost, nWrappersToTurnInBar);
                output[i] = obj.GetEatenChocolates();
            }

            return output;
        }
}

    public class ChocolateFeast
    {
        private int _amountOfMoney, _chocolateBarCost, _nWrappersToTurnInBar;
        private int _eatenChocolates;

        public ChocolateFeast(int amountOfMoney, int chocolateBarCost, int nWrappersToTurnInBar)
        {
            _amountOfMoney = amountOfMoney;
            _chocolateBarCost = chocolateBarCost;
            _nWrappersToTurnInBar = nWrappersToTurnInBar;
            _eatenChocolates = 0;

            _calculateHowManyChocolatesCanBeEaten();
        }

            private void _calculateHowManyChocolatesCanBeEaten()
            {
                _eatenChocolates = _amountOfMoney / _chocolateBarCost;

                for (int availableWrappers = _eatenChocolates; availableWrappers >= _nWrappersToTurnInBar; )
                {
                    int chocolatesForFree = availableWrappers / _nWrappersToTurnInBar;
                    availableWrappers = availableWrappers - (chocolatesForFree * _nWrappersToTurnInBar) + chocolatesForFree;
                    _eatenChocolates += chocolatesForFree;
                }
            }

        public int GetEatenChocolates()
        {
            return _eatenChocolates;
        }
    }
