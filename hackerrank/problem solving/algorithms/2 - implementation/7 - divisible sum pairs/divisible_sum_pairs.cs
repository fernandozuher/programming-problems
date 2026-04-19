// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

int k = ReadNumbers()[1];
int[] numbers = ReadNumbers();
Console.WriteLine(DivisibleSumPairs(numbers, k));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of numbers
// k: length of freq
// T: O(n + k)
// S: O(k) extra space
int DivisibleSumPairs(int[] numbers, int k)
{
    int[] freq = InitRemainderFrequency(numbers, k);
    return CountPairsWithRemainder0(freq) + CountComplementaryRemainderPairs(freq)
           + CountPairsWithRemainderKHalf(freq);
}

int[] InitRemainderFrequency(int[] numbers, int k)
{
    int[] freq = new int[k];
    foreach (int x in numbers)
        freq[x % k]++;
    return freq;
}

int CountPairsWithRemainder0(int[] freq) => PairCount(freq[0]);

int PairCount(int n) => n * (n - 1) / 2;

int CountComplementaryRemainderPairs(int[] freq)
{
    return Enumerable.Range(1, (freq.Length + 1) / 2 - 1).Sum(i => freq[i] * freq[^i]);
}

int CountPairsWithRemainderKHalf(int[] freq)
{
    int n = freq.Length;
    return int.IsOddInteger(n) ? 0 : PairCount(freq[n / 2]);
}
