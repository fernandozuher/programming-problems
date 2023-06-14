// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        List<int> inputLine = _readAnArray();
        int size = inputLine.First();
        int beautifulDifference = inputLine.Last();
        List<int> array = _readAnArray();

        BeautifulTriplets obj = new BeautifulTriplets(array, beautifulDifference);
        Console.WriteLine(obj.GetNBeautifulTriplets());
    }

        private static List<int> _readAnArray()
        {
            List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
            return array;
        }
}

    public class BeautifulTriplets
    {
        private List<int> _array;
        private int _beautifulDifference;
        private int _nBeautifulTriplets;

        public BeautifulTriplets(List<int> array, int beautifulDifference)
        {
            _array = array;
            _beautifulDifference = beautifulDifference;
            _findBeautifulTriplets();
        }

            private void _findBeautifulTriplets()
            {
                _nBeautifulTriplets = 0;

                if (_array.Count > 2)
                    for (int i = 0; i < _array.Count - 2; i++)
                        for (int j = i + 1; j < _array.Count - 1; j++)
                        {
                            int firstDifference = _array[j] - _array[i];

                            if (firstDifference < _beautifulDifference)
                                continue;
                            else if (firstDifference > _beautifulDifference)
                                break;

                            for (int k = j + 1; k < _array.Count; k++)
                            {
                                int secondDifference = _array[k] - _array[j];

                                if (secondDifference == _beautifulDifference)
                                    _nBeautifulTriplets++;
                                else if (secondDifference > _beautifulDifference)
                                    break;
                            }
                        }
            }

            public int GetNBeautifulTriplets()
            {
                return _nBeautifulTriplets;
            }
        }
