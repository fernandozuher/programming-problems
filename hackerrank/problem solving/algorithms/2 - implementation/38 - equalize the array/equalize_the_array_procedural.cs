// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

using System;

public class EqualizeTheArray
{
    public static void Main()
    {
        int _ = _ReadANumber();
        List<int> array = _ReadAnArray();

        int minimumNumberOfDeletionsRequired  = _EqualizeArray(array);
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

        private static int _EqualizeArray(List<int> array)
        {
            array.Sort();
            int maximumQuantityOfEqualElement = _FindMaximumQuantityOfEqualElement(array);
            int minimumNumberOfDeletionsRequired = array.Count - maximumQuantityOfEqualElement;
            return minimumNumberOfDeletionsRequired;
        }

            private static int _FindMaximumQuantityOfEqualElement(List<int> array)
            {
                int maximumQuantityOfEqualElement = 1;

                for (int i = 1, temporaryQuantityEqualElement = 1, size = array.Count; i < size; i++)
                {
                    if (_AreConsecutiveElementesEqual(array[i - 1], array[i]))
                    {
                        temporaryQuantityEqualElement++;
                        maximumQuantityOfEqualElement = Math.Max(temporaryQuantityEqualElement, maximumQuantityOfEqualElement);
                    }
                    else
                        temporaryQuantityEqualElement = 1;
                }

                return maximumQuantityOfEqualElement;
            }

                private static bool _AreConsecutiveElementesEqual(int element1, int element2)
                {
                    return element1 == element2;
                }
}
