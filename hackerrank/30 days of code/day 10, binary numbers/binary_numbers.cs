// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(ReadLine());
        var binary = Convert.ToString(n, 2);
        WriteLine(FindMaxLengthOfOnes(binary));
    }

    public static int FindMaxLengthOfOnes(string binary)
    {
        return binary.Split('0').Max(segment => segment.Length);
    }
}
