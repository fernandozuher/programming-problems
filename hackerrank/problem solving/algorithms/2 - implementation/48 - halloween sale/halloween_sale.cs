// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        List<int> array = ReadIntArray();
        int defaultPriceGame = array.First();
        int discount = array[1];
        int minimumPriceGame = array[2];
        int budget = array.Last();
        WriteLine(HowManyGamesCanBeBought(defaultPriceGame, discount, minimumPriceGame, budget));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static int HowManyGamesCanBeBought(int defaultPriceGame, int discount, int minimumPriceGame, int budget)
        {
            int gamesCanBeBoughtQuantity = 0;

            for (int currentPriceGame = defaultPriceGame, currentBudget = budget - defaultPriceGame; currentBudget >= 0;)
            {
                ++gamesCanBeBoughtQuantity;
                currentPriceGame -= discount;
                currentBudget -= Math.Max(currentPriceGame, minimumPriceGame);
            }

            return gamesCanBeBoughtQuantity;
        }
}
