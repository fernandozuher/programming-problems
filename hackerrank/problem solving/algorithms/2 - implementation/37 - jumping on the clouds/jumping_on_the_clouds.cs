// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> clouds = Console.ReadLine().Split().Select(int.Parse).ToList();
        Console.WriteLine(MinimumNumberOfJumps(clouds));
    }

        public static int MinimumNumberOfJumps(List<int> clouds)
        {
            int jumps = 0;
            for (int i = 0, n = clouds.Count - 1; i < n; ++jumps)
                i += NextJump(i, clouds);
            return jumps;
        }

            public static int NextJump(int index, List<int> clouds)
            {
                bool isNextSecondCloudCumulus = false;
                if (index + 2 < clouds.Count)
                    isNextSecondCloudCumulus = clouds[index + 2] == 0;
                return isNextSecondCloudCumulus ? 2 : 1;
            }
}
