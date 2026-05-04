// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

Console.ReadLine();
var freqMap = Counter(ReadNumbers());
Console.WriteLine(PickingNumbers(freqMap));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of arr
// k: length of output
// k <= n
// T: O(n)
// S: O(k) extra space
Dictionary<int, int> Counter(int[] arr) => arr.GroupBy(num => num).ToDictionary(g => g.Key, g => g.Count());

// k: length of freqMap
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
int PickingNumbers(Dictionary<int, int> freqMap)
{
    int maxLen = 0;
    foreach (int num in freqMap.Keys)
    {
        int current = freqMap[num] + (freqMap.ContainsKey(num + 1) ? freqMap[num + 1] : 0);
        maxLen = Math.Max(maxLen, current);
    }
    return maxLen;
}
