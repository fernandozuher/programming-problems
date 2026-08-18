// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

using Morfo.IO;

Input data = ReadInput();
var charged = BonAppetit(data);
Console.WriteLine(charged > 0 ? charged : "Bon Appetit");

Input ReadInput()
{
    int n = Reader.Read<int>();
    return new Input(ItemNotEaten: Reader.Read<int>(), MealCosts: Reader.Read<int>(n), AmountCharged: Reader.Read<int>());
}

// n: length of data.MealCosts
// T: O(n)
// S: O(1) extra space
int BonAppetit(Input data)
{
    int totalSharedCost = data.MealCosts.Sum() - data.MealCosts[data.ItemNotEaten];
    totalSharedCost /= 2;
    return data.AmountCharged - totalSharedCost;
}

record Input(int ItemNotEaten, int[] MealCosts, int AmountCharged);
