// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] numbers = ReadArray();
        Console.WriteLine(numbers.Sum());
    }

    private static int[] ReadArray()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToArray();
    }
}
