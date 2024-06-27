// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        ReadLine();
        List<int> chocolateSquares = ReadIntArray();
        List<int> dayMonth = ReadIntArray();
        WriteLine(Birthday(chocolateSquares, dayMonth));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine()!.Split().Select(int.Parse).ToList();
        }

        static int Birthday(List<int> chocolateSquares, List<int> dayMonth)
        {
            int waysBarCanBeDivided = 0;
            int day = dayMonth.First();
            int month = dayMonth.Last();

            foreach (int i in Enumerable.Range(0, chocolateSquares.Count - month + 1))
                if (chocolateSquares[i..(i + month)].Sum() is var sum && sum == day)
                    ++waysBarCanBeDivided;

            return waysBarCanBeDivided;
        }
}