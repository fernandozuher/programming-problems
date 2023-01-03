// Source: https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        List<int> input1 = ReadLineAsListInt();
        int itemAnnaDidntConsume = input1.Last();
        
        List<int> costOfEachMeal = ReadLineAsListInt();
        List<int> brianChargedAnna = ReadLineAsListInt();

        Result result = new Result(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna.First());
    }

        private static List<int> ReadLineAsListInt()
        {
            List<int> numbers = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return numbers;
        }
}

    class Result
    {
        private List<int> _costOfEachMeal;
        private int _itemAnnaDidntConsume;
        private int _brianChargedAnna;
        private string _brianOverchargedAnna;

        public Result(List<int> costOfEachMeal, int itemAnnaDidntConsume, int brianChargedAnna)
        {
            _costOfEachMeal = costOfEachMeal;
            _itemAnnaDidntConsume = itemAnnaDidntConsume;
            _brianChargedAnna = brianChargedAnna;
            _brianOverchargedAnna = "";

            _BonAppetit();
            PrintResult();
        }

            private void _BonAppetit()
            {
                int annaCost = _CalculateAnnaCost();
                _CheckIfBrianOverchargedAnna(annaCost);
            }

                private int _CalculateAnnaCost()
                {
                    int sum = _costOfEachMeal.Sum();
                    int annaCost = (sum - _costOfEachMeal[_itemAnnaDidntConsume]) / 2;
                    return annaCost;
                }

                private void _CheckIfBrianOverchargedAnna(int annaCost)
                {
                    if (annaCost == _brianChargedAnna)
                        _brianOverchargedAnna = "Bon Appetit";
                    else
                    {
                        int brianOverchargedAnna = _brianChargedAnna - annaCost;
                        _brianOverchargedAnna = brianOverchargedAnna.ToString();
                    }
                }

            public void PrintResult()
            {
                Console.WriteLine(_brianOverchargedAnna);
            }
    }
