// Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        List<int> array = _readAnIntArrayAsAList();
        int gameDefaultPrice = array.First();
        int discount = array[1];
        int gameMinimumPrice = array[2];
        int budget = array.Last();

        HalloweenSale obj = new HalloweenSale(gameDefaultPrice, discount, gameMinimumPrice, budget);
        Console.WriteLine(obj.GetGamesCanBeBoughtQuantity());
    }

        private static List<int> _readAnIntArrayAsAList()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class HalloweenSale
    {
        private int _gameDefaultPrice, _discount, _gameMinimumPrice, _budget;
        private int _gamesCanBeBoughtQuantity = 0;

        public HalloweenSale(int gameDefaultPrice, int discount, int gameMinimumPrice, int budget)
        {
            _gameDefaultPrice = gameDefaultPrice;
            _discount = discount;
            _gameMinimumPrice = gameMinimumPrice;
            _budget = budget;

            _calculateHowManyGamesCanBeBought();
        }

            private void _calculateHowManyGamesCanBeBought()
            {
                for (int currentGamePrice = _gameDefaultPrice, currentBudget = _budget - _gameDefaultPrice; currentBudget >= 0;)
                {
                    _gamesCanBeBoughtQuantity++;
                    currentGamePrice -= _discount;
                    currentBudget -= currentGamePrice >= _gameMinimumPrice ? currentGamePrice : _gameMinimumPrice;
                }
            }

        public int GetGamesCanBeBoughtQuantity()
        {
            return _gamesCanBeBoughtQuantity;
        }
    }
