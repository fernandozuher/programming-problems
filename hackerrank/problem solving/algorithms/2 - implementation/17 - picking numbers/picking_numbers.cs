// Source: https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        ReadLineAsListInt();

        List<int> numbers = ReadLineAsListInt();
        numbers.Sort();

        Result result = new Result(numbers);
    }

        private static List<int> ReadLineAsListInt()
        {
            List<int> inputLine = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return inputLine;
        }
}

    class Result
    {
        private List<int> _numbers;
        private int _subarrayBiggestSize;

        public Result(List<int> numbers)
        {
            _numbers = numbers;
            _subarrayBiggestSize = 1;

            _PickingNumbers();
            PrintResult();
        }

            private void _PickingNumbers()
            {
                int firstReferenceNumberIndex = 0;
                int secondReferenceNumberIndex = 0;
                int subarrayCurrentSize = 1;

                for (int i = 1, n = _numbers.Count; i < n; i++) {
                    int difference = _numbers[i] - _numbers[firstReferenceNumberIndex];

                    switch (difference) {
                        case 0:
                            subarrayCurrentSize++;
                            break;

                        case 1:
                            subarrayCurrentSize++;
                            if (_numbers[secondReferenceNumberIndex] != _numbers[i])
                                secondReferenceNumberIndex = i;
                            break;

                        default:
                            _subarrayBiggestSize = _UpdateSubarrayBiggestSize(subarrayCurrentSize);

                            List<int> update = _UpdateFirstReferenceNumberIndexAndSubarrayCurrentSize(i, secondReferenceNumberIndex);

                            firstReferenceNumberIndex = update.First();
                            secondReferenceNumberIndex = i;
                            subarrayCurrentSize = update.Last();
                            break;
                    }
                }

                _subarrayBiggestSize = _UpdateSubarrayBiggestSize(subarrayCurrentSize);
            }

                int _UpdateSubarrayBiggestSize(int subarrayCurrentSize)
                {
                    return Math.Max(subarrayCurrentSize, _subarrayBiggestSize);
                }

                List<int> _UpdateFirstReferenceNumberIndexAndSubarrayCurrentSize(int i, int secondReferenceNumberIndex)
                {
                    int firstReferenceNumberIndex, subarrayCurrentSize;

                    if (_numbers[i] - _numbers[secondReferenceNumberIndex] == 1)
                    {
                        firstReferenceNumberIndex = secondReferenceNumberIndex;
                        subarrayCurrentSize = i - secondReferenceNumberIndex + 1;
                    }
                    else 
                    {
                        firstReferenceNumberIndex = i;
                        subarrayCurrentSize = 1;
                    }

                    List<int> result = new List<int>() {firstReferenceNumberIndex, subarrayCurrentSize};
                    return result;
                }

            public void PrintResult()
            {
                Console.WriteLine(_subarrayBiggestSize);
            }
    }
