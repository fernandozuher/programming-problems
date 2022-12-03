using System;

class Solution
{
    public static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine().Trim());

        int max_ones = 0, ones;
        for (ones = 0; n > 0; n /= 2) {
            if (n % 2 == 1)
                ++ones;
            else {
                if (ones > max_ones)
                    max_ones = ones;
                ones = 0;
            }
        }

        Console.WriteLine(ones > max_ones ? ones : max_ones);
    }
}
