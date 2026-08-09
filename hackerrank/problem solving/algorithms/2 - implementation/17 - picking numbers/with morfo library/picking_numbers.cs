// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

using Morfo.Collections;
using Morfo.IO;

Reader.SkipInputLn();
var freqMap = Counter.Of(Reader.ReadLn<int, int[]>());
Console.WriteLine(PickingNumbers(freqMap));

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
