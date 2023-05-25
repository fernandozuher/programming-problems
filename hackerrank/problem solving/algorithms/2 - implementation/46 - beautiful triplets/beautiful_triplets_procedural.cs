// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

using System;

public class BeautifulTriplets
{
    public static void Main() {
        List<int> inputLine = _readAnArray();
        int size = inputLine.First();
        int beautifulDifference = inputLine.Last();
        List<int> array = _readAnArray();

        int nBeautifulTriplets = _findBeautifulTriplets(array, beautifulDifference);
        Console.WriteLine(nBeautifulTriplets);
    }

        private static List<int> _readAnArray() {
            List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
            return array;
        }

        private static int _findBeautifulTriplets(List<int> array, int beautifulDifference) {
            int nBeautifulTriplets = 0;

            if (array.Count > 2)
                for (int i = 0; i < array.Count - 2; i++)
                    for (int j = i + 1; j < array.Count - 1; j++) {
                        int firstDifference = array[j] - array[i];

                        if (firstDifference < beautifulDifference)
                            continue;
                        else if (firstDifference > beautifulDifference)
                            break;

                        for (int k = j + 1; k < array.Count; k++) {
                            int secondDifference = array[k] - array[j];

                            if (secondDifference == beautifulDifference)
                                nBeautifulTriplets++;
                            else if (secondDifference > beautifulDifference)
                                break;
                        }
                    }

            return nBeautifulTriplets;
        }
}
