// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        List<int> input = _readIntArray();
        int n = input.First();
        int itemAnnaDidntConsume = input.Last();

        List<int> costOfEachMeal = _readIntArray();
        int brianChargedAnna = int.Parse(Console.ReadLine());

        var obj = new BillDivision(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna);
        _printOutput(obj.BrianOverchargedAnna);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static void _printOutput(int charged)
        {
            Console.WriteLine(charged > 0 ? charged : "Bon Appetit");
        }
}

    public class BillDivision
    {
        private List<int> _costOfEachMeal;
        private int _itemAnnaDidntConsume;
        private int _brianChargedAnna;
        private int _brianOverchargedAnna;

        public BillDivision(List<int> costOfEachMeal, int itemAnnaDidntConsume, int brianChargedAnna)
        {
            _costOfEachMeal = costOfEachMeal;
            _itemAnnaDidntConsume = itemAnnaDidntConsume;
            _brianChargedAnna = brianChargedAnna;
            _brianOverchargedAnna = 0;

            _bonAppetit();
        }

            private void _bonAppetit()
            {
                int annaCost = _calculateAnnaCost();
                _calculateHowMuchBrianOverchargedAnna(annaCost);
            }

                private int _calculateAnnaCost()
                {
                    int sum = _costOfEachMeal.Sum();
                    int annaCost = (sum - _costOfEachMeal[_itemAnnaDidntConsume]) / 2;
                    return annaCost;
                }

                private void _calculateHowMuchBrianOverchargedAnna(int annaCost)
                {
                    if (annaCost != _brianChargedAnna)
                        _brianOverchargedAnna = _brianChargedAnna - annaCost;
                }

        public int BrianOverchargedAnna
        {
            get { return _brianOverchargedAnna; }
        }
    }
