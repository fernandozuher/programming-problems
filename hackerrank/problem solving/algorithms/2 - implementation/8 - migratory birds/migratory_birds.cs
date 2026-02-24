// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

Dictionary<int, int> birdsToCounts = ReadInput();
Console.WriteLine(FindMostSpottedBird(birdsToCounts));

// n: length of input
// T: O(n)
// S: O(n) extra space
Dictionary<int, int> ReadInput()
{
    Console.ReadLine();
    var freqMap = new Dictionary<int, int>();
    foreach (int x in Console.ReadLine()!.Split().Select(int.Parse))
    {
        freqMap.TryGetValue(x, out int count);
        freqMap[x] = ++count;
    }
    return freqMap;
}

// n: length of birdsToCounts
// T: O(n)
// S: O(1) extra space
int FindMostSpottedBird(Dictionary<int, int> birdsToCounts)
{
    var x = birdsToCounts.MaxBy(x => (x.Value, -x.Key));
    return x.Key;
}
