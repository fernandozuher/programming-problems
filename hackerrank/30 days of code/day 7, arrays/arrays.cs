// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

using static System.Console;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(ReadLine());
        List<int> array = ReadLine().Split().Select(int.Parse).ToList();
        for (int i = n - 1; i >= 0; i--)
            Write("{0} ", array[i]);
    }
}
