// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main(String[] args)
    {
        List<List<int>> input = _readInput();
        CircularArrayRotation obj = new CircularArrayRotation(input);
        obj.printRotatedArrayElementsAccordingToQueries();
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
}

    class CircularArrayRotation {
        private List<int> _array;
        private int _arraySize;
        private int _rotationCount;
        private List<int> _queries;
        private int _querySize;

        public CircularArrayRotation(List<List<int>> input)
        {
            _array = input[0];
            _arraySize = input[1][0];
            _rotationCount = input[2][0];
            _queries = input[3];
            _querySize = input[4][0];

            _reduceInputRotations();
            _rotateInputArray();
        }

            private void _reduceInputRotations()
            {
                if (_arraySize > 1)
                    _rotationCount = _rotationCount >= _arraySize ? _rotationCount % _arraySize : _rotationCount;
                else
                    _rotationCount = 0;
            }

            private void _rotateInputArray()
            {
                List<int> firstHalfArray = _array.GetRange(_arraySize - _rotationCount, _rotationCount);
                List<int> secondHalfArray = _array.GetRange(0, _arraySize - _rotationCount);

                List<int> newArray = new List<int>();
                newArray.AddRange(firstHalfArray);
                newArray.AddRange(secondHalfArray);

                _array = newArray;
            }

        public void printRotatedArrayElementsAccordingToQueries()
        {
            _queries.ForEach(query => Console.WriteLine(_array[query]));
        }
    }
