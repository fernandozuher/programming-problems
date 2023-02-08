// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

using System;
using System.Linq;


class Solution
{
    public int[] solution(int[] a, int k)
    {
        int[] rotated_array = IsThereRotation(a, k);

        if (rotated_array != null)
            return rotated_array;
        else
            return a;
    }

    public int[] IsThereRotation(int[] array, int rotation)
    {
        int new_rotation = ReduceRotations(array.Length, rotation);

        if (new_rotation > 0)
        {
            int[] rotated_array = RotateElements(array, new_rotation);
            return rotated_array;
        }
        else
            return null;
    }

    public int ReduceRotations(int array_size, int rotation)
    {
        if (array_size > 1)
            return rotation >= array_size ? rotation % array_size : rotation;
        else
            return 0;
    }

    public int[] RotateElements(int[] array, int rotation)
    {
        int N = array.Length;

        int[] first_half_array = array.Skip(N - rotation)
                                 .Take(N)
                                 .ToArray();

        int[] second_half_array = array.Skip(0)
                                  .Take(N - rotation)
                                  .ToArray();

        var new_array = new int[N];
        first_half_array.CopyTo(new_array, 0);
        second_half_array.CopyTo(new_array, first_half_array.Length);

        return new_array;
    }
}
