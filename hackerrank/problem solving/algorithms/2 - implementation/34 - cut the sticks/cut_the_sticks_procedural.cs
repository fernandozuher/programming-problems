// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

using System;

public class CutTheSticks
{
    public static void Main()
    {
        int _size = _ReadANumber();
        List<int> array = _ReadAnArray();
        array.Sort();

        List<int> result = _CutTheSticks(array);
        printArray(result);
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

        private static List<int> _CutTheSticks(List<int> array)
        {
            int size = array.Count;
            List<int> remainingSticksOfEachIteration = _InitializeResult(size);

            for (int i = 0; i < size; )
            {
                int shortestStickLength = array[i];

                i = _FindFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, array);
                int currentIterationSize = size - i;
                if (i == size)
                    break;

                remainingSticksOfEachIteration.Add(currentIterationSize);
                _DecreaseSticksLengthsHigherThanCurrentShortestStickLength(i, array, shortestStickLength);
            }

            return remainingSticksOfEachIteration;
        }

            private static List<int> _InitializeResult(int size)
            {
                List<int> remainingSticksOfEachIteration = new List<int> {size};
                return remainingSticksOfEachIteration;
            }

            private static int _FindFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(int index, List<int> array)
            {
                int size = array.Count;
                int shortestStickLength = array[index];
                while (index < size && array[index] == shortestStickLength)
                    index++;
                return index;
            }

            private static void _DecreaseSticksLengthsHigherThanCurrentShortestStickLength(int index, List<int> array, int shortestStickLength)
            {
                array = array.Select(element => element - shortestStickLength).ToList();
            }

        public static void printArray(List<int> array)
        {
            array.ForEach(Console.WriteLine);
        }
}
