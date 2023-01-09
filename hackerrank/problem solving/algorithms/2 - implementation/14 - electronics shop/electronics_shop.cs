// Source: https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        List<int> newLine = ReadLineAsListInt();
        int budget = newLine.First();

        List<int> keyboardCosts = ReadLineAsListInt();
        List<int> usbDriveCosts = ReadLineAsListInt();

        keyboardCosts.Sort();
        usbDriveCosts.Sort();

        Result result = new Result(keyboardCosts, usbDriveCosts, budget);
    }

        private static List<int> ReadLineAsListInt()
        {
            List<int> inputLine = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return inputLine;
        }
}

    class Result
    {
        private List<int> _keyboardCosts;
        private List<int> _usbDriveCosts;
        private int _budget;
        private int _canBeSpent;

        public Result(List<int> keyboardCosts, List<int> usbDriveCosts, int budget)
        {
            _keyboardCosts = keyboardCosts;
            _usbDriveCosts = usbDriveCosts;
            _budget = budget;
            _canBeSpent = 0;

            _GetMoneySpent();
            PrintResult();
        }

            private void _GetMoneySpent()
            {
                for (int i = 0, n_keyboardCosts = _keyboardCosts.Count; i < n_keyboardCosts; i++)
                {
                    if (_IsNextCostEqualToCurrentOne(_keyboardCosts, i))
                        continue;

                    for (int j = 0, n_usbDriveCosts = _usbDriveCosts.Count; j < n_usbDriveCosts; j++)
                    {                        
                        if (_IsNextCostEqualToCurrentOne(_usbDriveCosts, j))
                            continue;

                        int sum = _keyboardCosts[i] + _usbDriveCosts[j];

                        if (_IsSumInsideBudget(sum))
                            _canBeSpent = _UpdateCost(sum);
                        else
                            break;
                    }
                }

                _canBeSpent = _canBeSpent > 0 ? _canBeSpent : -1;
            }

                private bool _IsNextCostEqualToCurrentOne(List<int> deviceCosts, int currentIndex)
                {
                    return currentIndex < deviceCosts.Count - 1 && deviceCosts[currentIndex] == deviceCosts[currentIndex + 1];
                }

                private bool _IsSumInsideBudget(int sum)
                {
                    return sum <= _budget;
                }

                private int _UpdateCost(int sum)
                {
                    return Math.Max(sum, _canBeSpent);
                }

            public void PrintResult()
            {
                Console.WriteLine(_canBeSpent);
            }
    }
