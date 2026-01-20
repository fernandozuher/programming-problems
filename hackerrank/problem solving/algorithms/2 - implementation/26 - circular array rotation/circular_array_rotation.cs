// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

int[] arr = ReadNumbers();
int nRotation = arr[1];
int nQueries = arr[2];
arr = ReadNumbers();
PrintQueries(arr, nRotation, nQueries);

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(" "), int.Parse);
}

// T: O(nQueries)
// S: O(1) extra space
void PrintQueries(int[] arr, int nRotation, int nQueries)
{
    int n = arr.Length;
    int offset = n - nRotation % n;
    for (int i = 0; i < nQueries; i++)
    {
        int query = int.Parse(Console.ReadLine()!);
        int idx = (query + offset) % n;
        Console.WriteLine(arr[idx]);
    }
}
