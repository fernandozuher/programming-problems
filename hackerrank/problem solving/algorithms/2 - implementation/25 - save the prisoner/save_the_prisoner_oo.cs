// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

using System;


public class Solution
{
    public static void Main(String[] args)
    {
        int nTestCases = _ReadANumber();
        List<int> prisonersChairNumberToWarn = new List<int>(new int[nTestCases]);

        for (int i = 0; i < nTestCases; i++)
        {
            List<int> testCase = _ReadTestCase();
            SaveThePrisoner obj = new SaveThePrisoner(testCase);
            prisonersChairNumberToWarn[i] = obj.GetPrisonerChairNumberToWarn();
        }

        _PrintResults(prisonersChairNumberToWarn);
    }

        private static int _ReadANumber()
        {
            int number = int.Parse(Console.ReadLine());
            return number;
        }

        private static List<int> _ReadTestCase()
        {
            List<int> testCase = Console.ReadLine().Split().Select(int.Parse).ToList();
            return testCase;
        }

        private static void _PrintResults(List<int> array)
        {
            array.ForEach(Console.WriteLine);
        }
}

    class SaveThePrisoner
    {
        private int _Prisoners;
        private int _Sweets;
        private int _ChairNumberToBegin;
        private int _PrisonerChairNumberToWarn;

        public SaveThePrisoner(List<int> testCase)
        {
            _Prisoners = testCase.First();
            _Sweets = testCase[1];
            _ChairNumberToBegin = testCase.Last();

            _PrisonerChairNumberToWarn = _SaveThePrisoner();
        }

            private int _SaveThePrisoner()
            {
                int prisonerChairNumberToWarn = _ChairNumberToBegin + (_Sweets - 1);

                if (prisonerChairNumberToWarn > _Prisoners)
                {
                    prisonerChairNumberToWarn %= _Prisoners;

                    if (prisonerChairNumberToWarn == 0)
                        prisonerChairNumberToWarn = _Prisoners;
                }

                return prisonerChairNumberToWarn;
            }

        public int GetPrisonerChairNumberToWarn()
        {
            return _PrisonerChairNumberToWarn;
        }
    }
