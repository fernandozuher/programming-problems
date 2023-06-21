// Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

using System;

public class HalloweenSale
{
    public static void Main()
    {
        List<int> array = _readAnIntArrayAsAList();
        int gameDefaultPrice = array.First();
        int discount = array[1];
        int gameMinimumPrice = array[2];
        int budget = array.Last();

        Console.WriteLine(_howManyGamesCanBeBought(gameDefaultPrice, discount, gameMinimumPrice, budget));
    }

        private static List<int> _readAnIntArrayAsAList()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static int _howManyGamesCanBeBought(int gameDefaultPrice, int discount, int gameMinimumPrice, int budget)
        {
            int gamesCanBeBoughtQuantity = 0;

            for (int currentGamePrice = gameDefaultPrice, currentBudget = budget - gameDefaultPrice; currentBudget >= 0;)
            {
                gamesCanBeBoughtQuantity++;
                currentGamePrice -= discount;
                currentBudget -= currentGamePrice >= gameMinimumPrice ? currentGamePrice : gameMinimumPrice;
            }

            return gamesCanBeBoughtQuantity;
        }
}
