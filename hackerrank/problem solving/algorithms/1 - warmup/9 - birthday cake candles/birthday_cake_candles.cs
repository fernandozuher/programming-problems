// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

Console.ReadLine();
int[] candles = ReadNumbers();
Console.WriteLine(BirthdayCakeCandles(candles));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of candles
// T: O(2n) = O(n)
// S: O(1) extra space
int BirthdayCakeCandles(int[] candles)
{
    int max = candles.Max();
    return candles.Count(x => x == max);
}
