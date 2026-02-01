// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

Console.ReadLine();
Console.WriteLine(MinDeletionsToEqualize(ReadNumbers()));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of arr, 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(n) = O(100) = O(1) extra space
int MinDeletionsToEqualize(int[] arr) => arr.Length - Counter(arr).Values.Max();

Dictionary<int, int> Counter(int[] arr) => arr.GroupBy(x => x).ToDictionary(g => g.Key, g => g.Count());
