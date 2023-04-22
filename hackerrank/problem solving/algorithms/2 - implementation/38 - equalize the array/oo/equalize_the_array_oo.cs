// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int _ = _ReadANumber();
        List<int> array = _ReadAnArray();

        EqualizeTheArray obj = new EqualizeTheArray(array);
        int minimumNumberOfDeletionsRequired  = obj.GetMinimumNumberOfDeletionsRequired();
        Console.WriteLine(minimumNumberOfDeletionsRequired);
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

    public class EqualizeTheArray
    {
        private List<int> _Array;
        private int _MinimumNumberOfDeletionsRequired;

        public EqualizeTheArray(List<int> array)
        {
            array.Sort();
            _Array = array;
            _EqualizeArray();
        }
        
            private void _EqualizeArray()
            {
                int maximumQuantityOfEqualElement = _FindMaximumQuantityOfEqualElement();
                _MinimumNumberOfDeletionsRequired = _Array.Count - maximumQuantityOfEqualElement;
            }

                private int _FindMaximumQuantityOfEqualElement()
                {
                    int maximumQuantityOfEqualElement = 1;

                    for (int i = 1, temporaryQuantityEqualElement = 1, size = _Array.Count; i < size; i++)
                    {
                        if (_AreConsecutiveElementesEqual(_Array[i - 1], _Array[i]))
                        {
                            temporaryQuantityEqualElement++;
                            maximumQuantityOfEqualElement = Math.Max(temporaryQuantityEqualElement, maximumQuantityOfEqualElement);
                        }
                        else
                            temporaryQuantityEqualElement = 1;
                    }

                    return maximumQuantityOfEqualElement;
                }

                    private bool _AreConsecutiveElementesEqual(int element1, int element2)
                    {
                        return element1 == element2;
                    }

        public int GetMinimumNumberOfDeletionsRequired()
        {
            return _MinimumNumberOfDeletionsRequired;
        }
    }
