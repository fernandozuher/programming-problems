// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

int k = ReadNumbers()[1];
int[] numbers = ReadNumbers();
Console.WriteLine(DivisibleSumPairs(numbers, k));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of array numbers
// k: length of array frequency
// T: O(n + k)
// S: O(k) extra space
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
    return Enumerable.Range(1, (frequency.Length + 1) / 2 - 1).Sum(i => frequency[i] * frequency[^i]);
}

int CountPairsWithRemainderKHalf(int[] frequency)
{
    int n = frequency.Length;
    return int.IsOddInteger(n) ? 0 : PairCount(frequency[n / 2]);
}
