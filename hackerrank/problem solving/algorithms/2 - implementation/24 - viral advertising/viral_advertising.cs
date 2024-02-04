// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int days = int.Parse(Console.ReadLine());
        Console.WriteLine(ViralAdvertising(days));
    }

        public static int ViralAdvertising(int days)
        {
            int shared = 5, liked = 0, cumulative = 0;

            while (days-- > 0)
            {
                liked = shared / 2;
                cumulative += liked;
                shared = liked * 3;
            }

            return cumulative;
        }
}
