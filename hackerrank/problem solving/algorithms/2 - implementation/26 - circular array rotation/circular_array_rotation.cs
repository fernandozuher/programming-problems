// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

int[] line = ReadNumbers();
int nRotation = line[1];
int nQueries = line[2];
int[] arr = ReadNumbers();
PrintQueries(arr, nRotation, nQueries);

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(" "), int.Parse);
}

void PrintQueries(int[] arr, int nRotation, int nQueries)
{
    int n = arr.Length;
    int r = nRotation % n;
    for (int i = 0; i < nQueries; i++)
    {
        int query = int.Parse(Console.ReadLine()!);
        int idx = (query + n - r) % n;
        Console.WriteLine(arr[idx]);
    }
}
