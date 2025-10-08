// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        int[] a = ReadNumbers();
        int[] b = ReadNumbers();
        Console.WriteLine(BetweenTwoSets(a, b));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int BetweenTwoSets(int[] a, int[] b)
    {
        int lcmOfA = LcmArray(a);
        int gcdOfB = GcdArray(b);

        int count = 0;
        for (int i = lcmOfA; i <= gcdOfB; i += lcmOfA)
            if (gcdOfB % i == 0)
                count++;
        return count;
    }

    private static int LcmArray(int[] arr)
    {
        return arr.Aggregate(Lcm);
    }

    private static int Lcm(int a, int b)
    {
        return a * b / Gcd(a, b);
    }

    private static int GcdArray(int[] arr)
    {
        return arr.Aggregate(Gcd);
    }

    private static int Gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
