// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

Input data = ReadInput();
var charged = BonAppetit(data);
Console.WriteLine(charged > 0 ? charged : "Bon Appetit");

Input ReadInput()
{
    int itemNotEaten = ReadNums()[1];
    int[] mealCosts = ReadNums();
    int amountCharged = ReadNums()[0];
    return new Input(itemNotEaten, mealCosts, amountCharged);
}

int[] ReadNums() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

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
