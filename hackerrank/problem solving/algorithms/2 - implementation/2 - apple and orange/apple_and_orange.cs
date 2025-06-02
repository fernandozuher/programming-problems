// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        var (house, appleTree, orangeTree) = ReadInput();
        Console.WriteLine(CountFruitsOnHouse(appleTree, house));
        Console.WriteLine(CountFruitsOnHouse(orangeTree, house));
    }

    private static (House, FruitTree, FruitTree) ReadInput()
    {
        var numbers = ReadNumbers();
        var house = new House(numbers[0], numbers[1]);

        numbers = ReadNumbers();
        Console.ReadLine(); // Discard sizes of arrays
        var appleTree = new FruitTree(numbers[0], ReadNumbers());
        var orangeTree = new FruitTree(numbers[1], ReadNumbers());

        return (house, appleTree, orangeTree);
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToArray();
    }

    private static int CountFruitsOnHouse(FruitTree fruitTree, House house)
    {
        return fruitTree.FruitDistances
                        .Select(distance => fruitTree.TreeLocation + distance)
                        .Count(position => house.Contains(position));
    }
}

public record House(int Start, int End)
{
    public bool Contains(int position)
    {
        return Start <= position && position <= End;
    }
}

public record FruitTree(int TreeLocation, int[] FruitDistances);
