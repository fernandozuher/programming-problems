// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        var prisonersChairNumberToWarn = new List<int>(new int[n]);

        for (int i = 0; i < n; ++i)
        {
            List<int> testCase = _readIntArray();
            int prisoners = testCase.First();
            int sweets = testCase[1];
            int chairNumberToBegin = testCase.Last();
            prisonersChairNumberToWarn[i] = _saveThePrisoner(prisoners, sweets, chairNumberToBegin);
        }

        prisonersChairNumberToWarn.ForEach(Console.WriteLine);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static int _saveThePrisoner(int prisoners, int sweets, int chairNumberToBegin)
        {
            int prisonerChairNumberToWarn = chairNumberToBegin + (sweets - 1);
            int x = prisonerChairNumberToWarn;

            if (x > prisoners)
            {
                x %= prisoners;
                if (x == 0)
                    x = prisoners;
            }

            return x;
        }
}
