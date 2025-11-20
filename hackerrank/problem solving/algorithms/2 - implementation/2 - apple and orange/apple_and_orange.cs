// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

var (house, appleTree, orangeTree) = ReadInput();
Console.WriteLine(CountFruitsOnHouse(appleTree, house));
Console.WriteLine(CountFruitsOnHouse(orangeTree, house));

(House, FruitTree, FruitTree) ReadInput()
{
    var arr = ReadNumbers();
    var house = new House(arr[0], arr[1]);

    arr = ReadNumbers();
    var appleTreeLocation = arr[0];
    var orangeTreeLocation = arr[1];

    Console.ReadLine(); // Discard sizes of arrays

    var appleTree = new FruitTree(appleTreeLocation, ReadNumbers());
    var orangeTree = new FruitTree(orangeTreeLocation, ReadNumbers());

    return (house, appleTree, orangeTree);
}

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int CountFruitsOnHouse(FruitTree fruitTree, House house)
{
    return fruitTree.FruitDistances
                    .Select(distance => fruitTree.TreeLocation + distance)
                    .Count(position => house.Contains(position));
}

record House(int Start, int End)
{
    public bool Contains(int position)
    {
        return Start <= position && position <= End;
    }
}

record FruitTree(int TreeLocation, int[] FruitDistances);
