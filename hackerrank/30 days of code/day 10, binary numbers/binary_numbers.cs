// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int maxOnes = 0, ones = 0;

        for (; n > 0; n /= 2)
            if (n % 2 == 1)
                ++ones;
            else
            {
                maxOnes = Math.Max(maxOnes, ones);
                ones = 0;
            }

        maxOnes = Math.Max(maxOnes, ones);
        Console.WriteLine(maxOnes);
    }
}
