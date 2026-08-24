// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

using Morfo.IO;

var (house, appleTree, orangeTree) = ReadInput();
Console.WriteLine(CountFruitsOnHouse(appleTree, house));
Console.WriteLine(CountFruitsOnHouse(orangeTree, house));

(House, FruitTree, FruitTree) ReadInput()
{
    var (houseStart, houseEnd) = Reader.Read<int, int>();
    var house = new House(houseStart, houseEnd);

    var (appleTreeLocation, orangeTreeLocation) = Reader.Read<int, int>();
    var (nApples, nOranges) = Reader.Read<int, int>();

    var appleTree = new FruitTree(appleTreeLocation, Reader.Read<int>(nApples));
    var orangeTree = new FruitTree(orangeTreeLocation, Reader.Read<int>(nOranges));

    return (house, appleTree, orangeTree);
}

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
    public bool Contains(int position) => Start <= position && position <= End;
}

record FruitTree(int TreeLocation, int[] FruitDistances);
