// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        List<int> line = _readIntArray();
        int budget = line.First();

        List<int> keyboardCosts = _readIntArray();
        List<int> usbDriveCosts = _readIntArray();

        keyboardCosts.Sort();
        usbDriveCosts.Sort();

        var obj = new ElectronicsShop(keyboardCosts, usbDriveCosts, budget);
        Console.WriteLine(obj.MoneyThatCanBeSpent);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class ElectronicsShop
    {
        private List<int> _keyboardCosts;
        private List<int> _usbDriveCosts;
        private int _budget;
        private int _moneyThatCanBeSpent;

        public ElectronicsShop(List<int> keyboardCosts, List<int> usbDriveCosts, int budget)
        {
            _keyboardCosts = keyboardCosts;
            _usbDriveCosts = usbDriveCosts;
            _budget = budget;
            _moneyThatCanBeSpent = 0;
            _calculateMoneySpent();
        }

            private void _calculateMoneySpent()
            {
                for (int i = 0; i < _keyboardCosts.Count; ++i)
                {
                    if (_isNextCostEqualToCurrentOne(_keyboardCosts, i))
                        continue;

                    for (int j = 0; j < _usbDriveCosts.Count; ++j)
                    {
                        if (_isNextCostEqualToCurrentOne(_usbDriveCosts, j))
                            continue;

                        int sum = _keyboardCosts[i] + _usbDriveCosts[j];

                        if (_isSumAffordableByBudget(sum))
                            _moneyThatCanBeSpent = _updateCost(sum);
                        else
                            break;
                    }
                }

                _moneyThatCanBeSpent = _moneyThatCanBeSpent > 0 ? _moneyThatCanBeSpent : -1;
            }

                private bool _isNextCostEqualToCurrentOne(List<int> deviceCosts, int i)
                {
                    return i < deviceCosts.Count - 1 && deviceCosts[i] == deviceCosts[i + 1];
                }

                private bool _isSumAffordableByBudget(int sum)
                {
                    return sum <= _budget;
                }

                private int _updateCost(int sum)
                {
                    return Math.Max(sum, _moneyThatCanBeSpent);
                }

        public int MoneyThatCanBeSpent
        {
            get { return _moneyThatCanBeSpent; }
        }
    }
