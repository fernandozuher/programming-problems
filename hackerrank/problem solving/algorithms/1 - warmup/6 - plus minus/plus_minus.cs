// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int n = int.Parse(ReadLine());
        List<int> array = ReadIntArray();
        var (positiveProportion, negativeProportion, zeroProportion) = PlusMinus(array);
        WriteLine("{0:0.000000}", positiveProportion);
        WriteLine("{0:0.000000}", negativeProportion);
        WriteLine("{0:0.000000}", zeroProportion);
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static (double, double, double) PlusMinus(List<int> array)
        {
            int positive = 0;
            int negative = 0;
            int zero = 0;

            foreach (int x in array)
                if (x > 0)
                    ++positive;
                else if (x < 0)
                    ++negative;
                else
                    ++zero;

            int n = array.Count;
            double positiveProportion = (double) positive / n;
            double negativeProportion = (double) negative / n;
            double zeroProportion = (double) zero / n;

            return (positiveProportion, negativeProportion, zeroProportion);
        }
}
