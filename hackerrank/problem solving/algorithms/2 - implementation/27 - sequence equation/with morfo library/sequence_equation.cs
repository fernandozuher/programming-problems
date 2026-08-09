// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

using Morfo.IO;

Reader.SkipInputLn();
int[] arr = Reader.ReadLn<int, int[]>();
Writer.Println(SequenceEquation(arr));

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
