// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

Console.ReadLine();
int[] arr = ReadNumbers();
Array.ForEach(SequenceEquation(arr), Console.WriteLine);

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int[] SequenceEquation(int[] arr)
{
    int[] valuesToIndex = new int[arr.Length];
    int i = 0;
    foreach (int val in arr)
    {
        valuesToIndex[val - 1] = i++;
    }
    return valuesToIndex.Select(val => valuesToIndex[val] + 1).ToArray();
}
