// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int n = int.Parse(ReadLine());
        List<int> array = ReadIntArray();
        WriteLine(BirthdayCakeCandles(array));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static int BirthdayCakeCandles(List<int> candles)
        {
            int maxCount = 0;
            int maxElement = 0;

            foreach (int x in candles)
                if (x > maxElement) {
                    maxElement = x;
                    maxCount = 1;
                }
                else if (x == maxElement)
                    ++maxCount;

            return maxCount;
        }
}
