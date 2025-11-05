// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

Console.ReadLine();
Console.WriteLine(PickingNumbers(ReadNumbersIntoMap()));

Dictionary<int, int> ReadNumbersIntoMap()
{
    return Console.ReadLine()!
                  .Split()
                  .Select(int.Parse)
                  .GroupBy(num => num)
                  .ToDictionary(g => g.Key, g => g.Count());
}

int PickingNumbers(Dictionary<int, int> counter)
{
    int maxLen = 0;
    foreach (int num in counter.Keys)
    {
        int current = counter[num] + (counter.ContainsKey(num + 1) ? counter[num + 1] : 0);
        maxLen = Math.Max(maxLen, current);
    }
    return maxLen;
}
