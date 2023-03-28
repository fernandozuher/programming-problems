// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int size = _ReadANumber();
        List<int> array = _ReadAnArray();

        Sequence_Equation obj = new Sequence_Equation(array);
        obj.PrintPermutatedArray();
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
}

    class Sequence_Equation
    {
        List<int> _InputArray;
        List<int> _ElementsPositionsArray;
        List<int> _PermutatedArray;

        public Sequence_Equation(List<int> array)
        {
            _InputArray = array;
            _ElementsPositionsArray = _GenerateElementsPositionsArray();
            _PermutatedArray = _GeneratePermutatedArray();
        }

            private List<int> _GenerateElementsPositionsArray()
            {
                List<int> elementsPositionsArray = new List<int>(new int[_InputArray.Count]);
                for (int i = 0, size = _InputArray.Count; i < size; i++)
                    elementsPositionsArray[_InputArray[i] - 1] = i;
                return elementsPositionsArray;
            }

            private List<int> _GeneratePermutatedArray()
            {
                List<int> permutatedArray = new List<int>(new int[_ElementsPositionsArray.Count]);
                for (int i = 0, size = _ElementsPositionsArray.Count; i < size; i++)
                    permutatedArray[i] = _ElementsPositionsArray[_ElementsPositionsArray[i]] + 1;
                return permutatedArray;
            }

        public void PrintPermutatedArray()
        {
            _PermutatedArray.ForEach(Console.WriteLine);
        }
    }
