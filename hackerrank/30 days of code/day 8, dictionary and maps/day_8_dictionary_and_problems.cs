using System;
using System.Collections.Generic;

class Solution {
    static void Main(String[] args) {
        
        var n = int.Parse(Console.ReadLine());
        var phoneBook = new Dictionary<string, string>();

        while (n-- > 0) {
            string[] entry = Console.ReadLine().Split(' ');
            phoneBook.Add(entry[0], entry[1]);
        }

        for (string name, phone; (name = Console.ReadLine()) != null; )
            if (phoneBook.TryGetValue(name, out phone))
                Console.WriteLine("{0}={1}", name, phone);
            else
                Console.WriteLine("Not found");
    }
}
