// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

using Morfo.IO;

Reader.SkipInputLn();
var candles = Reader.ReadLn<int, int[]>();
Console.WriteLine(BirthdayCakeCandles(candles));

// n: length of candles
// T: O(2n) => O(n)
// S: O(1) extra space
int BirthdayCakeCandles(int[] candles)
{
    int max = candles.Max();
    return candles.Count(x => x == max);
}
