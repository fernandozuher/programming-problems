// Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

using System;

class Solution
{
    public int solution(int[] array)
    {
        Array.Sort(array);
        int missingElement = FindMissingElement(array);
        return missingElement;
    }

        private int FindMissingElement(int[] array)
        {
            int i;

            for (i = 0; i < array.Length; i++)
                if (array[i] != i + 1)
                    break;

            return i + 1;
        }
}
