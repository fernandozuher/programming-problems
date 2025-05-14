// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        for (int testCases = int.Parse(Console.ReadLine()); testCases-- > 0;)
        {
            var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int n = input[0];
            int k = input[1];
            Console.WriteLine(BitwiseAnd(n, k));
        }
    }

    private static int BitwiseAnd(int n, int k)
    {
        if ((k - 1 | k) <= n)
            return k - 1;
        return k - 2;
    }
}
