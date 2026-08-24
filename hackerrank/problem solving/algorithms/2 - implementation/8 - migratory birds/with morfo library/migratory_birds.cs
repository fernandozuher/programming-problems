// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

using Morfo.Collections;
using Morfo.IO;

Dictionary<int, int> birdsToCounts = ReadInput();
Console.WriteLine(FindMostSpottedBird(birdsToCounts));

// n: length of input
// T: O(n)
// S: O(n) extra space
Dictionary<int, int> ReadInput()
{
    Reader.SkipInputLn();
    return Counter.Of(Reader.ReadLn<int, int[]>());
}

// n: length of birdsToCounts
// T: O(n)
// S: O(1) extra space
int FindMostSpottedBird(Dictionary<int, int> birdsToCounts)
{
    var x = birdsToCounts.MaxBy(x => (x.Value, -x.Key));
    return x.Key;
}
