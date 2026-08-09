// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

using Morfo.Collections;
using Morfo.IO;

Reader.SkipInputLn();
int[] arr = Reader.ReadLn<int, int[]>();
Console.WriteLine(MinDeletionsToEqualize(arr));

// n: length of arr, 1 <= n <= 100
// k: number of distinct elements in arr
// k <= n
// T: O(n) = O(100) = O(1)
// S: O(k) = O(n) = O(100) = O(1) extra space
int MinDeletionsToEqualize(int[] arr) => arr.Length - Counter.Of(arr).Values.Max();
