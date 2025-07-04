// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Input data = readInput();
        PrintOutput(new BillDivision(data).BonAppetit());
    }

    private static Input readInput()
    {
        int[] numbers = ReadNumbers();
        return new Input(
            numbers[1],
            ReadNumbers(),
            int.Parse(Console.ReadLine()!)
        );
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static void PrintOutput(int charged)
    {
        Console.WriteLine(charged > 0 ? charged : "Bon Appetit");
    }
}

public record Input(int ItemNotEaten, int[] MealCosts, int AmountCharged);

public class BillDivision(Input data)
{
    private readonly int _itemNotEaten = data.ItemNotEaten;
    private readonly int[] _mealCosts = data.MealCosts;
    private readonly int _amountCharged = data.AmountCharged;

    public int BonAppetit()
    {
        return _amountCharged - ComputeActualShare();
    }

    private int ComputeActualShare()
    {
        int totalCost = _mealCosts.Sum();
        int totalSharedCost = totalCost - _mealCosts[_itemNotEaten];
        return totalSharedCost / 2;
    }
}
