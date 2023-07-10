// Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

using System;

class Solution
{
    public int solution(int[] array)
    {
        Array.Sort(array);
        return _findMissingElement(ref array);
    }

        private static int _findMissingElement(ref int[] array)
        {
            int i;
            for (i = 0; i < array.Length; i++)
                if (array[i] != i + 1)
                    break;
            return i + 1;
        }
}
