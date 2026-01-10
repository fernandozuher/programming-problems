// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

Console.ReadLine();
Console.WriteLine(PickingNumbers(Counter()));

Dictionary<int, int> Counter()
{
    return Console.ReadLine()!
                  .Split()
                  .Select(int.Parse)
                  .GroupBy(num => num)
                  .ToDictionary(g => g.Key, g => g.Count());
}

// n: length of initial input array of numbers
// k: length of map frequency
// T:
//   Without constraining the input values:
//       In the worst case, length of map equals length of initial input array when there is no repeated element: k = n
//       O(n)
//   With input values limited to 1 through 99, as stated in the problem:
//       Max of 99 keys/values at map: O(99) = O(1)
// S: O(1) extra space
int PickingNumbers(Dictionary<int, int> frequency)
{
    int maxLen = 0;
    foreach (int num in frequency.Keys)
    {
        int current = frequency[num] + (frequency.ContainsKey(num + 1) ? frequency[num + 1] : 0);
        maxLen = Math.Max(maxLen, current);
    }
    return maxLen;
}
