// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

Console.ReadLine();
int[] arr = ReadNumbers();
foreach (var x in SequenceEquation(arr))
    Console.WriteLine(x);

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of arr
// T: O(n)
// S: O(n) extra space
IEnumerable<int> SequenceEquation(int[] arr)
{
    int[] valuesToIndex = new int[arr.Length];
    int i = 0;
    foreach (int val in arr)
        valuesToIndex[val - 1] = i++;
    foreach (int val in valuesToIndex)
        yield return valuesToIndex[val] + 1;
}
