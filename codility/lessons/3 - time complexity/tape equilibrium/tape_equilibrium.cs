// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

using System;
using System.Linq;

class Solution
{
    public int solution(int[] array)
    {
        int firstPart = array.First();
        int secondPart = array.Sum() - firstPart;
        int minimumDifferenceBetweenParts = Math.Abs(firstPart - secondPart);

        foreach (int element in new ArraySegment<int>(array, 1, array.Length - 2))
        {
            firstPart += element;
            secondPart -= element;
            int currentMinimum = Math.Abs(firstPart - secondPart);
            minimumDifferenceBetweenParts = Math.Min(minimumDifferenceBetweenParts, currentMinimum);
        }

        return minimumDifferenceBetweenParts;
    }
}
