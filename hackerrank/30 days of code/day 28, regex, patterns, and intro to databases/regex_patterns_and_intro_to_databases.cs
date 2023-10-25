// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<string> names = _findNamesWithGmailDomainsEmailsFromStdin(n);
        _sortInPlaceAndPrintNames(names);
    }

        private static List<string> _findNamesWithGmailDomainsEmailsFromStdin(int n)
        {
            List<string> names = new List<string>();

            while (n-- > 0)
            {
                List<string> line = Console.ReadLine().Split().ToList();
                string name = line.First(), emailId = line.Last();

                if (emailId.Contains("@gmail.com"))
                    names.Add(name);
            }

            return names;
        }

        private static void _sortInPlaceAndPrintNames(List<string> names)
        {
            names.Sort();
            foreach (string name in names)
                Console.WriteLine(name);
        }
}
