// https://www.hackerrank.com/challenges/30-operators/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        double mealCost = double.Parse(Console.ReadLine());
        int tipPercent = int.Parse(Console.ReadLine());
        int taxPercent = int.Parse(Console.ReadLine());

        _solve(mealCost, tipPercent, taxPercent);
    }

        private static void _solve(double mealCost, int tipPercent, int taxPercent)
        {
            double totalCost = mealCost + mealCost * tipPercent / 100 + mealCost * taxPercent / 100;
            Console.WriteLine("{0:0}", totalCost);
        }
}
