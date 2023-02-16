// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

using System;
using System.Linq;


class Solution
{
    public int solution(int[] array)
    {
        int minimumDifferenceBetweenParts = FindMinimumDifferenceBetweenTwoPartsArray(array);
        return minimumDifferenceBetweenParts;
    }

        private static int FindMinimumDifferenceBetweenTwoPartsArray(int[] array)
        {
            int firstPart = array[0];
            int secondPart = array.Sum() - firstPart;
            int minimumDifferenceBetweenParts = Math.Abs(firstPart - secondPart);

            for (int i = 1, size = array.Length - 1; i < size; i++)
            {
                firstPart += array[i];
                secondPart -= array[i];
                int currentMinimum = Math.Abs(firstPart - secondPart);

                if (minimumDifferenceBetweenParts > currentMinimum)
                    minimumDifferenceBetweenParts = currentMinimum;
            }

            return minimumDifferenceBetweenParts;
        }
}
