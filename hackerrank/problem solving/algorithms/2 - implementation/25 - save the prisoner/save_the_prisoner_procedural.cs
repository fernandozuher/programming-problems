// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

using System;


public class Solution
{
    public static void Main(string[] args)
    {
        int nTestCases = _ReadANumber();
        List<int> prisonersChairNumberToWarn = _ReadTestCasesAndSaveThePrisoners(nTestCases);
        PrintResults(prisonersChairNumberToWarn);
    }

        private static int _ReadANumber()
        {
            int number = int.Parse(Console.ReadLine());
            return number;
        }

        private static List<int> _ReadTestCasesAndSaveThePrisoners(int nTestCases)
        {
            List<int> prisonersChairNumberToWarn = new List<int>(new int[nTestCases]);

            for (int i = 0; i < nTestCases; i++)
            {
                List<int> testCase = _ReadTestCase();
                prisonersChairNumberToWarn[i] = _SaveThePrisoner(testCase);
            }

            return prisonersChairNumberToWarn;
        }

            private static List<int> _ReadTestCase()
            {
                List<int> testCase = Console.ReadLine().Split().Select(int.Parse).ToList();
                return testCase;
            }

            private static int _SaveThePrisoner(List<int> testCase)
            {
                int prisoners = testCase.First();
                int sweets = testCase[1];
                int chairNumberToBegin = testCase.Last();
                int prisonerChairNumberToWarn = chairNumberToBegin + (sweets - 1);

                if (prisonerChairNumberToWarn > prisoners)
                {
                    prisonerChairNumberToWarn %= prisoners;

                    if (prisonerChairNumberToWarn == 0)
                        prisonerChairNumberToWarn = prisoners;
                }

                return prisonerChairNumberToWarn;
            }

        public static void PrintResults(List<int> array)
        {
            array.ForEach(Console.WriteLine);
        }
}
