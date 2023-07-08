// Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

using System;

class Solution
{
    public int solution(int[] A)
    {
        Array.Sort(A);
        int unpairedElement = A[0];
        bool isElementPaired = false;

        for (int i = 1; i < A.Length; i++)
            if (A[i] == unpairedElement)
                isElementPaired = !isElementPaired;
            else if (isElementPaired)
            {
                isElementPaired = false;
                unpairedElement = A[i];
            }
            else
                break;

        return unpairedElement;
    }
}
