// https://www.hackerrank.com/challenges/30-operators/problem?isFullScreen=true

using static System.Console;

class Solution
{
    public static void Main()
    {
        var mealCost = double.Parse(ReadLine());
        var tipPercent = int.Parse(ReadLine());
        var taxPercent = int.Parse(ReadLine());
        solve(mealCost, tipPercent, taxPercent);
    }

    private static void solve(double mealCost, int tipPercent, int taxPercent)
    {
        var totalCost = mealCost + mealCost * tipPercent / 100 + mealCost * taxPercent / 100;
        WriteLine("{0:0}", totalCost);
    }
}