// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

using System;

public class Solution {

    public static void Main()
    {
        int _ = _ReadANumber();
        List<int> array = _ReadAnArray();

        List<int> permutatedArray = _PermutationEquation(array);
        PrintArray(permutatedArray);
    }

        private static int _ReadANumber()
        {
            int number = int.Parse(Console.ReadLine());
            return number;
        }

        private static List<int> _ReadAnArray()
        {
            List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
            return array;
        }

        private static List<int> _PermutationEquation(List<int> array)
        {
            List<int> arrayElementsPositions = _GenerateArrayOfElementsPositions(array);
            List<int> permutatedArray = _GeneratePermutatedArray(arrayElementsPositions);
            return permutatedArray;
        }

            private static List<int> _GenerateArrayOfElementsPositions(List<int> array)
            {
                List<int> arrayElementsPositions = new List<int>(new int[array.Count]);
                for (int i = 0, size = array.Count; i < size; i++)
                    arrayElementsPositions[array[i] - 1] = i;
                return arrayElementsPositions;
            }

            private static List<int> _GeneratePermutatedArray(List<int> array)
            {
                List<int> permutatedArray = new List<int>(new int[array.Count]);
                for (int i = 0, size = array.Count; i < size; i++)
                    permutatedArray[i] = array[array[i]] + 1;
                return permutatedArray;
            }

        public static void PrintArray(List<int> array)
        {
            array.ForEach(Console.WriteLine);
        }
}
