// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

Input data = ReadInput();
var charged = BonAppetit(data);
Console.WriteLine(charged > 0 ? charged : "Bon Appetit");

Input ReadInput()
{
    int itemNotEaten = ReadNumbers()[1];
    int[] mealCosts = ReadNumbers();
    int amountCharged = ReadNumbers()[0];
    return new Input(itemNotEaten, mealCosts, amountCharged);
}

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int BonAppetit(Input data)
{
    int totalSharedCost = data.MealCosts.Sum() - data.MealCosts[data.ItemNotEaten];
    totalSharedCost /= 2;
    return data.AmountCharged - totalSharedCost;
}

record Input(int ItemNotEaten, int[] MealCosts, int AmountCharged);
