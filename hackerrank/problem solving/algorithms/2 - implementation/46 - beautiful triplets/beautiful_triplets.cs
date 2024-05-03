// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    static void Main()
    {
        List<int> list = ReadIntArray();
        int n = list.First();
        int beautifulDifference = list.Last();
        List<int> array = ReadIntArray();
        WriteLine(FindBeautifulTriplets(array, beautifulDifference));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static int FindBeautifulTriplets(List<int> array, int beautifulDifference)
        {
            int nBeautifulTriplets = 0;

            if (array.Count > 2)
                foreach (int i in Enumerable.Range(0, array.Count - 2))
                {
                    foreach (var j in Enumerable.Range(i + 1, array.Count - i - 2))
                    {
                        int firstDifference = array[j] - array[i];

                        if (firstDifference < beautifulDifference)
                            continue;
                        else if (firstDifference > beautifulDifference)
                            break;

                        foreach (int k in Enumerable.Range(j + 1, array.Count - j - 1))
                        {
                            int secondDifference = array[k] - array[j];

                            if (secondDifference == beautifulDifference)
                                ++nBeautifulTriplets;
                            else if (secondDifference > beautifulDifference)
                                break;
                        }
                    }
                }

            return nBeautifulTriplets;
        }
}
