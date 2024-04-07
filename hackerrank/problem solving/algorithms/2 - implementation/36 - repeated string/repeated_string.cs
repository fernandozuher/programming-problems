// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

using System;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        string inputString = Console.ReadLine();
        long nCharacters = long.Parse(Console.ReadLine());
        const char letter = 'a';
        Console.WriteLine(CountInRepeatedString(inputString, letter, nCharacters));
    }

        public static long CountInRepeatedString(string inputString, char letter, long nCharacters)
        {
            long nSubstring;
            long repeatedEntireString = Math.DivRem(nCharacters, inputString.Length, out nSubstring);
            var substring = inputString.Substring(0, Convert.ToInt32(nSubstring));

            long quantity = inputString.Count(x => x == letter);
            quantity *= repeatedEntireString;
            quantity += substring.Count(x => x == letter);

            return quantity;
        }
}
