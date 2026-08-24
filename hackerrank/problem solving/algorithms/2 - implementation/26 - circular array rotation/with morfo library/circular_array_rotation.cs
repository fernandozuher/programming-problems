// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

using Morfo.IO;

var (n, nRotation, nQueries) = Reader.Read<int, int, int>();
int[] arr = Reader.Read<int>(n);
foreach (var q in Queries(arr, nRotation, nQueries))
    Console.WriteLine(q);

// T: O(nQueries)
// S: O(1) extra space
IEnumerable<int> Queries(int[] arr, int nRotation, int nQueries)
{
    int n = arr.Length;
    int offset = n - nRotation % n;
    for (int i = 0; i < nQueries; i++)
    {
        int query = Reader.Read<int>();
        int idx = (query + offset) % n;
        yield return arr[idx];
    }
}
