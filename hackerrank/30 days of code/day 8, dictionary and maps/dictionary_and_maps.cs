// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var phoneBook = new Dictionary<string, string>();

        while (n-- > 0)
        {
            string[] entry = Console.ReadLine().Split(' ');
            phoneBook.Add(entry[0], entry[1]);
        }

        for (string name, phone; (name = Console.ReadLine()) != null;)
            if (phoneBook.TryGetValue(name, out phone))
                Console.WriteLine("{0}={1}", name, phone);
            else
                Console.WriteLine("Not found");
    }
}
