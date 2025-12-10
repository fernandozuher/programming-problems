// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

Console.ReadLine();
Console.WriteLine(EqualizeArray(ReadNumbers()));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int EqualizeArray(int[] arr)
{
    return arr.Length - Counter(arr).Values.Max();
}

Dictionary<int, int> Counter(int[] arr)
{
    return arr.GroupBy(x => x).ToDictionary(g => g.Key, g => g.Count());
}
