// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

int n = int.Parse(Console.ReadLine()!);
string[] strings = ReadLines(n);
Dictionary<string, int> stringsToCounts = Counter(strings);

n = int.Parse(Console.ReadLine()!);
string[] queries = ReadLines(n);

foreach (var x in CountsFrom(stringsToCounts, queries))
    Console.WriteLine(x);

string[] ReadLines(int n) => Enumerable.Range(0, n).Select(_ => Console.ReadLine()!).ToArray();

Dictionary<string, int> Counter(string[] arr)
{
    var freqMap = new Dictionary<string, int>();
    foreach (var x in arr)
        freqMap[x] = freqMap.GetValueOrDefault(x) + 1;
    return freqMap;
}

// n: length of queries
// maxQueryStringLength: 20
// T: O(n * maxQueryStringLength) = O(n * 20) = O(n)
// S: O(n) extra space
int[] CountsFrom(Dictionary<string, int> freqMap, string[] queries)
{
    return queries.Select(q => freqMap.GetValueOrDefault(q)).ToArray();
}
