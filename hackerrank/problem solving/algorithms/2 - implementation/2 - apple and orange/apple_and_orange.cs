// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

using static System.Console;

struct AppleAndOrange
{
    public int StartingSam, EndingSam;
    public int AppleTreeLocation, OrangeTreeLocation;
    public List<int> ApplesDistanceFromTree, OrangesDistanceFromTree;
}

class Solution
{
    static void Main()
    {
        AppleAndOrange input = ReadInput();
        CountApplesAndOranges(input);
    }

        static AppleAndOrange ReadInput()
        {
            var input = new AppleAndOrange();
            var temp = ReadIntArray();
            input.StartingSam = temp.First();
            input.EndingSam = temp.Last();

            temp = ReadIntArray();
            input.AppleTreeLocation = temp.First();
            input.OrangeTreeLocation = temp.Last();
            ReadLine(); // Discard sizes of arrays
            input.ApplesDistanceFromTree = ReadIntArray();
            input.OrangesDistanceFromTree = ReadIntArray();

            return input;
        }

            static List<int> ReadIntArray()
            {
                return ReadLine().Split().Select(int.Parse).ToList();
            }

        static void CountApplesAndOranges(AppleAndOrange input)
        {
            int applesOnHouse = CountFruitsOnHouse(input, "apple");
            int orangesOnHouse = CountFruitsOnHouse(input, "orange");
            WriteLine("{0}\n{1}", applesOnHouse, orangesOnHouse);
        }

            static int CountFruitsOnHouse(AppleAndOrange input, string fruit)
            {
                var (treeLocation, fruits) = FilterInput(input, fruit);
                return fruits.Count(partialLocation =>
                {
                    int location = treeLocation + partialLocation;
                    return location >= input.StartingSam && location <= input.EndingSam;
                });
            }

                static (int, List<int>) FilterInput(AppleAndOrange input, string fruit)
                {
                    return fruit == "apple"
                        ? (input.AppleTreeLocation, input.ApplesDistanceFromTree)
                        : (input.OrangeTreeLocation, input.OrangesDistanceFromTree);
                }
}
