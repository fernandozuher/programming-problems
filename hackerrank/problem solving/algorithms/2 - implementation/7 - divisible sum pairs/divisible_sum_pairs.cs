// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

int k = ReadNumbers()[1];
int[] numbers = ReadNumbers();
Console.WriteLine(DivisibleSumPairs(numbers, k));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int DivisibleSumPairs(int[] numbers, int k)
{
    int[] frequency = InitRemainderFrequency(numbers, k);
    return CountPairsWithRemainder0(frequency) + CountComplementaryRemainderPairs(frequency)
           + CountPairsWithRemainderKHalf(frequency);
}

int[] InitRemainderFrequency(int[] numbers, int k)
{
    int[] frequency = new int[k];
    foreach (int x in numbers)
        frequency[x % k]++;
    return frequency;
}

int CountPairsWithRemainder0(int[] frequency) => PairCount(frequency[0]);

int PairCount(int n) => n * (n - 1) / 2;

int CountComplementaryRemainderPairs(int[] frequency)
{
    int k = frequency.Length;
    return Enumerable.Range(1, (k + 1) / 2 - 1).Sum(i => frequency[i] * frequency[k - i]);
}

int CountPairsWithRemainderKHalf(int[] frequency)
{
    int k = frequency.Length;
    return k % 2 == 0 ? PairCount(frequency[k / 2]) : 0;
}
