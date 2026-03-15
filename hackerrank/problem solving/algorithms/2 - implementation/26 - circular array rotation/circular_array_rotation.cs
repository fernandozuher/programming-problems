// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

int[] arr = ReadNumbers();
int nRotation = arr[1];
int nQueries = arr[2];
arr = ReadNumbers();
foreach (var q in Queries(arr, nRotation, nQueries))
    Console.WriteLine(q);

int[] ReadNumbers() => Console.ReadLine()!.Split(" ").Select(int.Parse).ToArray();

// T: O(nQueries)
// S: O(1) extra space
IEnumerable<int> Queries(int[] arr, int nRotation, int nQueries)
{
    int n = arr.Length;
    int offset = n - nRotation % n;
    for (int i = 0; i < nQueries; i++)
    {
        int query = int.Parse(Console.ReadLine()!);
        int idx = (query + offset) % n;
        yield return arr[idx];
    }
}
