// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

int[] arr = ReadNumbers();
int n = arr[0];
int nQueries = arr[1];
Console.WriteLine(ArrayManipulation(n, nQueries));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

long ArrayManipulation(int n, int nQueries)
{
    int[] arr = PopulateArr(n, nQueries);
    return MaxSequentialSum(arr);
}

// T: O(n + nQueries)
// S: O(n) extra space
int[] PopulateArr(int n, int nQueries)
{
    // +2 = 1-indexed array + range-end
    var res = new int[n + 2];

    for (int i = 0; i < nQueries; i++)
    {
        int[] arr = ReadNumbers();
        int b = arr[0];
        int e = arr[1];
        int summand = arr[2];

        res[b] += summand;
        res[e + 1] -= summand;
    }

    return res;
}

long MaxSequentialSum(int[] arr)
{
    long acc = 0;
    return arr.Select(x => acc += x).Max();
}
