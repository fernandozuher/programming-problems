// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

using System;
using System.Linq;

class Solution
{
    public int[] solution(int[] a, int k)
    {
        int[] rotatedArray = _isThereRotation(ref a, k);

        if (rotatedArray != null)
            return rotatedArray;
        else
            return a;
    }

        private static int[] _isThereRotation(ref int[] array, int rotation)
        {
            int newRotation = _reduceRotations(array.Length, rotation);

            if (newRotation > 0)
            {
                int[] rotatedArray = _rotateElements(ref array, newRotation);
                return rotatedArray;
            }
            else
                return null;
        }

            private static int _reduceRotations(int arraySize, int rotation)
            {
                if (arraySize > 1)
                    return rotation >= arraySize ? rotation % arraySize : rotation;
                else
                    return 0;
            }

            private static int[] _rotateElements(ref int[] array, int rotation)
            {
                int size = array.Length;

                int[] firstHalfArray = array.Skip(size - rotation)
                                       .Take(size)
                                       .ToArray();

                int[] secondHalfArray = array.Skip(0)
                                        .Take(size - rotation)
                                        .ToArray();

                var newArray = new int[size];
                firstHalfArray.CopyTo(newArray, 0);
                secondHalfArray.CopyTo(newArray, firstHalfArray.Length);

                return newArray;
            }
}
