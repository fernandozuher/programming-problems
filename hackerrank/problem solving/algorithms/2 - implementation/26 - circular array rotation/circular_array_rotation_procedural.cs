// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main(String[] args)
    {
        List<List<int>> input = _readInput();

        input = _reduceInputRotations(input);
        input = _rotateInputArray(input);
        printRotatedArrayElementsAccordingToQueries(input);
    }

        private static List<List<int>> _readInput()
        {
            List<int> line = _readLineAsListInt();
            List<int> arraySize = new List<int>() {line.First()};
            List<int> rotationCount = new List<int>() {line[1]};
            List<int> queriesSize = new List<int>() {line[2]};

            List<int> array = _readLineAsListInt();
            List<int> queries = _readQueries(queriesSize[0]);

            List<List<int>> input = new List<List<int>>();
            input.Add(array);
            input.Add(arraySize);
            input.Add(rotationCount);
            input.Add(queries);
            input.Add(queriesSize);

            return input;
        }

            private static List<int> _readLineAsListInt()
            {
                List<int> numbers = Console.ReadLine().Split().Select(int.Parse).ToList();
                return numbers;
            }

            private static List<int> _readQueries(int size)
            {
                List<int> array = new List<int>(new int[size]);
                for (int i = 0; i < size; i++)
                    array[i] = int.Parse(Console.ReadLine());
                return array;
            }

        private static List<List<int>> _reduceInputRotations(List<List<int>> input)
        {
            int arraySize = input[0].Count;
            int rotationCount = input[2][0];

            if (arraySize > 1)
                rotationCount = rotationCount >= arraySize ? rotationCount % arraySize : rotationCount;
            else
                rotationCount = 0;

            input[2][0] = rotationCount;
            return input;
        }

        private static List<List<int>> _rotateInputArray(List<List<int>> input)
        {
            List<int> array = input[0];
            int arraySize = array.Count;
            int rotationCount = input[2][0];

            List<int> firstHalfArray = array.GetRange(arraySize - rotationCount, rotationCount);
            List<int> secondHalfArray = array.GetRange(0, arraySize - rotationCount);

            List<int> newArray = new List<int>();
            newArray.AddRange(firstHalfArray);
            newArray.AddRange(secondHalfArray);

            input[0] = newArray;
            return input;
        }

        public static void printRotatedArrayElementsAccordingToQueries(List<List<int>> input)
        {
            List<int> array = input[0];
            List<int> queries = input[3];
            queries.ForEach(query => Console.WriteLine(array[query]));
        }
}
