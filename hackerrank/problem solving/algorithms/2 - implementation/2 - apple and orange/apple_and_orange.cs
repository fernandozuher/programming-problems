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

    Console.ReadLine(); // Discard array sizes

    var appleTree = new FruitTree(appleTreeLocation, ReadNumbers());
    var orangeTree = new FruitTree(orangeTreeLocation, ReadNumbers());

    return (house, appleTree, orangeTree);
}

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of fruitTree.fruitDistances
// T: O(n)
// S: O(1) extra space
int CountFruitsOnHouse(FruitTree fruitTree, House house)
{
    return fruitTree.FruitDistances
                    .Count(distance => house.Contains(fruitTree.TreeLocation + distance));
}

record House(int Start, int End)
{
    public bool Contains(int position)
    {
        return Start <= position && position <= End;
    }
}

record FruitTree(int TreeLocation, int[] FruitDistances);
